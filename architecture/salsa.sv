// salsa.sv: the SALSA system around your front-end (salsa_fenwick_pull.sv).
//
//   s_axis -> salsa_datapath (4 cycles, never stalls) -> result FIFO -> m_axis
//   s_axi  -> registers (start, run length, counters)
//
// Word format (s_axis and m_axis, 64 bits):
//   [63:62] op (0 query, 2 update; 1 and 3 reserved, treated as queries)
//   [61:48] seq  [47:32] key  [31:0] delta / result
// There is no store: the tree is built by updates from the all-zero state the block
// RAMs and roots have after configuration (update key i by a[i] for every i).

package salsa_pkg;
  localparam int W = 16, K = 12, B = 16, R = 15;   // key bits, set bits, banks, roots
  localparam logic [1:0] OP_QUERY = 0, OP_UPDATE = 2;
  typedef struct packed {
    logic [1:0]  op;
    logic [13:0] seq;
    logic [15:0] key;
    logic [31:0] value;
  } word_t;
endpackage

// ---------------------------------------------------------------------------
// Datapath: front-end + 16 banks + 15 roots + adder.
//   update: add the delta to every node on the key's update path; result = echo
//   query : result = sum of every node on the key's query path
// Write lag 2, additive corrections (reference model: lag2_model.py). Principles:
//  1. a block RAM output feeds only the partial-sum adder (as in Stage 1) and a capture flop;
//  2. cycle 2 (front end -> block RAM address) is untouched; comparisons run in cycle 3 on
//     registered addresses;
//  3. an update reads at E2 and writes at E4, the value q + delta + correction computed in
//     cycle 4 from flops; a read misses at most ops m-1 and m-2, and since updates only add,
//     it is corrected by adding their deltas (registers);
//  4. a query shares at most ONE node with any update (Fenwick: the query's ranges partition
//     [1, j]; the update's nodes are those whose range contains i), so its correction is
//     [hit1] d1 + [hit2] d2: no count, no multiply.
// Every path out of a block RAM ends at a flop; every path into one starts at a flop.
// Roots are registers (read-modify-write at E2), so they need no correction.
// ---------------------------------------------------------------------------
module salsa_datapath import salsa_pkg::*; (
  input  logic               clk, rst,
  input  logic               in_valid,
  input  word_t              in_word,
  output logic               out_valid,
  output word_t              out_word,
  output logic [B-1:0][31:0] bank_stores,
  output logic [31:0]        root_stores
);
  // ---- front-end
  logic iss_valid, iss_write, iss_update, ready, own_root; logic [R-1:0] rupd; logic [B-1:0] own;
  logic [B-1:0] en; logic [B*K-1:0] set; logic [3:0] lane, hi; logic [31:0] data;

  salsa_fen_pull_top #(.W(W), .K(K), .B(B), .DW(32), .IN_REG(1'b0), .ISS_REG(1'b0), .LEVEL(1'b1)) u_fe (
    .clk, .rst_n(!rst),
    .q_valid(in_valid), .q_is_write(1'b0), .q_is_update(in_word.op == OP_UPDATE),
    .q_idx(in_word.key), .q_data(in_word.value), .q_ready(ready),
    .iss_valid, .iss_write, .iss_update, .iss_root_upd(rupd), .iss_own_en(own), .iss_own_root(own_root),
    .iss_bank_en(en), .iss_bank_set(set),
    .iss_reg_en(lane), .iss_hi(hi), .iss_data(data));

  // the request word, delayed to line up with the front-end's 1 cycle (tag register only)
  word_t w0;
  always_ff @(posedge clk) w0 <= in_word;

  logic query, update;
  assign update = iss_valid &&  iss_update;
  assign query  = iss_valid && !iss_update;

  // deltas by stage: dat3 = this op (cycle 3), dat4 = op m-1, dat5 = op m-2
  logic [31:0] dat3, dat4, dat5;
  always_ff @(posedge clk) begin dat3 <= data; dat4 <= dat3; dat5 <= dat4; end
  logic [B-1:0] en1;                           // cycle 3: query bank enables
  logic [B-1:0] qh1, qh2;                      // cycle 3: query shares this bank's node with op m-1 / m-2

  // ---- 16 banks, 4096 x 32 bits each (simple dual-port block RAM, 1-cycle read)
  //      read at E2; update write at E4 from flops (write lag 2); READ_FIRST on the write port
  logic [B-1:0][31:0] rd;
  for (genvar b = 0; b < B; b++) begin : g_bank
    (* ram_style = "block" *) logic [31:0] mem [4096];
    logic [31:0] q, qreg, xreg, c;
    logic [K-1:0] s3, s4, s5;                  // this op's set, op m-1's, op m-2's (registered)
    logic u3, u4, u5, h1, h2, ren;             // bank written by this op / m-1 / m-2
    initial for (int i = 0; i < 4096; i++) mem[i] = 0;
    assign ren = (query || update) && en[b];
    assign rd[b] = q;                          // partial sums: block RAM data only (Stage 1)
    // cycle 3, registers only: did op m-1 / m-2 write (or will write) this op's node?
    assign h1 = u4 && (s4 == s3);
    assign h2 = u5 && (s5 == s3);
    assign c  = (h1 ? dat4 : 32'd0) + (h2 ? dat5 : 32'd0);
    assign qh1[b] = en1[b] && h1;
    assign qh2[b] = en1[b] && h2;
    always_ff @(posedge clk) begin
      if (ren) q <= mem[set[b*K +: K]];        // E2: read (address path as in Stage 1)
      if (u4)  mem[s4] <= qreg + xreg;         // E4: write from flops (op in stage 4)
      qreg <= q;                               // E3: capture the read
      xreg <= dat3 + c;                        // E3: delta + correction, from registers
      s3 <= set[b*K +: K]; u3 <= update && en[b];
      s4 <= s3;            u4 <= u3;
      s5 <= s4;            u5 <= u4;
      // balance counter: updates whose OWN node (the key's own level) is in this bank
      if (rst) bank_stores[b] <= 0; else if (update && own[b]) bank_stores[b] <= bank_stores[b] + 1;
    end
  end

  // ---- 15 roots; lane j of iss_reg_en means the root "hi with bits below j cleared"
  //   a query needs at most one root per lane (4 lanes); select them here and add
  //   them a cycle later (rsel1 -> rs2), so no wide adder sits in the issue cycle
  logic [R-1:0] rflag; logic [R-1:0][31:0] root; logic [3:0][31:0] rsel;
  always_comb begin
    rflag = 0;
    for (int j = 0; j < 4; j++) if (lane[j]) rflag[(hi & ~4'((1 << j) - 1)) - 1] = 1;
    for (int j = 0; j < 4; j++) begin
      logic [3:0] idx;
      idx = (hi & ~4'((1 << j) - 1)) - 1;            // root on lane j (valid when lane[j])
      rsel[j] = (lane[j] && idx < R) ? root[idx] : 32'd0;
    end
  end
  always_ff @(posedge clk)
    if (rst) begin root <= 0; root_stores <= 0; end
    else begin
      if (update) begin                             // roots on the anchor-space update chain
        for (int h = 0; h < R; h++) if (rupd[h]) root[h] <= root[h] + data;
        if (own_root) root_stores <= root_stores + 1;   // updates whose own node is a root
      end
    end

  // ---- 1 cycle for the banks, then add: partial sums registered, final add
  //      combinational into the result FIFO / output register
  logic v1, v2; word_t x1, x2; logic [31:0] corr4;

  logic [3:0][31:0] rsel1; logic [31:0] rs2; logic [3:0][31:0] part, part_c;

  // query correction (cycle 3, registers only): at most one shared node per pending update
  logic [31:0] corr_q;
  assign corr_q = ((|qh1) ? dat4 : 32'd0) + ((|qh2) ? dat5 : 32'd0);

  always_comb
    for (int g = 0; g < 4; g++) begin
      part_c[g] = 0;
      for (int k = 0; k < 4; k++) if (en1[4*g+k]) part_c[g] += rd[4*g+k];
    end

  always_ff @(posedge clk) begin
    v1 <= !rst && iss_valid; v2 <= !rst && v1;
    x1 <= w0; en1 <= query ? en : 0; rsel1 <= query ? rsel : '0;
    corr4 <= corr_q;
    x2 <= x1; part <= part_c;        rs2 <= rsel1[0] + rsel1[1] + rsel1[2] + rsel1[3];

  end

  // final add, unregistered: the result goes straight to the FIFO or the output register
  always_comb begin
    out_valid = v2;
    out_word  = x2;
    if (x2.op == OP_QUERY) out_word.value = part[0] + part[1] + part[2] + part[3] + rs2 + corr4;
  end
endmodule

// ---------------------------------------------------------------------------
// Top level: AXI-Stream in/out + AXI-Lite registers. Put this in the block design.
// Registers: 0x00 CTRL (write 1 = start)   0x04 STATUS (bit0 done)   0x08 RUN_LEN
//            0x0C CYCLES  0x10 REQ_COUNT  0x14 RES_COUNT  0x18 LATENCY
//            0x40..0x7C BANK_STORES[0..15]: updates whose own node is in bank b
//            0x80 ROOT_STORES: updates whose own node is a root
//            (build the tree with each key once: 4,095 per bank and 15 roots = exact balance)
// ---------------------------------------------------------------------------
module salsa import salsa_pkg::*; #(
  parameter int DEPTH = 32                     // result FIFO; must exceed the datapath latency
) (
  input  wire        aclk, aresetn,
  input  wire [63:0] s_axis_tdata,  input  wire s_axis_tvalid, output wire s_axis_tready,
  input  wire        s_axis_tlast,
  output reg  [63:0] m_axis_tdata,  output reg  m_axis_tvalid, input  wire m_axis_tready,
  output reg         m_axis_tlast,
  input  wire [7:0]  s_axi_awaddr,  input  wire [2:0] s_axi_awprot,
  input  wire        s_axi_awvalid, output wire s_axi_awready,
  input  wire [31:0] s_axi_wdata,   input  wire [3:0] s_axi_wstrb,
  input  wire        s_axi_wvalid,  output wire s_axi_wready,
  output wire [1:0]  s_axi_bresp,   output reg  s_axi_bvalid,  input wire s_axi_bready,
  input  wire [7:0]  s_axi_araddr,  input  wire [2:0] s_axi_arprot,
  input  wire        s_axi_arvalid, output wire s_axi_arready,
  output reg  [31:0] s_axi_rdata,   output wire [1:0] s_axi_rresp,
  output reg         s_axi_rvalid,  input  wire s_axi_rready
);
  logic rst;
  assign rst = !aresetn;

  // ---- input handshake; credits: accept only if every result in flight has a FIFO slot
  logic accept, out_valid;
  word_t out_word;
  logic [7:0] in_flight, count;
  assign accept        = s_axis_tvalid && s_axis_tready;
  assign s_axis_tready = aresetn && (count + in_flight < DEPTH);

  always_ff @(posedge aclk)
    if (rst) in_flight <= 0; else in_flight <= in_flight + accept - out_valid;

  logic [B-1:0][31:0] bank_stores; logic [31:0] root_stores;
  salsa_datapath u_dp (.clk(aclk), .rst,
    .in_valid(accept), .in_word(word_t'(s_axis_tdata)),
    .out_valid, .out_word, .bank_stores, .root_stores);

  // ---- result FIFO with a registered output and fall-through; tlast rides along as bit 64
  //  A finished result goes straight to the output register when the FIFO is empty and
  //  the output is free (bypass), saving the FIFO write cycle. Otherwise it is queued
  //  (push) and leaves in order (load). Bypass needs an empty FIFO, so order is kept.
  logic start; logic [31:0] run_len, pushed;
  logic [64:0] fifo [DEPTH];
  logic [$clog2(DEPTH)-1:0] wp, rp;
  logic free, load, bypass, push, last;
  assign free   = !m_axis_tvalid || m_axis_tready;        // output register can take a word
  assign load   = free && count != 0;                      // oldest queued result to the output
  assign bypass = free && count == 0 && out_valid;         // new result straight to the output
  assign push   = out_valid && !bypass;                    // new result into the FIFO
  assign last   = pushed == run_len - 1;                   // this result ends the run

  always_ff @(posedge aclk) begin
    if (push) fifo[wp] <= {last, out_word};
    if (rst) begin
      wp <= 0; rp <= 0; count <= 0; m_axis_tvalid <= 0;
    end else begin
      if (push) wp <= wp + 1;
      if (load) rp <= rp + 1;
      count <= count + push - load;
      if (free) m_axis_tvalid <= load || bypass;
    end
    if (load)        {m_axis_tlast, m_axis_tdata} <= fifo[rp];
    else if (bypass) {m_axis_tlast, m_axis_tdata} <= {last, out_word};
    if (rst || start) pushed <= 0; else if (out_valid) pushed <= pushed + 1;
  end

  // ---- counters
  logic send, timing, done, got_first;
  logic [31:0] cycles, req_count, res_count, latency;
  assign send = m_axis_tvalid && m_axis_tready;

  always_ff @(posedge aclk)
    if (rst || start) begin
      timing <= 0; done <= 0; got_first <= 0;
      cycles <= 0; req_count <= 0; res_count <= 0; latency <= 0;
    end else begin
      if (accept && !timing && !done) timing <= 1;
      if (timing || (accept && !done)) cycles <= cycles + 1;
      if (timing && !got_first) latency <= latency + 1;
      if (send) got_first <= 1;
      if (send && m_axis_tlast) begin timing <= 0; done <= 1; end
      req_count <= req_count + accept;
      res_count <= res_count + send;
    end

  // ---- AXI-Lite: a write needs address and data together, and a free B channel
  logic wr;
  assign s_axi_awready = wr;
  assign s_axi_wready  = wr;
  assign s_axi_arready = !s_axi_rvalid;
  assign s_axi_bresp = 0;
  assign s_axi_rresp = 0;

  always_ff @(posedge aclk) begin
    wr    <= !rst && !wr && s_axi_awvalid && s_axi_wvalid && (!s_axi_bvalid || s_axi_bready);
    start <= wr && s_axi_awaddr[7:2] == 0 && s_axi_wdata[0];
    if (rst) run_len <= 0; else if (wr && s_axi_awaddr[7:2] == 2) run_len <= s_axi_wdata;

    if (rst) s_axi_bvalid <= 0; else if (wr) s_axi_bvalid <= 1; else if (s_axi_bready) s_axi_bvalid <= 0;
    if (rst) s_axi_rvalid <= 0; else if (s_axi_arvalid && s_axi_arready) s_axi_rvalid <= 1;
    else if (s_axi_rready) s_axi_rvalid <= 0;

    if (!s_axi_rvalid || s_axi_rready)
      case (s_axi_araddr[7:2])
        1:  s_axi_rdata <= {31'd0, done};
        2:  s_axi_rdata <= run_len;
        3:  s_axi_rdata <= cycles;
        4:  s_axi_rdata <= req_count;
        5:  s_axi_rdata <= res_count;
        6:  s_axi_rdata <= latency;
        32: s_axi_rdata <= root_stores;
        default: s_axi_rdata <= (s_axi_araddr[7:6] == 1) ? bank_stores[s_axi_araddr[5:2]] : 0;
      endcase
  end

  wire unused = ^{s_axis_tlast, s_axi_awprot, s_axi_arprot, s_axi_wstrb};
endmodule
