"""SALSA on the ZCU104 (PYNQ): load a Fenwick tree through SALSA, check the
per-bank store counters, run queries, and check every result.

Put salsa.bit and salsa.hwh (same base name) next to this script, then, as root
with PYNQ's environment loaded:
    sudo -i
    source /etc/profile.d/pynq_venv.sh
    source /etc/profile.d/xrt_setup.sh
    cd /home/xilinx/run
    python3 salsa.py | tee run_log.txt

results.json: SHA-256 of the exact .bit and .hwh that ran (compare with the
build folder's checksums to prove which build produced these results).

Word format (64 bits): [63:62] op (0 query, 1 store), [61:48] seq,
[47:32] key, [31:0] value. Results come back in the same format, with the
prefix sum (query) or the stored value (store) in [31:0].
Loading the overlay resets the design and zeroes the banks.
"""
import sys
import time
import json
import hashlib
import datetime
import numpy as np
from pynq import Overlay, allocate

BIT      = "salsa.bit"     # change if your files are named differently
N_QUERY  = 100_000_000     # total queries; any size: they run in chunks of CHUNK
CHUNK    = 1_000_000       # queries per DMA run (memory stays small whatever N_QUERY is)
SEED     = 7

# AXI-Lite register offsets (salsa.sv)
CTRL, STATUS, RUN_LEN = 0x00, 0x04, 0x08
CYCLES, REQ_COUNT, RES_COUNT, LATENCY = 0x0C, 0x10, 0x14, 0x18
BANK_STORES, ROOT_STORES = 0x40, 0x80
OP_QUERY, OP_STORE = 0, 1


def words(op, keys, values):
    """Pack requests: op | seq | key | value, one uint64 per request."""
    n = len(keys)
    seq = np.arange(n, dtype=np.uint64) & np.uint64(0x3FFF)
    return ((np.uint64(op) << np.uint64(62)) | (seq << np.uint64(48))
            | (keys.astype(np.uint64) << np.uint64(32)) | values.astype(np.uint64))


def run(ol, salsa, dma, req, timeout_s=10.0):
    """Send one run of requests through SALSA and return the results."""
    n = len(req)
    src = allocate(shape=(n,), dtype=np.uint64)
    dst = allocate(shape=(n,), dtype=np.uint64)
    src[:] = req
    dst[:] = 0
    salsa.write(RUN_LEN, n)            # tlast goes on result number n
    salsa.write(CTRL, 1)               # start: clears the run counters
    dma.recvchannel.transfer(dst)      # always start receiving first
    dma.sendchannel.transfer(src)
    t0 = time.time()
    while not (dma.recvchannel.idle and dma.sendchannel.idle):
        if time.time() - t0 > timeout_s:
            print(f"TIMEOUT: status={salsa.read(STATUS):#x} req={salsa.read(REQ_COUNT)} "
                  f"res={salsa.read(RES_COUNT)} of {n}")
            sys.exit(1)
    dma.sendchannel.wait()
    dma.recvchannel.wait()
    dst.invalidate()
    out = np.array(dst, copy=True)
    src.freebuffer(); dst.freebuffer()
    if not salsa.read(STATUS) & 1:
        print("WARNING: DONE bit not set after the run")
    return out


def counters(salsa, n):
    cyc = salsa.read(CYCLES)
    return dict(cycles=cyc, req=salsa.read(REQ_COUNT), res=salsa.read(RES_COUNT),
                latency=salsa.read(LATENCY), per_req=cyc / n)


def sha256(path):
    try:
        with open(path, "rb") as f:
            return hashlib.sha256(f.read()).hexdigest()
    except OSError:
        return None


def main():
    results = dict(date=datetime.datetime.now().isoformat(timespec="seconds"),
                   bitstream=BIT, bit_sha256=sha256(BIT),
                   hwh_sha256=sha256(BIT.rsplit(".", 1)[0] + ".hwh"),
                   n_query=N_QUERY, seed=SEED)
    ol = Overlay(BIT)                                   # programs the PL; banks start at zero
    print("IP blocks:", list(ol.ip_dict.keys()))
    name = next((k for k in ol.ip_dict if "salsa" in k), None)
    if name is None:
        sys.exit("No SALSA block in this overlay: is this the SALSA bitstream?")
    salsa, dma = getattr(ol, name), ol.axi_dma_0
    try:
        from pynq import Clocks
        mhz = Clocks.fclk0_mhz
    except Exception:
        mhz = None
    print(f"PL clock: {mhz:.2f} MHz" if mhz else "PL clock: unknown")
    results["ip_blocks"] = list(ol.ip_dict.keys())
    results["pl_clock_mhz"] = mhz
    ok = True

    # ---- data: raw values, the Fenwick tree, and the golden prefix sums
    rng = np.random.default_rng(SEED)
    a = np.zeros(65536, dtype=np.uint64)
    a[1:] = rng.integers(0, 1000, size=65535, dtype=np.uint64)
    prefix = (np.cumsum(a) & np.uint64(0xFFFFFFFF)).astype(np.uint64)
    tree = a.copy()
    for i in range(1, 65536):
        j = i + (i & -i)
        if j < 65536:
            tree[j] += tree[i]
    tree &= np.uint64(0xFFFFFFFF)

    # ---- 1. load: 65,535 stores, SALSA places every value
    keys = np.arange(1, 65536, dtype=np.uint64)
    req = words(OP_STORE, keys, tree[1:])
    res = run(ol, salsa, dma, req)
    bad = np.flatnonzero(res != req)          # a store echoes its own word
    print(f"load: {len(req):,} stores, {len(bad)} wrong echoes")
    ok &= len(bad) == 0
    results["stores"] = len(req)
    results["store_echo_errors"] = int(len(bad))

    # ---- 2. exact balance, read from the hardware counters
    banks = [salsa.read(BANK_STORES + 4 * b) for b in range(16)]
    roots = salsa.read(ROOT_STORES)
    print("stores per bank:", banks, " roots:", roots)
    balanced = all(v == 4095 for v in banks) and roots == 15
    print("balance:", "every bank holds exactly 4,095 nodes" if balanced else "NOT balanced")
    ok &= balanced
    results["bank_stores"] = banks
    results["root_stores"] = roots
    results["balanced"] = balanced

    # ---- 3. queries, in chunks: every result must equal the prefix sum from the raw data
    special = np.array([0, 1, 4095, 4096, 4097, 32768, 56086, 65535], dtype=np.uint64)
    n_chunks = (N_QUERY + CHUNK - 1) // CHUNK
    src = allocate(shape=(CHUNK,), dtype=np.uint64)          # two buffers, reused for every chunk
    dst = allocate(shape=(CHUNK,), dtype=np.uint64)
    errors = req_tot = res_tot = cyc_tot = done = 0
    lat = None
    wall = 0.0
    first_bad = None
    t_start = time.time()
    print(f"queries: {N_QUERY:,} in {n_chunks:,} chunk(s) of up to {CHUNK:,}")
    for ci in range(n_chunks):
        m = min(CHUNK, N_QUERY - done)
        qkeys = rng.integers(0, 65536, size=m, dtype=np.uint64)
        if ci == 0:
            qkeys[:len(special)] = special
        req = words(OP_QUERY, qkeys, np.zeros(m, dtype=np.uint64))
        s_buf, d_buf = (src, dst) if m == CHUNK else (allocate(shape=(m,), dtype=np.uint64),
                                                      allocate(shape=(m,), dtype=np.uint64))
        s_buf[:] = req
        d_buf[:] = 0
        salsa.write(RUN_LEN, m)
        salsa.write(CTRL, 1)
        t0 = time.perf_counter()
        dma.recvchannel.transfer(d_buf)
        dma.sendchannel.transfer(s_buf)
        dma.sendchannel.wait()
        dma.recvchannel.wait()
        wall += time.perf_counter() - t0
        d_buf.invalidate()
        res = np.array(d_buf, copy=True)
        if m != CHUNK:
            s_buf.freebuffer(); d_buf.freebuffer()
        bad = np.flatnonzero(res != words(OP_QUERY, qkeys, prefix[qkeys]))
        if len(bad) and first_bad is None:
            i0 = bad[0]
            first_bad = (ci, int(qkeys[i0]), int(res[i0]) & 0xFFFFFFFF, int(prefix[qkeys[i0]]))
        c = counters(salsa, m)
        errors += len(bad); req_tot += c["req"]; res_tot += c["res"]; cyc_tot += c["cycles"]
        lat = c["latency"] if lat is None else lat
        done += m
        if n_chunks > 1 and ((ci + 1) % 10 == 0 or len(bad)):
            el = time.time() - t_start
            print(f"  {done:,} queries, {errors} wrong, {el:.0f} s elapsed, "
                  f"about {el / (ci + 1) * (n_chunks - ci - 1):.0f} s left")
    src.freebuffer(); dst.freebuffer()
    print(f"queries: {N_QUERY:,}, {errors} wrong")
    if first_bad:
        print(f"  first wrong: chunk {first_bad[0]}, key {first_bad[1]}: got {first_bad[2]}, want {first_bad[3]}")
    ok &= errors == 0 and req_tot == N_QUERY and res_tot == N_QUERY
    c = dict(cycles=cyc_tot, req=req_tot, res=res_tot, latency=lat, per_req=cyc_tot / N_QUERY)
    results["query_errors"] = int(errors)
    results["counters"] = c
    results["chunks"] = n_chunks
    results["wall_s"] = wall

    # ---- 4. hardware counters, totalled over all chunks
    print(f"cycles: {c['cycles']:,} for {N_QUERY:,} queries = {c['per_req']:.4f} cycles/query")
    print(f"latency (first request to first result): {c['latency']} cycles"
          + (f" = {c['latency'] * 1e3 / mhz:.1f} ns" if mhz else ""))
    if mhz:
        hw_s = c["cycles"] / (mhz * 1e6)
        print(f"throughput: {N_QUERY / hw_s / 1e6:.1f} million queries/s (hardware)")
        print(f"time: hardware {hw_s:.3f} s (cycle counter), wall {wall:.3f} s (DMA start to finish, "
              f"{N_QUERY / wall / 1e6:.1f} million queries/s end to end)")
        results["latency_ns"] = c["latency"] * 1e3 / mhz
        results["throughput_mqps"] = N_QUERY / hw_s / 1e6
        results["hardware_s"] = hw_s

    # ---- 5. power, while idle (run a query loop separately to measure under load)
    try:
        from pynq import get_rails
        for nm, rail in get_rails().items():
            if nm in ("12V", "INT") and rail.power is not None:
                print(f"  power {nm}: {rail.power.value:.3f} W")
                results[f"power_idle_{nm}_W"] = rail.power.value
    except Exception as e:
        print("power rails not readable:", e)

    results["pass"] = bool(ok)
    with open("results.json", "w") as f:
        json.dump(results, f, indent=1)
    print("PASS" if ok else "FAIL")
    print("results written to results.json")


if __name__ == "__main__":
    main()
