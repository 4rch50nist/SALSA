#!/bin/sh
set -e

ITCH_URL="${ITCH_URL:-https://emi.nasdaq.com/ITCH/Nasdaq%20ITCH/01302019.NASDAQ_ITCH50.gz}"
FEED=data/01302019.NASDAQ_ITCH50.gz

mkdir -p data runs

if [ ! -f "$FEED" ]; then
  curl -L --fail -C - -o "$FEED.part" "$ITCH_URL"
  mv "$FEED.part" "$FEED"
fi

g++ -O2 -std=c++17 -o runs/itch_ops itch_ops.cpp -lz
gcc -O2 -o runs/hazard hazard.c -lz

[ -f runs/itch_ops.bin.gz ] || ./runs/itch_ops "$FEED" runs/itch_ops.bin.gz --until 10:30

cd runs
./hazard itch_ops.bin.gz
python3 ../make_figure.py
cp itch_fig.tex ..
