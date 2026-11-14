package salsa_pkg;
  localparam int W    = 16, K = 12;
  localparam int HW   = W - K;
  localparam int B    = 1 << HW;
  localparam int R    = B - 1;
  localparam int SEQW = 64 - 2 - W - 32;
  localparam logic [1:0] OP_QUERY = 0, OP_UPDATE = 2;
  typedef struct packed {
    logic [1:0]      op;
    logic [SEQW-1:0] seq;
    logic [W-1:0]    key;
    logic [31:0]     value;
  } word_t;
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
  localparam int GS = 4, NG = B / GS;

`ifndef SYNTHESIS
  initial begin
    if (HW < 2)    $fatal(1, "need W - K >= 2 (at least 4 banks)");
    if (SEQW < 1)  $fatal(1, "key too wide for the 64-bit word");
  end
`endif

  logic iss_valid, iss_update, own_root; logic [R-1:0] rupd; logic [B-1:0] own;
  logic [B-1:0] en; logic [B*K-1:0] set; logic [HW-1:0] lane, hi; logic [31:0] data;

  salsa_fen_pull_top #(.W(W), .K(K), .B(B), .DW(32)) u_fe (
    .clk, .rst_n(!rst),
    .q_valid(in_valid), .q_is_update(in_word.op == OP_UPDATE),
    .q_idx(in_word.key), .q_data(in_word.value),
    .iss_valid, .iss_update, .iss_root_upd(rupd), .iss_own_en(own), .iss_own_root(own_root),
    .iss_bank_en(en), .iss_bank_set(set),
    .iss_reg_en(lane), .iss_hi(hi), .iss_data(data));

  word_t w0;
  always_ff @(posedge clk) w0 <= in_word;

  logic query, update;
  assign update = iss_valid &&  iss_update;
  assign query  = iss_valid && !iss_update;

  logic [31:0] dat3, dat4, dat5;
  always_ff @(posedge clk) begin dat3 <= data; dat4 <= dat3; dat5 <= dat4; end
  logic [B-1:0] en1;
  logic [B-1:0] qh1, qh2;

  logic [B-1:0][31:0] rd;
  for (genvar b = 0; b < B; b++) begin : g_bank
    (* ram_style = "block" *) logic [31:0] mem [1 << K];
    logic [31:0] q, qreg, xreg, c;
    logic [K-1:0] s3, s4, s5;
    logic u3, u4, u5, h1, h2, ren;
    initial for (int i = 0; i < (1 << K); i++) mem[i] = 0;
    assign ren = (query || update) && en[b];
    assign rd[b] = q;
    assign h1 = u4 && (s4 == s3);
    assign h2 = u5 && (s5 == s3);
    assign c  = (h1 ? dat4 : 32'd0) + (h2 ? dat5 : 32'd0);
    assign qh1[b] = en1[b] && h1;
    assign qh2[b] = en1[b] && h2;
    always_ff @(posedge clk) begin
      if (ren) q <= mem[set[b*K +: K]];
      if (u4)  mem[s4] <= qreg + xreg;
      qreg <= q;
      xreg <= dat3 + c;
      s3 <= set[b*K +: K]; u3 <= update && en[b];
      s4 <= s3;            u4 <= u3;
      s5 <= s4;            u5 <= u4;
      if (rst) bank_stores[b] <= 0; else if (update && own[b]) bank_stores[b] <= bank_stores[b] + 1;
    end
  end

  logic [R-1:0][31:0] root; logic [HW-1:0][31:0] rsel;
  always_comb
    for (int j = 0; j < HW; j++) begin
      logic [HW-1:0] idx;
      idx = (hi & ~HW'((1 << j) - 1)) - 1'b1;
      rsel[j] = (lane[j] && idx < R) ? root[idx] : 32'd0;
    end
  always_ff @(posedge clk)
    if (rst) begin root <= 0; root_stores <= 0; end
    else begin
      if (update) begin
        for (int h = 0; h < R; h++) if (rupd[h]) root[h] <= root[h] + data;
        if (own_root) root_stores <= root_stores + 1;
      end
    end

  logic v1, v2; word_t x1, x2; logic [31:0] corr4;

  logic [HW-1:0][31:0] rsel1; logic [31:0] rs_c, rs2; logic [NG-1:0][31:0] part, part_c;

  logic [31:0] corr_q;
  assign corr_q = ((|qh1) ? dat4 : 32'd0) + ((|qh2) ? dat5 : 32'd0);

  always_comb
    for (int g = 0; g < NG; g++) begin
      part_c[g] = 0;
      for (int k = 0; k < GS; k++) if (en1[GS*g+k]) part_c[g] += rd[GS*g+k];
    end

  always_comb begin
    rs_c = 0;
    for (int j = 0; j < HW; j++) rs_c += rsel1[j];
  end

  always_ff @(posedge clk) begin
    v1 <= !rst && iss_valid; v2 <= !rst && v1;
    x1 <= w0; en1 <= query ? en : 0; rsel1 <= query ? rsel : '0;
    corr4 <= corr_q;
    x2 <= x1; part <= part_c;        rs2 <= rs_c;
  end

  logic [31:0] sum;
  always_comb begin
    sum = rs2 + corr4;
    for (int g = 0; g < NG; g++) sum += part[g];
    out_valid = v2;
    out_word  = x2;
    if (x2.op != OP_UPDATE) out_word.value = sum;
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
