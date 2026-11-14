#!/bin/bash
# Simulate with Verilator 5:   bash run.sh
set -e
verilator --binary --timing -Wno-fatal -Wno-WIDTHEXPAND -Wno-WIDTHTRUNC --timescale 1ns/1ps --top-module tb_salsa -o sim \
  salsa_segment_pull.sv salsa.sv tb_salsa.sv
./obj_dir/sim
