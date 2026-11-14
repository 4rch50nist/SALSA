#!/bin/sh
set -e

git clone -q --depth 1 https://github.com/pulp-platform/cluster_interconnect.git
git clone -q --depth 1 --branch v1.22.1 https://github.com/pulp-platform/common_cells.git
CI=cluster_interconnect/rtl/tcdm_interconnect; CC=common_cells

verilator --binary --timing -Wno-fatal -Wno-WIDTH -Wno-UNOPTFLAT -Wno-MULTIDRIVEN -Wno-CASEINCOMPLETE -Wno-SELRANGE \
  -I$CC/include --top-module tb -o sim \
  $CC/src/cf_math_pkg.sv $CC/src/lzc.sv $CC/src/rr_arb_tree.sv $CC/src/lfsr.sv \
  $CI/tcdm_interconnect_pkg.sv $CI/addr_dec_resp_mux.sv $CI/xbar.sv $CI/bfly_net.sv $CI/clos_net.sv $CI/tcdm_interconnect.sv \
  tb_xor_interco.sv

mkdir -p runs
for i in $(seq 1 100); do
  l=$(printf "%.2f" "$(echo "$i/100" | bc -l)")
  ./obj_dir/sim +place=xor +xregs +mode=open +lambda=$l +n=60000 +out=runs/xor_$l.txt > /dev/null
done

python3 make_conflict_heatmap.py
