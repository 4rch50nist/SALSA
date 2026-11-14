#!/bin/sh
set -e

: "${SYMBOLS:?set SYMBOLS to the tickers to replay, e.g. SYMBOLS=\"QQQ AAPL ...\"}"
FOCUS="${FOCUS:-QQQ}"
ITCH_URL="${ITCH_URL:-https://emi.nasdaq.com/ITCH/Nasdaq%20ITCH/01302019.NASDAQ_ITCH50.gz}"

mkdir -p data runs

if [ ! -f data/itch.gz ]; then
  curl -L --fail -C - -o data/itch.gz.part "$ITCH_URL"
  mv data/itch.gz.part data/itch.gz
fi

g++ -O3 -std=c++17 parser.cpp -lz -o parser

if [ ! -f data/events.csv ]; then
  rm -f data/events.fifo
  mkfifo data/events.fifo
  LC_ALL=C awk -F, -v syms="$SYMBOLS" 'BEGIN { n = split(syms, a, " "); for (i = 1; i <= n; i++) keep[a[i]] = 1 } ($2 in keep)' \
    < data/events.fifo > data/events.csv.part &
  ./parser data/itch.gz data/events.fifo 0
  wait
  rm -f data/events.fifo
  mv data/events.csv.part data/events.csv
fi

python3 hazard_sim.py data/events.csv "$SYMBOLS" "$FOCUS"
python3 make_itch_figure.py "$FOCUS" "$(echo $SYMBOLS | wc -w)"
