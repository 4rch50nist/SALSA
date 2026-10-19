"""SALSA on the ZCU104
Writes results.json: every measured number, the date, and the SHA-256 of the exact
.bit and .hwh that ran.

Word format (64 bits): [63:62] op (0 query, 2 update), [61:48] seq, [47:32] key,
[31:0] delta / result. A query returns the prefix sum in [31:0]; an update returns its
own word (echo). There is no store: the tree is built by updates, which is correct only
from the zero state, so this script always loads (reprograms) the overlay first.
Arithmetic is modulo 2^32 throughout, as in the hardware.

Sizes can be overridden for a quick run: SALSA_N_QUERY=1000000 SALSA_N_MIXED=1000000 python3 salsa.py
(salsa_stage1.py drives Stage 1 bitstreams, which build the tree with stores.)
"""
import os
import sys
import time
import json
import hashlib
import datetime
import numpy as np
from pynq import Overlay, allocate

BIT       = "salsa.bit"                         
N_QUERY   = int(os.environ.get("SALSA_N_QUERY", 100_000_000))      # phase 3: queries
N_MIXED   = int(os.environ.get("SALSA_N_MIXED", 10_000_000))       # phase 4: updates + queries
CHUNK     = 1_000_000                                              # requests per DMA run
UPD_FRAC  = 0.5                                                    # phase 4: share of updates
SPREAD    = 64                                                     # phase 4: keys within +-SPREAD of the price
SEED      = 7
ITCH_FILES = ["itch_ops.bin.gz", "/boot/itch_ops.bin.gz",          # made by itch_ops.cpp
              "itch_ops.bin", "/boot/itch_ops.bin"]

# AXI-Lite register offsets (salsa.sv)
CTRL, STATUS, RUN_LEN = 0x00, 0x04, 0x08
CYCLES, REQ_COUNT, RES_COUNT, LATENCY = 0x0C, 0x10, 0x14, 0x18
BANK_OWN, ROOT_OWN = 0x40, 0x80          # updates whose own node is in bank b / is a root
OP_QUERY, OP_UPDATE = 0, 2
MASK = np.uint64(0xFFFFFFFF)
N = 65536


def words(ops, keys, values):
    """Pack requests: op | seq | key | value, one uint64 per request (ops may be an array)."""
    n = len(keys)
    seq = np.arange(n, dtype=np.uint64) & np.uint64(0x3FFF)
    ops = np.broadcast_to(np.asarray(ops, dtype=np.uint64), (n,))
    return ((ops << np.uint64(62)) | (seq << np.uint64(48))
            | (np.asarray(keys).astype(np.uint64) << np.uint64(32)) | (np.asarray(values).astype(np.uint64) & MASK))


def sha256(path):
    try:
        with open(path, "rb") as f:
            return hashlib.sha256(f.read()).hexdigest()
    except OSError:
        return None


class Board:
    """The overlay, SALSA's registers, and two reusable DMA buffers."""

    def __init__(self, bit):
        self.ol = Overlay(bit)                          # programs the PL: block RAMs start at zero
        name = next((k for k in self.ol.ip_dict if "salsa" in k), None)
        if name is None:
            sys.exit("No SALSA block in this overlay: is this the SALSA bitstream?")
        self.salsa, self.dma = getattr(self.ol, name), self.ol.axi_dma_0
        self.src = allocate(shape=(CHUNK,), dtype=np.uint64)
        self.dst = allocate(shape=(CHUNK,), dtype=np.uint64)
        self.wall = 0.0

    def run(self, req, timeout_s=10.0):
        """Send one run (at most CHUNK requests) and return results plus the run's counters."""
        n = len(req)
        s_buf, d_buf = ((self.src, self.dst) if n == CHUNK else
                        (allocate(shape=(n,), dtype=np.uint64), allocate(shape=(n,), dtype=np.uint64)))
        s_buf[:] = req
        d_buf[:] = 0
        self.salsa.write(RUN_LEN, n)                    # tlast goes on result number n
        self.salsa.write(CTRL, 1)                       # start: clears the run counters
        t0 = time.perf_counter()
        self.dma.recvchannel.transfer(d_buf)            # always start receiving first
        self.dma.sendchannel.transfer(s_buf)
        while not (self.dma.recvchannel.idle and self.dma.sendchannel.idle):
            if time.perf_counter() - t0 > timeout_s:
                print(f"TIMEOUT: status={self.salsa.read(STATUS):#x} req={self.salsa.read(REQ_COUNT)} "
                      f"res={self.salsa.read(RES_COUNT)} of {n}")
                sys.exit(1)
        self.dma.sendchannel.wait()
        self.dma.recvchannel.wait()
        self.wall += time.perf_counter() - t0
        d_buf.invalidate()
        out = np.array(d_buf, copy=True)
        if n != CHUNK:
            s_buf.freebuffer(); d_buf.freebuffer()
        if not self.salsa.read(STATUS) & 1:
            print("WARNING: DONE bit not set after the run")
        c = dict(cycles=self.salsa.read(CYCLES), req=self.salsa.read(REQ_COUNT),
                 res=self.salsa.read(RES_COUNT), latency=self.salsa.read(LATENCY))
        return out, c

    def close(self):
        self.src.freebuffer(); self.dst.freebuffer()


def mixed_stream(rng, n, price, upd_frac=UPD_FRAC, spread=SPREAD):
    """Order-book-like traffic: keys within +-spread of a price that drifts; updates add or remove
    quantity (negative deltas wrap modulo 2^32, as in the hardware). Returns ops, keys, deltas, price."""
    steps = rng.integers(-3, 4, size=n)
    prices = np.clip(price + np.cumsum(steps), 1, N - 1)
    keys = np.clip(prices + rng.integers(-spread, spread + 1, size=n), 1, N - 1).astype(np.int64)
    is_upd = rng.random(n) < upd_frac
    mag = rng.integers(1, 1000, size=n, dtype=np.int64)
    sign = np.where(rng.random(n) < 0.3, -1, 1)
    deltas = np.where(is_upd, (sign * mag) % (1 << 32), 0).astype(np.uint64)
    ops = np.where(is_upd, OP_UPDATE, OP_QUERY).astype(np.uint64)
    return ops, keys, deltas, int(prices[-1])


def expected_mixed(raw, ops, keys, deltas, block=256):
    """Expected results for a mixed run, in order; updates `raw` (the raw values) in place.
    Within a block, a query's answer = prefix at the block start + earlier in-block updates
    at keys <= its key (a small matrix product); exact modulo 2^32. Only the chunk's key range
    [lo, hi] is summed: everything below lo is a fixed base, since no key in the chunk is below it."""
    n = len(keys)
    exp = np.zeros(n, dtype=np.uint64)
    lo, hi = int(keys.min()), int(keys.max())
    base = raw[:lo].sum(dtype=np.uint64) & MASK
    for s in range(0, n, block):
        e = min(s + block, n)
        window = (base + np.cumsum(raw[lo:hi + 1], dtype=np.uint64)) & MASK    # prefix[lo..hi]
        k, d, o = keys[s:e], deltas[s:e], ops[s:e]
        is_u = o == OP_UPDATE
        t = np.arange(e - s)
        # dominance: update u counts for query q if u comes earlier and key_u <= key_q
        dom = (t[None, :] < t[:, None]) & (k[None, :] <= k[:, None]) & is_u[None, :]
        add = (dom.astype(np.uint64) * d[None, :]).sum(axis=1, dtype=np.uint64) & MASK
        exp[s:e] = np.where(is_u, d, (window[k - lo] + add) & MASK)
        np.add.at(raw, k[is_u], d[is_u])
        raw &= MASK
    return exp


def read_ops_bin(path):
    """itch_ops.bin or itch_ops.bin.gz from itch_ops.cpp: "SALSAOPS" | u32 version | u64 n | u32 meta_len | meta text |
    u8 ops[n] | u16 keys[n] | u32 vals[n] | u32 expected[n] | u32 final_prefix[65536] (little-endian)."""
    import gzip
    opener = gzip.open if path.endswith(".gz") else open
    with opener(path, "rb") as f:
        data = f.read()                                   # ~11 bytes per operation, uncompressed
    if data[:8] != b"SALSAOPS":
        sys.exit(f"{path}: not an itch_ops.bin file")
    version = int(np.frombuffer(data, "<u4", 1, 8)[0])
    n = int(np.frombuffer(data, "<u8", 1, 12)[0])
    meta_len = int(np.frombuffer(data, "<u4", 1, 20)[0])
    off = 24
    meta = dict(line.split("=", 1) for line in data[off:off + meta_len].decode().splitlines() if "=" in line)
    off += meta_len
    arr = {}
    for name, dt, count in (("ops", "<u1", n), ("keys", "<u2", n), ("vals", "<u4", n),
                            ("expected", "<u4", n), ("final_prefix", "<u4", N)):
        size = np.dtype(dt).itemsize * count
        arr[name] = np.frombuffer(data, dt, count, off) if off + size <= len(data) else np.zeros(0, dt)
        off += size
    if version != 1 or any(len(arr[k]) != n for k in ("ops", "keys", "vals", "expected")) or len(arr["final_prefix"]) != N:
        sys.exit(f"{path}: truncated or unknown version {version}")
    meta["version"] = version
    return meta, arr


def main():
    results = dict(date=datetime.datetime.now().isoformat(timespec="seconds"),
                   bitstream=BIT, bit_sha256=sha256(BIT),
                   hwh_sha256=sha256(BIT.rsplit(".", 1)[0] + ".hwh"),
                   n_query=N_QUERY, n_mixed=N_MIXED, seed=SEED, design="stage4: write lag 2, queries + updates")
    bd = Board(BIT)
    salsa = bd.salsa
    print("IP blocks:", list(bd.ol.ip_dict.keys()))
    try:
        from pynq import Clocks
        mhz = Clocks.fclk0_mhz
    except Exception:
        mhz = None
    print(f"PL clock: {mhz:.2f} MHz" if mhz else "PL clock: unknown")
    results["pl_clock_mhz"] = mhz
    ok = True
    rng = np.random.default_rng(SEED)

    # ---- data: the raw values a[i] (the tree is SALSA's business)
    raw = np.zeros(N, dtype=np.uint64)
    raw[1:] = rng.integers(0, 1000, size=N - 1, dtype=np.uint64)

    # ---- 1. build the tree by updates from zero
    keys = np.arange(1, N, dtype=np.int64)
    req = words(OP_UPDATE, keys, raw[1:])
    res, c = bd.run(req)
    bad = int(np.count_nonzero(res != req))               # an update echoes its own word
    print(f"build: {len(req):,} updates in {c['cycles']:,} cycles, {bad} wrong echoes")
    ok &= bad == 0
    results["build"] = dict(updates=len(req), cycles=c["cycles"], echo_errors=bad)

    # ---- 2. exact balance, read from the hardware counters
    banks = [salsa.read(BANK_OWN + 4 * b) for b in range(16)]
    roots = salsa.read(ROOT_OWN)
    balanced = all(v == 4095 for v in banks) and roots == 15
    print("own nodes per bank:", banks, " roots:", roots)
    print("balance:", "every bank holds exactly 4,095 nodes" if balanced else "NOT balanced")
    ok &= balanced
    results.update(bank_own=banks, root_own=roots, balanced=balanced)

    # ---- 3. queries, in chunks: every result must equal the prefix sum from the raw data
    prefix = np.cumsum(raw, dtype=np.uint64) & MASK
    special = np.array([0, 1, 4095, 4096, 4097, 32768, 56086, 65535], dtype=np.int64)
    errors = cyc = done = 0
    lat = None
    t_start = time.time()
    n_chunks = (N_QUERY + CHUNK - 1) // CHUNK
    print(f"queries: {N_QUERY:,} in {n_chunks:,} chunk(s)")
    for ci in range(n_chunks):
        m = min(CHUNK, N_QUERY - done)
        qk = rng.integers(0, N, size=m, dtype=np.int64)
        if ci == 0:
            qk[:len(special)] = special
        res, c = bd.run(words(OP_QUERY, qk, np.zeros(m, dtype=np.uint64)))
        nb = int(np.count_nonzero(res != words(OP_QUERY, qk, prefix[qk])))
        errors += nb; cyc += c["cycles"]; done += m
        lat = c["latency"] if lat is None else lat
        ok &= c["req"] == m and c["res"] == m
        if n_chunks > 1 and ((ci + 1) % 10 == 0 or nb):
            el = time.time() - t_start
            print(f"  {done:,} queries, {errors} wrong, {el:.0f} s elapsed")
    print(f"queries: {N_QUERY:,}, {errors} wrong, {cyc / N_QUERY:.4f} cycles/query, latency {lat} cycles"
          + (f" = {lat * 1e3 / mhz:.1f} ns" if mhz else ""))
    ok &= errors == 0
    results["queries"] = dict(n=N_QUERY, errors=errors, cycles=cyc, per_req=cyc / N_QUERY, latency=lat)
    if mhz:
        results["queries"]["latency_ns"] = lat * 1e3 / mhz
        results["queries"]["throughput_mqps"] = N_QUERY / (cyc / (mhz * 1e6)) / 1e6

    # ---- 4. mixed updates and queries (order-book-like), every result checked
    errors = cyc = done = n_upd = 0
    price = 30000
    t_start = time.time()
    n_chunks = (N_MIXED + CHUNK - 1) // CHUNK
    print(f"mixed: {N_MIXED:,} updates and queries ({UPD_FRAC:.0%} updates, keys within +-{SPREAD} "
          f"of a drifting price) in {n_chunks:,} chunk(s)")
    first_bad = None
    for ci in range(n_chunks):
        m = min(CHUNK, N_MIXED - done)
        ops, mk, md, price = mixed_stream(rng, m, price)
        req = words(ops, mk, md)
        res, c = bd.run(req)
        exp = expected_mixed(raw, ops, mk, md)            # also advances `raw`
        want = words(ops, mk, exp)
        bad = np.flatnonzero(res != want)
        if len(bad) and first_bad is None:
            i0 = bad[0]
            first_bad = (ci, int(ops[i0]), int(mk[i0]), int(res[i0]) & 0xFFFFFFFF, int(exp[i0]))
        errors += len(bad); cyc += c["cycles"]; done += m; n_upd += int(np.count_nonzero(ops == OP_UPDATE))
        ok &= c["req"] == m and c["res"] == m
        if n_chunks > 1 and ((ci + 1) % 5 == 0 or len(bad)):
            print(f"  {done:,} operations, {errors} wrong, {time.time() - t_start:.0f} s elapsed")
    print(f"mixed: {N_MIXED:,} operations ({n_upd:,} updates), {errors} wrong, "
          f"{cyc / max(N_MIXED, 1):.4f} cycles/operation")
    if first_bad:
        print(f"  first wrong: chunk {first_bad[0]}, op {first_bad[1]}, key {first_bad[2]}: "
              f"got {first_bad[3]}, want {first_bad[4]}")
    ok &= errors == 0
    results["mixed"] = dict(n=N_MIXED, updates=n_upd, errors=int(errors), cycles=cyc,
                            per_op=cyc / max(N_MIXED, 1), spread=SPREAD, upd_frac=UPD_FRAC)

    # ---- 5. final sweep: every prefix sum after all the updates
    prefix = np.cumsum(raw, dtype=np.uint64) & MASK
    sk = np.arange(1, N, dtype=np.int64)
    res, c = bd.run(words(OP_QUERY, sk, np.zeros(N - 1, dtype=np.uint64)))
    nb = int(np.count_nonzero(res != words(OP_QUERY, sk, prefix[sk])))
    print(f"final sweep: all {N - 1:,} prefix sums, {nb} wrong")
    ok &= nb == 0
    results["final_sweep_errors"] = nb

    # ---- 6. NASDAQ ITCH: real order flow, from an empty book
    itch_path = next((f for f in ITCH_FILES if os.path.exists(f)), None)
    if itch_path is None:
        print("itch: itch_ops.bin.gz not found, skipped")
        results["itch"] = None
    else:
        meta, z = read_ops_bin(itch_path)
        # compact arrays (uint8 / uint16 / uint32); widened one chunk at a time to save memory
        i_ops, i_keys, i_vals, i_exp = z["ops"], z["keys"], z["vals"], z["expected"]
        i_final = z["final_prefix"].astype(np.uint64)
        n_ops = len(i_ops)
        print(f"itch: {n_ops:,} operations ({int(meta['kept_events']):,} order-book events, {int(meta['queries']):,} "
              f"queries) for {meta['symbols']}, until {meta['until']}; {meta['anchors_live']} anchors live")
        bd.close()
        bd = Board(BIT)                                   # reprogram: block RAMs and roots back to zero
        salsa = bd.salsa
        errors = cyc = 0
        first_bad = None
        for s0 in range(0, n_ops, CHUNK):
            sl = slice(s0, min(s0 + CHUNK, n_ops))
            co, ck = i_ops[sl].astype(np.uint64), i_keys[sl].astype(np.int64)
            res, c = bd.run(words(co, ck, i_vals[sl].astype(np.uint64)))
            bad = np.flatnonzero(res != words(co, ck, i_exp[sl].astype(np.uint64)))
            if len(bad) and first_bad is None:
                j = s0 + bad[0]
                first_bad = (int(j), int(i_ops[j]), int(i_keys[j]), int(res[bad[0]]) & 0xFFFFFFFF, int(i_exp[j]))
            errors += len(bad); cyc += c["cycles"]
            ok &= c["req"] == sl.stop - sl.start and c["res"] == sl.stop - sl.start
        sk = np.arange(1, N, dtype=np.int64)
        res, c = bd.run(words(OP_QUERY, sk, np.zeros(N - 1, dtype=np.uint64)))
        sweep_bad = int(np.count_nonzero(res != words(OP_QUERY, sk, i_final[sk])))
        print(f"itch: {errors} wrong of {n_ops:,}, {cyc / n_ops:.4f} cycles/operation; "
              f"final sweep {sweep_bad} wrong of {N - 1:,}")
        if first_bad:
            print(f"  first wrong: operation {first_bad[0]}, op {first_bad[1]}, key {first_bad[2]}: "
                  f"got {first_bad[3]}, want {first_bad[4]}")
        ok &= errors == 0 and sweep_bad == 0
        results["itch"] = dict(meta=meta, operations=n_ops, errors=int(errors), cycles=cyc,
                               per_op=cyc / n_ops, final_sweep_errors=sweep_bad)

    # ---- power, while idle
    try:
        from pynq import get_rails
        for nm, rail in get_rails().items():
            if nm in ("12V", "INT") and rail.power is not None:
                print(f"  power {nm}: {rail.power.value:.3f} W")
                results[f"power_idle_{nm}_W"] = rail.power.value
    except Exception as e:
        print("power rails not readable:", e)

    bd.close()
    results["wall_s"] = bd.wall
    results["pass"] = bool(ok)
    with open("results.json", "w") as f:
        json.dump(results, f, indent=1)
    print("PASS" if ok else "FAIL")
    print("results written to results.json")


if __name__ == "__main__":
    main()
