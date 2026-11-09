#!/bin/bash
# Simulate with Verilator 5:   bash run.sh
set -e
verilator --binary --timing -Wno-fatal -Wno-WIDTHEXPAND -Wno-WIDTHTRUNC --top-module tb_system -o sim \
  salsa_fenwick_pull.sv salsa.sv tb_salsa.sv
./obj_dir/sim
