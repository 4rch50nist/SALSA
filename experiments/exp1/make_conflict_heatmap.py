import numpy as np

RUN = "runs/xor_{:.2f}.txt"
LOADS = [c / 100 for c in range(5, 81, 5)] + [c / 100 for c in range(83, 101)]
DRAWN = [0.20, 0.80, 0.86, 0.87, 0.90, 1.00]
KNEE = 0.865
XMAX = 12000
STYLES = ["cS1", "cS2", "cI1", "cI2", "cX1", "cX2"]
FILLS = ["rS!50", "rS", "black", "black!55", "rX!60", "rX"]
NPTS = 257

SPLIT, LEFT = 0.825, 0.6
def TX(x): return x / SPLIT * LEFT if x <= SPLIT else LEFT + (x - SPLIT) / (1 - SPLIT) * (1 - LEFT)

def lat(load): return np.loadtxt(RUN.format(load), ndmin=2)[:, 0].astype(int)
def g(v): return f"{v:g}"

YMIN = 1e-5

def ccdf(a):
    s = np.sort(a); n = len(s)
    grid = np.unique(np.round(np.geomspace(4, s[-1], NPTS)).astype(int))
    tail = np.unique(s[int(0.99 * n):])
    grid = np.union1d(grid, np.union1d(tail, tail - 1))
    pts = [(L, (n - np.searchsorted(s, L, side="right")) / n) for L in grid]
    pts = [(L, p) for L, p in pts if p > 0] + [(s[-1], YMIN)]
    return " ".join(f"({L},{g(round(p, 6))})" for L, p in pts)

AX = (r"width=0.42\textwidth, height=0.25\textwidth, axis lines=box, axis line style={black, line width=0.5pt}, "
      r"tick align=inside, tick style={black!70},")
GRID = (r"major grid style={black!40, dotted, line width=0.5pt}, minor grid style={black!15, dotted, line width=0.4pt},"
        "\n  " r"tick label style={font=\scriptsize}, label style={font=\footnotesize}, title style={font=\footnotesize},")

def panel():
    ticks = [4 ** k for k in range(1, 12) if 4 ** k <= XMAX]
    o = [r"\begin{tikzpicture}", r"\begin{axis}[" + AX,
         "  xmode=log, log basis x=2, ymode=log, grid=both,", "  " + GRID,
         r"  xlabel={Latency $L$ (Cycles)}, ylabel={Share Slower than $L$}, ylabel style={yshift=-4pt},",
         f"  ymin={YMIN:g}, ymax=1.6, xmin=3.6, xmax={XMAX},",
         "  xtick={" + ",".join(map(str, ticks)) + "}, xticklabels={"
         + ",".join(f"$2^{{{int(np.log2(t))}}}$" for t in ticks) + "}, title={(a) Fenwick}]"]
    for st, load in zip(STYLES, DRAWN):
        o.append(f"  \\addplot[{st}] coordinates {{{ccdf(lat(load))}}};")
    o += [r"  \draw[black!55, line width=0.5pt, densely dashed] (axis cs:8,1e-5) -- (axis cs:8,1.6);",
          f"  \\draw[black!55, line width=0.5pt, densely dashed] (axis cs:3.6,1e-3) -- (axis cs:{XMAX},1e-3);",
          r"  \node[font=\tiny, text=black!70, anchor=south west, inner sep=1pt, rotate=90] at (axis cs:8.4,1.5e-5) {8 cycles};",
          r"  \node[font=\tiny, text=black!70, anchor=south west, inner sep=1pt] at (axis cs:3.8,1.12e-3) {1 in 1{,}000};",
          r"\end{axis}", r"\end{tikzpicture}\hspace{0.06\textwidth}"]
    return "\n".join(o)

def medians():
    xt = [0, 0.4, 0.8, 0.9, 1.0]
    med = {l: float(np.median(lat(l))) for l in LOADS}
    o = [r"\begin{tikzpicture}",
         r"\begin{axis}[width=0.42\textwidth, height=0.25\textwidth, axis lines=box, axis line style={black, line width=0.5pt},",
         "  tick align=inside, tick style={black!70}, xmin=0, xmax=1, ymin=3.4, ymax=40000, clip=false,",
         "  ymode=log, log basis y=2, xtick={" + ",".join(f"{TX(t):.4g}" for t in xt) + "}, xticklabels={"
         + ",".join(f"{t:g}" for t in xt) + "},",
         r"  ytick={4,64,1024,16384}, yticklabels={$2^{2}$,$2^{6}$,$2^{10}$,$2^{14}$},",
         r"  grid=both, major grid style={black!40, dotted, line width=0.5pt}, minor grid style={black!15, dotted, line width=0.4pt},",
         r"  tick label style={font=\scriptsize}, label style={font=\footnotesize}, title style={font=\footnotesize, yshift=6pt},",
         r"  xlabel={Offered Load}, ylabel={Median (Cycles)}, ylabel style={yshift=-4pt}, title={(b) Median latency by load}]"]
    pts = " ".join(f"({TX(l):.4f},{m:.1f})" for l, m in med.items())
    o.append(f"  \\addplot[black!45, line width=0.7pt] coordinates {{{pts}}};")
    x = TX(KNEE)
    o += [f"  \\draw[cLn, densely dashed, line width=0.8pt] (axis cs:{x},3.4) -- (axis cs:{x},40000);",
          f"  \\node[font=\\scriptsize, text=cLn, anchor=south, inner sep=1.5pt] at (axis cs:{x},40000) {{{KNEE:g}}};"]
    o.append("  " + " ".join(
        f"\\addplot[only marks, mark=*, mark size=1.6pt, draw=white, line width=0.3pt, fill={f}] "
        f"coordinates {{({TX(l):.4f},{med[l]:.1f})}};" for f, l in zip(FILLS, DRAWN)))
    o += [r"\end{axis}", r"\end{tikzpicture}%"]
    return "\n".join(o), med

HEAD = r"""\begin{figure*}[!t]
\centering
{%
\definecolor{rS}{HTML}{2B6CB0}\definecolor{rX}{HTML}{C0392B}\definecolor{cLn}{HTML}{E4572E}%
\pgfplotsset{cS1/.style={rS!50, line width=0.8pt}, cS2/.style={rS, line width=0.8pt, densely dashed},
  cI1/.style={black, line width=0.9pt}, cI2/.style={black!55, line width=0.9pt, dash dot},
  cX1/.style={rX!60, line width=0.8pt, dotted}, cX2/.style={rX, line width=0.9pt}}%
"""
TAIL = r"""
}
\caption{Fenwick query latency under XOR-folded placement through the PULP TCDM crossbar: (a)~share of queries slower than $L$ at six loads; (b)~median latency against load, with the inflection and the loads drawn in (a) marked.}
\label{fig:conflict_ccdf}
\end{figure*}
"""
if __name__ == "__main__":
    m, med = medians()
    open("conflict_heatmaps.tex", "w").write(HEAD + panel() + "\n" + m + TAIL)
    print("wrote conflict_heatmaps.tex")
    for l in LOADS: print(f"{l:.2f} {med[l]:.1f}")
