# SALSA, TRL 5 build

| File | What |
| --- | --- |
| `salsa_fenwick_pull.sv` | your front-end (`salsa_fen_pull_top`, with `chain_gen` and `prefix_popcount`), unchanged |
| `salsa.sv` | everything else: `salsa_pkg` (word format), `salsa_datapath` (front-end + banks + roots + adder), `salsa` (top: AXI-Stream, result FIFO, AXI-Lite registers) |
| `tb_salsa.sv` | testbench, through the AXI interfaces only |
| `run.sh` | `bash run.sh` builds and runs it with Verilator 5 |

**Vivado:** add `salsa_fenwick_pull.sv` and `salsa.sv`; in the block design, add module `salsa` where the AXI-Stream FIFO was.

**Word** (64 bits): `op` [63:62] (0 query, 1 store), `seq` [61:48], `key` [47:32], `value` [31:0].

**Registers:** 0x00 CTRL (write 1 = start), 0x04 STATUS (bit 0 done), 0x08 RUN_LEN, 0x0C CYCLES, 0x10 REQ_COUNT, 0x14 RES_COUNT, 0x18 LATENCY, 0x40 to 0x7C BANK_STORES[0..15], 0x80 ROOT_STORES.

**Run:** set RUN_LEN, write CTRL = 1, DMA the words (receive channel first), poll STATUS. Load the tree with stores, then query. Reload the overlay to clear the banks.

**Simulation:** 65,535 stores, every bank 4,095, roots 15; 20,000 queries in 20,009 cycles, latency 9; 20,000 more under backpressure; 0 errors.
