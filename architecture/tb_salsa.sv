// System test: random queries and updates over AXI-Stream with random back-pressure,
// checked against a software Fenwick tree (prefix sums over keys 1 .. 2^W - 1).
// Hot-key bursts make consecutive ops share nodes, so the write-lag forwarding is exercised.
module tb_system;
  import salsa_pkg::*;
  logic aclk = 0, aresetn = 0;
  always #5 aclk = ~aclk;

  logic [63:0] s_tdata; logic s_tvalid = 0, s_tready;
  logic [63:0] m_tdata; logic m_tvalid, m_tready = 0, m_tlast;

  salsa #(.DEPTH(4)) dut (
    .aclk, .aresetn,
    .s_axis_tdata(s_tdata), .s_axis_tvalid(s_tvalid), .s_axis_tready(s_tready), .s_axis_tlast(1'b0),
    .m_axis_tdata(m_tdata), .m_axis_tvalid(m_tvalid), .m_axis_tready(m_tready), .m_axis_tlast(m_tlast),
    .s_axi_awaddr('0), .s_axi_awprot('0), .s_axi_awvalid(1'b0), .s_axi_awready(),
    .s_axi_wdata('0), .s_axi_wstrb('0), .s_axi_wvalid(1'b0), .s_axi_wready(),
    .s_axi_bresp(), .s_axi_bvalid(), .s_axi_bready(1'b1),
    .s_axi_araddr('0), .s_axi_arprot('0), .s_axi_arvalid(1'b0), .s_axi_arready(),
    .s_axi_rdata(), .s_axi_rresp(), .s_axi_rvalid(), .s_axi_rready(1'b1));

  localparam int N = 1 << W;
  int unsigned val [N];                 // the array the tree represents
  word_t expected [$];                  // results in issue order
  int sent = 0, got = 0, errors = 0, updates = 0, own_updates = 0;
  localparam int OPS = 200000;

  function automatic int unsigned prefix(int p);
    int unsigned s = 0;
    for (int i = 1; i <= p; i++) s += val[i];
    return s;
  endfunction

  // pick a key: half the time from a small hot window, so neighbouring ops share nodes
  int hot_base;
  function automatic int pick_key();
    if ($urandom % 2) return 1 + (hot_base + $urandom % 8) % (N - 1);
    return 1 + $urandom % (N - 1);
  endfunction

  word_t w;
  initial begin
    for (int i = 0; i < N; i++) val[i] = 0;
    repeat (4) @(posedge aclk); aresetn <= 1;
    hot_base = $urandom % N;
    while (sent < OPS) begin
      @(posedge aclk);
      if (s_tvalid && s_tready) sent++;           // previous word accepted
      if (!s_tvalid || s_tready) begin
        if (sent < OPS && ($urandom % 8 != 0)) begin
          if ($urandom % 64 == 0) hot_base = $urandom % N;
          w.op    = ($urandom % 2) ? OP_UPDATE : (($urandom % 8 == 0) ? 2'd1 : OP_QUERY); // some reserved op 1
          w.seq   = SEQW'(sent);
          w.key   = W'(pick_key());
          w.value = $urandom;
          // the model, in issue order
          if (w.op == OP_UPDATE) begin
            val[w.key] += w.value; updates++;
            expected.push_back(w);                // update echoes its word
          end else begin
            word_t e = w; e.value = prefix(w.key);
            expected.push_back(e);
          end
          s_tdata  <= w;
          s_tvalid <= 1;
        end else s_tvalid <= 0;
      end
    end
    @(posedge aclk); s_tvalid <= 0;
    wait (got == OPS);
    begin
      int unsigned total = dut.u_dp.root_stores;
      for (int b = 0; b < B; b++) total += dut.u_dp.bank_stores[b];
      if (total != updates) begin errors++; $display("own-node counters %0d, updates %0d", total, updates); end
    end
    $display("W=%0d K=%0d B=%0d: %0d ops, %0d updates, %0d errors: %s", W, K, B, OPS, updates, errors, errors ? "FAIL" : "PASS");
    $finish;
  end

  // consumer with random back-pressure; check every result in order
  always @(posedge aclk) begin
    m_tready <= ($urandom % 4 != 0);
    if (m_tvalid && m_tready) begin
      word_t r, e;
      r = m_tdata; e = expected.pop_front(); got++;
      if (r !== e) begin
        errors++;
        if (errors < 6) $display("result %0d: op %0d key %0d got %0d want %0d (seq %0d/%0d)",
                                 got, r.op, r.key, r.value, e.value, r.seq, e.seq);
      end
    end
  end
endmodule
