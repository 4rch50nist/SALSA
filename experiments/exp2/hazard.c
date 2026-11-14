#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#define N 65536
#define LAG 2
#define WIN 250
#define MARK 5000

typedef struct {
  int64_t visible[N];
  int64_t cyc, nops, wstart, wops;
  FILE *out;
} Pipe;

static void issue(Pipe *p, int kind, unsigned key) {
  int64_t ready = p->cyc + 1;
  if (kind == 0) {
    for (unsigned v = key; v; v &= v - 1)
      if (p->visible[v] > ready)
        ready = p->visible[v];
  } else
    for (unsigned v = key; v && v < N; v += v & (~v + 1))
      if (p->visible[v] > ready)
        ready = p->visible[v];
  p->cyc = ready;
  if (kind == 2)
    for (unsigned v = key; v && v < N; v += v & (~v + 1))
      p->visible[v] = p->cyc + LAG;
  p->nops++;
  p->wops++;
  if (p->wops == WIN) {
    fprintf(p->out, "W %.6f\n", (double)WIN / (double)(p->cyc + 1 - p->wstart));
    p->wstart = p->cyc + 1;
    p->wops = 0;
  }
}

static void finish(Pipe *p) {
  fprintf(p->out, "TOTAL ops %lld cycles %lld throughput %.4f ops/cycle\n",
          (long long)p->nops, (long long)(p->cyc + 1),
          (double)p->nops / (double)(p->cyc + 1));
  fclose(p->out);
}

static unsigned char *slurp(const char *path, size_t *len) {
  gzFile f = gzopen(path, "rb");
  if (!f) {
    fprintf(stderr, "cannot open %s\n", path);
    exit(1);
  }
  size_t cap = 1 << 26, n = 0;
  unsigned char *b = malloc(cap);
  int r;
  while ((r = gzread(f, b + n, (unsigned)(cap - n))) > 0) {
    n += r;
    if (n == cap)
      b = realloc(b, cap *= 2);
  }
  gzclose(f);
  *len = n;
  return b;
}

static int64_t vol[16][4096];
static int best[16];

static int find_best(int a) {
  if (a & 1) {
    for (int l = 1; l < 4096; l++)
      if (vol[a][l] > 0)
        return l;
  } else {
    for (int l = 4095; l >= 1; l--)
      if (vol[a][l] > 0)
        return l;
  }
  return 0;
}

int main(int argc, char **argv) {
  size_t len;
  unsigned char *d = slurp(argc > 1 ? argv[1] : "itch_ops.bin.gz", &len);
  if (len < 24 || memcmp(d, "SALSAOPS", 8)) {
    fprintf(stderr, "not an itch_ops stream\n");
    return 1;
  }
  uint64_t n;
  uint32_t ml;
  memcpy(&n, d + 12, 8);
  memcpy(&ml, d + 20, 4);
  const unsigned char *ops = d + 24 + ml;
  const unsigned char *keys = ops + n, *vals = ops + 3 * n;

  static Pipe all, qqq;
  all.cyc = qqq.cyc = -1;
  all.out = fopen("itch_stall_l2.txt", "w");
  qqq.out = fopen("itch_qqq_stall.txt", "w");
  FILE *pos = fopen("itch_qqq_pos.txt", "w");
  int64_t at = 0;

  for (uint64_t i = 0; i < n; i++) {
    if (ops[i] != 2)
      continue;
    uint16_t key;
    int32_t delta;
    memcpy(&key, keys + 2 * i, 2);
    memcpy(&delta, vals + 4 * i, 4);
    int a = key >> 12, l = key & 4095;
    vol[a][l] += delta;
    int b = best[a];
    if (vol[a][l] > 0 && (b == 0 || ((a & 1) ? l < b : l > b)))
      best[a] = l;
    else if (l == b && vol[a][l] <= 0)
      best[a] = find_best(a);
    unsigned qk = best[a] ? (unsigned)(a * 4096 + best[a]) : key;
    unsigned rec[2][2] = {{2, key}, {0, qk}};
    for (int r = 0; r < 2; r++, at++) {
      issue(&all, rec[r][0], rec[r][1]);
      if ((rec[r][1] >> 13) == 0) {
        if (qqq.nops % MARK == 0)
          fprintf(pos, "%lld\n", (long long)at);
        issue(&qqq, rec[r][0], rec[r][1]);
      }
    }
  }
  finish(&all);
  finish(&qqq);
  fclose(pos);
  printf("all eight symbols: %lld operations, %.4f cycles per operation\n",
         (long long)all.nops, (double)(all.cyc + 1) / all.nops);
  printf("QQQ alone:         %lld operations, %.4f cycles per operation\n",
         (long long)qqq.nops, (double)(qqq.cyc + 1) / qqq.nops);
  return 0;
}
