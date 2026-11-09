`timescale 1ns/1ps
package salsa_pkg;
  localparam int W    = 16, K = 12;
  localparam int HW   = W - K;
  localparam int B    = 1 << HW;
  localparam int R    = B - 1;
  localparam int NL   = W + 1;
  localparam int LW   = $clog2(NL);
  localparam int SEQW = 64 - 2 - W - 32;
  localparam bit MIN  = 1'b0;
  localparam logic [1:0] OP_QUERY = 0, OP_UPDATE = 2;
  typedef struct packed {
    logic [1:0]      op;
    logic [SEQW-1:0] seq;
    logic [W-1:0]    key;
    logic [31:0]     value;
  } word_t;
  function automatic logic [31:0] combine(input logic [31:0] x, input logic [31:0] y);
    if (MIN) return (x < y) ? x : y;
    else     return (x > y) ? x : y;
  endfunction
  localparam logic [31:0] ID = MIN ? '1 : '0;
endpackage

module salsa_datapath import salsa_pkg::*; (
  input  logic               clk, rst,
  input  logic               in_valid,
  input  word_t              in_word,
  output logic               out_valid,
  output word_t              out_word,
  output logic [B-1:0][31:0] bank_stores,
  output logic [31:0]        root_stores
);
`ifndef SYNTHESIS
  initial begin
    if (HW < 2)    $fatal(1, "need W - K >= 2 (at least 4 banks)");
    if (SEQW < 1)  $fatal(1, "key too wide for the 64-bit word");
  end
`endif

  logic iss_valid, iss_update; logic [31:0] data;
  logic [NL-1:0][1:0][W:0] cand; logic [NL-1:0][1:0] cval, isp;
  logic [1:0][B-1:0] ren, wen; logic [1:0][B-1:0][K-1:0] addr; logic [1:0][B-1:0][LW-1:0] lvl;

  salsa_segment_pull_top #(.W(W), .K(K), .B(B), .DW(32)) u_fe (
    .clk, .rst_n(!rst),
    .q_valid(in_valid), .q_is_update(in_word.op == OP_UPDATE),
    .q_idx(in_word.key), .q_data(in_word.value),
    .iss_valid, .iss_update, .iss_cand(cand), .iss_cval(cval), .iss_isp(isp),
    .iss_ren(ren), .iss_wen(wen), .iss_addr(addr), .iss_lvl(lvl), .iss_data(data));

  word_t w0;
  always_ff @(posedge clk) w0 <= in_word;

  logic v3, u3, v4, u4, u5; logic [31:0] d3, res4; word_t w3, w4;
  logic [NL-1:0][1:0][W:0] cand3; logic [NL-1:0][1:0] cval3, isp3;
  logic [NL-1:0][31:0] p4, p5; logic [NL-1:0][W:0] path4, path5;

  logic [1:0][B-1:0][31:0] q; logic [1:0][B-1:0] ren3; logic [1:0][B-1:0][LW-1:0] lvl3;
  logic [1:0][B-1:0] wen4;
  for (genvar p = 0; p < 2; p++) begin : g_half
    for (genvar b = 0; b < B; b++) begin : g_bank
      (* ram_style = "block" *) logic [31:0] mem [1 << K];
      logic wen3; logic [K-1:0] wa3, wa4; logic [LW-1:0] wl4;
      initial for (int i = 0; i < (1 << K); i++) mem[i] = ID;
      always_ff @(posedge clk) begin
        if (ren[p][b])  q[p][b] <= mem[addr[p][b]];
        if (wen4[p][b]) mem[wa4] <= p4[wl4];
        ren3[p][b] <= ren[p][b]; lvl3[p][b] <= lvl[p][b];
        wen3 <= wen[p][b];       wa3 <= addr[p][b];
        wen4[p][b] <= wen3;      wa4 <= wa3;     wl4 <= lvl3[p][b];
      end
    end
  end

  always_ff @(posedge clk)
    for (int b = 0; b < B; b++)
      if (rst) bank_stores[b] <= 0;
      else     bank_stores[b] <= bank_stores[b] + wen4[0][b] + wen4[1][b];

  logic [R:1][31:0] root; logic [NL-1:0][1:0][31:0] rq3;
  always_ff @(posedge clk) begin
    for (int L = 0; L < NL; L++)
      for (int p = 0; p < 2; p++)
        rq3[L][p] <= (L < HW && cand[L][p][HW-1:0] != 0) ? root[int'(cand[L][p][HW-1:0])] : ID;
    if (rst) begin root <= {R{ID}}; root_stores <= 0; end
    else if (v4 && u4) begin
      for (int L = 0; L < HW; L++) root[int'(path4[L][HW-1:0])] <= p4[L];
      root_stores <= root_stores + 1;
    end
  end

  always_ff @(posedge clk) begin
    v3 <= !rst && iss_valid; u3 <= iss_update; d3 <= data;
    cand3 <= cand; cval3 <= cval; isp3 <= isp; w3 <= w0;
  end

  logic [NL-1:0][1:0][31:0] fv; logic [NL-1:0][31:0] p3; logic [NL-1:0][W:0] path3; logic [31:0] res3;
  always_comb
    for (int L = 0; L < NL; L++)
      for (int p = 0; p < 2; p++) begin
        fv[L][p] = rq3[L][p];
        if (L >= HW)
          for (int b = 0; b < B; b++)
            if (ren3[p][b] && lvl3[p][b] == LW'(L)) fv[L][p] = q[p][b];
        if      (v4 && u4 && path4[L] == cand3[L][p]) fv[L][p] = p4[L];
        else if (u5       && path5[L] == cand3[L][p]) fv[L][p] = p5[L];
      end

  always_comb begin
    logic [NL-1:0][31:0] e, nxt;
    for (int L = 0; L < NL; L++) path3[L] = isp3[L][1] ? cand3[L][1] : cand3[L][0];
    e[0] = d3;
    for (int k = 1; k < NL; k++) e[k] = isp3[W-k+1][1] ? fv[W-k+1][0] : fv[W-k+1][1];
    for (int d = 1; d < NL; d <<= 1) begin
      nxt = e;
      for (int k = d; k < NL; k++) nxt[k] = combine(e[k], e[k-d]);
      e = nxt;
    end
    for (int k = 0; k < NL; k++) p3[W-k] = e[k];
    res3 = ID;
    for (int L = 0; L < NL; L++)
      for (int p = 0; p < 2; p++) if (cval3[L][p]) res3 = combine(res3, fv[L][p]);
  end

  always_ff @(posedge clk) begin
    v4 <= !rst && v3; u4 <= u3; p4 <= p3; path4 <= path3; res4 <= res3; w4 <= w3;
    u5 <= !rst && v4 && u4; p5 <= p4; path5 <= path4;
  end

  always_comb begin
    out_valid = v4;
    out_word  = w4;
    if (w4.op != OP_UPDATE) out_word.value = res4;
  end
endmodule

module salsa import salsa_pkg::*; #(
  parameter int DEPTH = 4
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
`ifndef SYNTHESIS
  initial if (B > 16) $fatal(1, "BANK_STORES has 16 slots (0x40..0x7C); widen the AXI-Lite map for B > 16");
`endif

  logic rst;
  assign rst = !aresetn;

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

  logic start; logic [31:0] run_len, pushed;
  logic [64:0] fifo [DEPTH];
  logic [$clog2(DEPTH)-1:0] wp, rp;
  logic free, load, bypass, push, last;
  assign free   = !m_axis_tvalid || m_axis_tready;
  assign load   = free && count != 0;
  assign bypass = free && count == 0 && out_valid;
  assign push   = out_valid && !bypass;
  assign last   = pushed == run_len - 1;
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
        default: s_axi_rdata <= (s_axi_araddr[7:6] == 1 && 32'(s_axi_araddr[5:2]) < B)
                                ? bank_stores[s_axi_araddr[5:2]] : 0;
      endcase
  end

  wire unused = ^{s_axis_tlast, s_axi_awprot, s_axi_arprot, s_axi_wstrb};
endmodule
