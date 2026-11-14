import numpy as np

G, WIN = 40, 250

def curve(path):
    w, total = [], None
    for line in open(path):
        if line.startswith("W "): w.append(1.0 / float(line.split()[1]))
        elif line.startswith("TOTAL"): f = line.split(); total = int(f[4]) / int(f[2])
    w = np.array(w)
    rows = []
    for g in range(len(w) // G):
        c = w[g * G:(g + 1) * G]
        rows.append([(g + 0.5) * G * WIN / 1e6, np.median(c), np.percentile(c, 10), np.percentile(c, 90)])
    return np.array(rows), total

A, ta = curve("itch_stall_l2.txt")
Q, tq = curve("itch_qqq_stall.txt")
pos = np.loadtxt("itch_qqq_pos.txt", dtype=np.int64, ndmin=1)
Q[:, 0] = pos[np.minimum(2 * np.arange(len(Q)) + 1, len(pos) - 1)] / 1e6
xmax = np.ceil(max(A[-1, 0], Q[-1, 0]) * 20) / 20
print(f"overall cycles per operation: all eight symbols {ta:.4f}, QQQ alone {tq:.4f}")

def table(d):
    return "x med lo hi\n" + "\n".join(f"{x:.4f} {m:.4f} {l:.4f} {h:.4f}" for x, m, l, h in d) + "\n}"

def series(d, tag, band, line):
    return (f"  \\addplot[draw=none, name path={tag}lo, forget plot] table[x=x, y=lo]{{\n{table(d)};\n"
            f"  \\addplot[draw=none, name path={tag}hi, forget plot] table[x=x, y=hi]{{\n{table(d)};\n"
            f"  \\addplot[{band}, fill opacity=0.35, draw=none, forget plot] fill between[of={tag}lo and {tag}hi];\n"
            f"  \\addplot[{line}, forget plot] table[x=x, y=med]{{\n{table(d)};\n")

tex = (r"""\begin{figure}[!t]
\centering
\begin{tikzpicture}[trim axis right]
\begin{axis}[width=\columnwidth, height=0.5\columnwidth, axis lines=box, axis line style={black, line width=0.5pt}, tick align=inside, tick style={black!70},
  grid=both, minor x tick num=1, minor y tick num=1,
  major grid style={black!40, dotted, line width=0.5pt}, minor grid style={black!18, dotted, line width=0.4pt},
  tick label style={font=\scriptsize}, label style={font=\footnotesize}, title style={font=\footnotesize},
  ylabel={Cycles per Operation}, ylabel style={yshift=-2pt},
  legend style={font=\scriptsize, draw=black!60, fill=white, fill opacity=0.9, text opacity=1, legend cell align=left},
""" + f"  xmin=0, xmax={xmax:g}, ymin=0.95, ymax=1.65, ytick={{1.0,1.2,1.4,1.6}},\n" + r"""  xlabel={Operations (Millions)}, title={(a) NASDAQ ITCH order flow},
  legend style={at={(0.98,0.97)}, anchor=north east, legend columns=2, column sep=5pt}]
""" + f"  \\draw[black!60, line width=0.6pt, loosely dashed] (axis cs:0,1) -- (axis cs:{xmax:g},1);\n"
    + series(A, "ia", "fill=black!18", "black, line width=1.0pt")
    + series(Q, "iq", "fill=black!10", "black!60, line width=1.0pt, densely dashed")
    + r"""  \addlegendimage{black, line width=1.0pt}\addlegendentry{All eight symbols}
  \addlegendimage{black!60, line width=1.0pt, densely dashed}\addlegendentry{QQQ alone}
\end{axis}
\end{tikzpicture}
\caption{Cycles per operation of a pipeline that stalls whenever an operation needs a write still in flight, over NASDAQ ITCH order flow for all eight symbols and for QQQ alone. The dashed line marks one cycle per operation; lines are medians, and bands span the 10th to 90th percentiles.}
\label{fig:rw_throughput}
\end{figure}
""")
open("itch_fig.tex", "w").write(tex)
print("wrote itch_fig.tex")
