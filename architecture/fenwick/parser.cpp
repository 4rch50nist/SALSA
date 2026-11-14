// itch_ops.cpp: NASDAQ TotalView-ITCH 5.0 -> SALSA test stream (itch_ops.bin),
// in one pass.
//
// Build:  g++ -O2 -std=c++17 -o itch_ops itch_ops.cpp -lz
// Run:    ./itch_ops                                  (reads
// ./data/01302019.NASDAQ_ITCH50.gz,
//                                                      writes
//                                                      ./data/itch_ops.bin.gz)
//         ./itch_ops [input.gz] [output.bin] [--until HH:MM] [--max-events N]
//                    [--query-every N] [--symbols
//                    QQQ,RDS.B,SAP,RIO,ASML,RDS.A,AAPL,BBL]
// Then copy itch_ops.bin to the SD card's boot partition, next to salsa.py.
//
// Method (stated once, applied uniformly):
//  * Order-book replay for the symbols (default: the eight busiest of 30 Jan
//  2019, as in the earlier
//    experiments). A/F add shares; E/C (executed) and X (cancelled) REDUCE the
//    order and remove those shares at the ORDER's price; D removes what is
//    still resting; U = delete + add (new ref, price).
//  * Layout, 16-bit instance: symbol s has anchors 2s (bids) and 2s+1 (asks);
//  each ladder is 4,095
//    one-cent levels centred on that ladder's median event price:
//        lo = floor((price - median) / 100) + 2048, kept if 1 <= lo <= 4095;
//        key = anchor * 4096 + lo
//    An order outside the window is dropped with all its changes (same price):
//    the book stays consistent.
//  * Queries: ITCH has none. After every kept event (or every --query-every
//  events), the prefix sum at
//    that event's key is queried: the depth question, landing where the book
//    just changed.
//  * The book starts empty at the start of the file, as SALSA's block RAMs do
//  after the overlay loads.
//  * Expected results from a plain Fenwick tree, exact modulo 2^32: an update
//  echoes its delta, a query
//    returns the prefix sum. Also the final prefix sums, for the board's final
//    sweep.
//
// Output ending in .gz is gzip-compressed (the default: the SD card's boot
// partition is small); salsa.py reads either form. The uncompressed content,
// itch_ops.bin (little-endian): "SALSAOPS" | u32 version (1) | u64 n_ops | u32
// meta_len | meta (text,
//   key=value lines) | u8 ops[n] (0 query, 2 update) | u16 keys[n] | u32
//   vals[n] | u32 expected[n] | u32 final_prefix[65536]

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <zlib.h>

static constexpr std::array<std::uint8_t, 256> make_msg_len() {
  std::array<std::uint8_t, 256> t{};
  t['S'] = 12;
  t['R'] = 39;
  t['H'] = 25;
  t['Y'] = 20;
  t['L'] = 26;
  t['V'] = 35;
  t['W'] = 12;
  t['K'] = 28;
  t['J'] = 35;
  t['h'] = 21;
  t['A'] = 36;
  t['F'] = 40;
  t['E'] = 31;
  t['C'] = 36;
  t['X'] = 23;
  t['D'] = 19;
  t['U'] = 35;
  t['P'] = 44;
  t['Q'] = 40;
  t['B'] = 19;
  t['I'] = 50;
  t['N'] = 20;
  t['O'] = 48;
  return t;
}
static constexpr auto MSG_LEN = make_msg_len();

static inline std::uint32_t rd32(const unsigned char *p) {
  return (std::uint32_t(p[0]) << 24) | (std::uint32_t(p[1]) << 16) |
         (std::uint32_t(p[2]) << 8) | p[3];
}
static inline std::uint64_t rd64(const unsigned char *p) {
  return (std::uint64_t(rd32(p)) << 32) | rd32(p + 4);
}
static inline std::uint64_t hash_u64(std::uint64_t x) {
  x ^= x >> 30;
  x *= 0xbf58476d1ce4e5b9ULL;
  x ^= x >> 27;
  x *= 0x94d049bb133111ebULL;
  x ^= x >> 31;
  return x;
}

// ---- open-addressed order table (as in the parser), compact orders
struct Order {
  std::uint64_t ref;
  std::uint32_t price;
  std::uint32_t shares;
  std::int8_t slot;
  std::int8_t side;
};
class OrderMap {
  struct Slot {
    Order o;
    std::uint8_t state;
  }; // 0 empty, 1 occupied, 2 tombstone
  std::vector<Slot> t;
  std::size_t used = 0, occ = 0;
  void init(std::size_t cap) {
    std::size_t p = 1;
    while (p < cap)
      p <<= 1;
    t.assign(p, Slot{});
    used = occ = 0;
  }
  void rehash(std::size_t cap) {
    std::vector<Slot> old;
    old.swap(t);
    init(cap);
    for (auto &s : old)
      if (s.state == 1)
        put_new(s.o);
  }
  void put_new(const Order &o) {
    std::size_t m = t.size() - 1, i = hash_u64(o.ref) & m;
    while (t[i].state == 1)
      i = (i + 1) & m;
    t[i].o = o;
    t[i].state = 1;
    ++used;
    ++occ;
  }

public:
  OrderMap() { init(1u << 20); }
  Order *find(std::uint64_t ref) {
    std::size_t m = t.size() - 1, i = hash_u64(ref) & m;
    for (;; i = (i + 1) & m) {
      if (t[i].state == 0)
        return nullptr;
      if (t[i].state == 1 && t[i].o.ref == ref)
        return &t[i].o;
    }
  }
  void put(const Order &o) {
    if (double(used + 1) / double(t.size()) > 0.70)
      rehash(t.size() * 2);
    std::size_t m = t.size() - 1, i = hash_u64(o.ref) & m, tomb = t.size();
    for (;; i = (i + 1) & m) {
      if (t[i].state == 0) {
        if (tomb != t.size())
          i = tomb;
        else
          ++used;
        t[i].o = o;
        t[i].state = 1;
        ++occ;
        return;
      }
      if (t[i].state == 2) {
        if (tomb == t.size())
          tomb = i;
      } else if (t[i].o.ref == o.ref) {
        t[i].o = o;
        return;
      }
    }
  }
  bool erase(std::uint64_t ref, Order *out = nullptr) {
    std::size_t m = t.size() - 1, i = hash_u64(ref) & m;
    for (;; i = (i + 1) & m) {
      if (t[i].state == 0)
        return false;
      if (t[i].state == 1 && t[i].o.ref == ref) {
        if (out)
          *out = t[i].o;
        t[i].state = 2;
        --occ;
        return true;
      }
    }
  }
  std::size_t size() const { return occ; }
};

struct Event {
  std::uint32_t price;
  std::int32_t delta;
  std::int8_t anchor;
};

int main(int argc, char **argv) {
  // positional arguments are optional: input, then output (defaults in ./data/)
  std::string in = "./data/01302019.NASDAQ_ITCH50.gz",
              out = "./data/itch_ops.bin.gz";
  int first_opt = 1;
  if (first_opt < argc && std::string(argv[first_opt]).rfind("--", 0) != 0)
    in = argv[first_opt++];
  if (first_opt < argc && std::string(argv[first_opt]).rfind("--", 0) != 0)
    out = argv[first_opt++];
  std::string symbols_arg = "QQQ,RDS.B,SAP,RIO,ASML,RDS.A,AAPL,BBL", until_arg;
  std::uint64_t max_events = 0, query_every = 1, until_ns = 0;
  for (int i = first_opt; i + 1 < argc; i += 2) {
    std::string k = argv[i], v = argv[i + 1];
    if (k == "--until") {
      until_arg = v;
      until_ns =
          (std::stoull(v.substr(0, 2)) * 60 + std::stoull(v.substr(3, 2))) *
          60ULL * 1000000000ULL;
    } else if (k == "--max-events")
      max_events = std::stoull(v);
    else if (k == "--query-every")
      query_every = std::max<std::uint64_t>(1, std::stoull(v));
    else if (k == "--symbols")
      symbols_arg = v;
    else {
      std::cerr << "unknown option " << k << "\n";
      return 1;
    }
  }
  std::vector<std::string> symbols;
  {
    std::stringstream ss(symbols_arg);
    std::string s;
    while (std::getline(ss, s, ','))
      if (!s.empty())
        symbols.push_back(s);
  }
  if (symbols.empty() || symbols.size() > 8) {
    std::cerr << "1 to 8 symbols (16 anchors, both sides)\n";
    return 1;
  }

  // ---- pass over the file: order-book replay, events for the symbols
  gzFile f = gzopen(in.c_str(), "rb");
  if (!f) {
    std::cerr << "cannot open " << in
              << "\nusage: itch_ops [input.gz] [output.bin] [--until HH:MM] "
                 "[--max-events N] [--query-every N] [--symbols A,B,...]\n";
    return 1;
  }
  gzbuffer(f, 64 << 20);
  std::vector<unsigned char> buf(64ULL << 20);
  std::size_t pending = 0;
  std::vector<std::int8_t> loc_slot(65536, -1); // stock locate -> symbol slot
  OrderMap book;
  std::vector<Event> ev;
  std::uint64_t nmsg = 0, bad_len = 0, unknown = 0;
  bool stop = false, truncated = false;
  auto emit = [&](const Order &o, std::uint32_t price, std::int64_t d) {
    if (max_events && ev.size() >= max_events) {
      stop = true;
      return;
    }
    ev.push_back(
        Event{price, std::int32_t(d), std::int8_t(2 * o.slot + o.side)});
  };
  while (!stop) {
    int n = gzread(f, buf.data() + pending, unsigned(buf.size() - pending));
    if (n < 0) {
      truncated = true;
      break;
    }
    if (n == 0)
      break;
    std::size_t avail = pending + std::size_t(n), pos = 0;
    while (!stop && pos + 2 <= avail) {
      std::size_t len = (std::size_t(buf[pos]) << 8) | buf[pos + 1];
      if (pos + 2 + len > avail)
        break;
      const unsigned char *m = buf.data() + pos + 2;
      pos += 2 + len;
      ++nmsg;
      unsigned char type = m[0];
      if (MSG_LEN[type] && MSG_LEN[type] != len) {
        ++bad_len;
        continue;
      }
      if (until_ns && (nmsg & 0xFFFF) == 0) {
        std::uint64_t ts = 0;
        for (int b = 5; b < 11; ++b)
          ts = (ts << 8) | m[b];
        if (ts >= until_ns) {
          stop = true;
          break;
        }
      }
      std::uint16_t loc = std::uint16_t((m[1] << 8) | m[2]);
      if (type == 'A' || type == 'F') {
        std::string st(reinterpret_cast<const char *>(m + 24), 8);
        st.erase(st.find_last_not_of(' ') + 1);
        if (loc_slot[loc] < 0) {
          auto it = std::find(symbols.begin(), symbols.end(), st);
          if (it == symbols.end())
            continue;
          loc_slot[loc] = std::int8_t(it - symbols.begin());
        }
        if (std::find(symbols.begin(), symbols.end(), st) == symbols.end())
          continue;
        Order o{rd64(m + 11), rd32(m + 32), rd32(m + 20), loc_slot[loc],
                std::int8_t(m[19] == 'B' ? 0 : 1)};
        book.put(o);
        emit(o, o.price, o.shares);
        continue;
      }
      if (loc_slot[loc] < 0)
        continue; // not one of our symbols
      if (type == 'E' || type == 'C' || type == 'X') {
        Order *o = book.find(rd64(m + 11));
        if (!o) {
          ++unknown;
          continue;
        }
        std::uint32_t k = std::min(rd32(m + 19), o->shares);
        emit(*o, o->price, -std::int64_t(k)); // at the ORDER's price
        o->shares -= k;
        if (o->shares == 0)
          book.erase(o->ref);
      } else if (type == 'D') {
        Order o;
        if (!book.erase(rd64(m + 11), &o)) {
          ++unknown;
          continue;
        }
        if (o.shares)
          emit(o, o.price, -std::int64_t(o.shares));
      } else if (type == 'U') {
        Order o;
        if (!book.erase(rd64(m + 11), &o)) {
          ++unknown;
          continue;
        }
        if (o.shares)
          emit(o, o.price, -std::int64_t(o.shares));
        Order r{rd64(m + 19), rd32(m + 31), rd32(m + 27), o.slot, o.side};
        book.put(r);
        emit(r, r.price, r.shares);
      }
    }
    pending = avail - pos;
    if (pending)
      std::memmove(buf.data(), buf.data() + pos, pending);
    if ((nmsg >> 22) != ((nmsg - 1) >> 22) || true) {
      static std::uint64_t last = 0;
      if (nmsg - last >= 20000000) {
        last = nmsg;
        std::cerr << "  " << nmsg / 1000000 << "M messages, " << ev.size()
                  << " events\n";
      }
    }
  }
  gzclose(f);
  std::cerr << "replay: " << nmsg << " messages, " << ev.size() << " events, "
            << unknown << " unknown order references, " << bad_len
            << " length mismatches"
            << (truncated ? " (input ends early: truncated .gz)" : "") << "\n";
  if (ev.empty()) {
    std::cerr << "no events for these symbols\n";
    return 1;
  }

  // ---- ladders: median event price per anchor (as numpy's median: mean of the
  // two middle values)
  std::array<std::int64_t, 16> median{};
  std::array<bool, 16> live{};
  for (int a = 0; a < 16; ++a) {
    std::vector<std::uint32_t> p;
    for (auto &e : ev)
      if (e.anchor == a)
        p.push_back(e.price);
    if (p.empty())
      continue;
    live[a] = true;
    std::sort(p.begin(), p.end());
    std::size_t h = p.size() / 2;
    median[a] = (p.size() % 2) ? p[h] : (std::int64_t(p[h - 1]) + p[h]) / 2;
  }
  std::vector<std::uint16_t> ekey;
  std::vector<std::int32_t> edelta;
  std::uint64_t dropped = 0;
  for (auto &e : ev) {
    std::int64_t diff = std::int64_t(e.price) - median[e.anchor];
    std::int64_t lo = (diff >= 0 ? diff / 100 : -((-diff + 99) / 100)) +
                      2048; // floor division
    if (lo < 1 || lo > 4095) {
      ++dropped;
      continue;
    }
    ekey.push_back(std::uint16_t(e.anchor * 4096 + lo));
    edelta.push_back(e.delta);
  }

  // ---- book sanity: no level ends with negative resting shares
  std::vector<std::int64_t> net(65536, 0);
  for (std::size_t i = 0; i < ekey.size(); ++i)
    net[ekey[i]] += edelta[i];
  std::size_t neg = std::count_if(net.begin(), net.end(),
                                  [](std::int64_t x) { return x < 0; });
  if (neg)
    std::cerr << "WARNING: " << neg
              << " price levels end with negative resting shares\n";

  // ---- the stream, and the expected results from a plain Fenwick tree (mod
  // 2^32)
  std::size_t ne = ekey.size();
  std::vector<std::uint8_t> ops;
  std::vector<std::uint16_t> keys;
  std::vector<std::uint32_t> vals, exp;
  ops.reserve(2 * ne);
  keys.reserve(2 * ne);
  vals.reserve(2 * ne);
  exp.reserve(2 * ne);
  std::vector<std::uint32_t> tree(65536, 0), raw(65536, 0);
  std::uint64_t nq = 0;
  for (std::size_t i = 0; i < ne; ++i) {
    std::uint32_t k = ekey[i], d = std::uint32_t(edelta[i]);
    ops.push_back(2);
    keys.push_back(std::uint16_t(k));
    vals.push_back(d);
    exp.push_back(d);
    for (std::uint32_t x = k; x < 65536; x += x & (~x + 1))
      tree[x] += d;
    raw[k] += d;
    if ((i + 1) % query_every == 0) {
      std::uint32_t s = 0;
      for (std::uint32_t x = k; x; x -= x & (~x + 1))
        s += tree[x];
      ops.push_back(0);
      keys.push_back(std::uint16_t(k));
      vals.push_back(0);
      exp.push_back(s);
      ++nq;
    }
  }
  std::vector<std::uint32_t> final_prefix(65536, 0);
  std::uint32_t run = 0;
  for (std::size_t i = 0; i < 65536; ++i) {
    run += raw[i];
    final_prefix[i] = run;
  }

  // ---- metadata and file
  std::ostringstream meta;
  meta << "source=" << in << "\nsymbols=" << symbols_arg
       << "\nuntil=" << (until_arg.empty() ? "end of file" : until_arg)
       << "\nmessages=" << nmsg << "\nevents=" << ev.size()
       << "\nkept_events=" << ne << "\ndropped_outside_ladder=" << dropped
       << "\nqueries=" << nq << "\noperations=" << ops.size()
       << "\nquery_every=" << query_every << "\nunknown_order_refs=" << unknown
       << "\nnegative_levels=" << neg
       << "\ntick=100\nlayout=anchor 2s bids, 2s+1 asks; 4095 levels centred "
          "on the ladder median\n";
  int nlive = 0;
  for (int a = 0; a < 16; ++a)
    if (live[a]) {
      meta << "median_" << a << "=" << median[a] << "\n";
      ++nlive;
    }
  meta << "anchors_live=" << nlive << "\n";
  std::string ms = meta.str();
  const bool gz = out.size() > 3 && out.compare(out.size() - 3, 3, ".gz") == 0;
  FILE *o = nullptr;
  gzFile g = nullptr;
  if (gz)
    g = gzopen(out.c_str(), "wb6");
  else
    o = std::fopen(out.c_str(), "wb");
  if (!o && !g) {
    std::cerr << "cannot write " << out << "\n";
    return 1;
  }
  bool wr_ok = true;
  auto put =
      [&](const void *p,
          std::size_t bytes) { // in pieces: gzwrite takes an unsigned length
        const char *c = static_cast<const char *>(p);
        while (bytes && wr_ok) {
          std::size_t k = std::min<std::size_t>(bytes, 1u << 26);
          wr_ok = gz ? gzwrite(g, c, unsigned(k)) == int(k)
                     : std::fwrite(c, 1, k, o) == k;
          c += k;
          bytes -= k;
        }
      };
  std::uint32_t version = 1, mlen = std::uint32_t(ms.size());
  std::uint64_t n = ops.size();
  put("SALSAOPS", 8);
  put(&version, 4);
  put(&n, 8);
  put(&mlen, 4);
  put(ms.data(), mlen);
  put(ops.data(), n);
  put(keys.data(), 2 * n);
  put(vals.data(), 4 * n);
  put(exp.data(), 4 * n);
  put(final_prefix.data(), 4 * 65536);
  if (gz ? gzclose(g) != Z_OK : std::fclose(o) != 0)
    wr_ok = false;
  if (!wr_ok) {
    std::cerr << "write failed: " << out << "\n";
    return 1;
  }
  std::cout << ms << "wrote " << out << " (" << n << " operations"
            << (gz ? ", gzip" : "") << ")\n";
  return 0;
}
