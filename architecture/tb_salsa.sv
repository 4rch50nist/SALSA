// Testbench, through the AXI interfaces only (as PYNQ + DMA will drive it):
//   1. load a Fenwick tree with 65,535 stores; SALSA places every value
//   2. check every bank got 4,095 stores and the roots 15
//   3. queries: each result must equal a[1] + ... + a[key] (computed from the
//      raw data, not the tree); once at full rate, once with backpressure
// Drive and sample on the FALLING edge to avoid races with the design.
`timescale 1ns/1ps
module tb;
  import salsa_pkg::*;
  logic clk = 0; always #5 clk = ~clk;
  logic rstn = 0;

  logic [63:0] sd = 0; logic sv = 0, sr;
  logic [63:0] md;     logic mv, mr = 1, ml;
  logic [7:0]  awa = 0, ara = 0; logic awv = 0, awr, wv = 0, wr_, bv, arv = 0, arr, rv;
  logic [31:0] wd = 0, rd; logic [1:0] br, rr;

  salsa dut (.aclk(clk), .aresetn(rstn),
    .s_axis_tdata(sd), .s_axis_tvalid(sv), .s_axis_tready(sr), .s_axis_tlast(1'b0),
    .m_axis_tdata(md), .m_axis_tvalid(mv), .m_axis_tready(mr), .m_axis_tlast(ml),
    .s_axi_awaddr(awa), .s_axi_awprot(3'd0), .s_axi_awvalid(awv), .s_axi_awready(awr),
    .s_axi_wdata(wd), .s_axi_wstrb(4'hF), .s_axi_wvalid(wv), .s_axi_wready(wr_),
    .s_axi_bresp(br), .s_axi_bvalid(bv), .s_axi_bready(1'b1),
    .s_axi_araddr(ara), .s_axi_arprot(3'd0), .s_axi_arvalid(arv), .s_axi_arready(arr),
    .s_axi_rdata(rd), .s_axi_rresp(rr), .s_axi_rvalid(rv), .s_axi_rready(1'b1));

  task automatic reg_write(input logic [7:0] a, input logic [31:0] d);
    @(negedge clk); awa = a; wd = d; awv = 1; wv = 1;
    while (!awr) @(negedge clk);
    @(negedge clk); awv = 0; wv = 0;
    while (!bv) @(negedge clk);
    @(negedge clk);
  endtask

  task automatic reg_read(input logic [7:0] a, output logic [31:0] d);
    @(negedge clk); ara = a; arv = 1;
    while (!arr) @(negedge clk);
    @(negedge clk); arv = 0;
    while (!rv) @(negedge clk);
    d = rd; @(negedge clk);
  endtask

  // data and golden
  int unsigned a[65536], tree[65536], prefix[65536], hw_tree[65536];   // hw_tree: what the hardware holds
  word_t expect_q[$];
  int errors = 0, got = 0, n_run = 0; bit backpressure = 0;

  // DMA receive side: check every result and tlast
  always @(posedge clk) begin
    if (mv && mr) begin
      word_t r, e; r = word_t'(md);
      e = expect_q.pop_front();
      if (r != e) begin errors++; if (errors < 5) $display("ERROR key %0d: got %0d want %0d", e.key, r.value, e.value); end
      if (ml != (got == n_run - 1)) begin errors++; $display("ERROR: tlast at %0d", got); end
      got++;
    end
    mr <= !backpressure || ($urandom % 3 != 0);
  end

  // one run: send words, wait for DONE
  task automatic run(input word_t words[$], input bit bp);
    logic [31:0] st;
    backpressure = bp; n_run = words.size(); got = 0;
    reg_write(8'h08, n_run);
    reg_write(8'h00, 1);
    @(negedge clk);
    foreach (words[i]) begin
      sd = 64'(words[i]); sv = 1;
      while (!sr) @(negedge clk);
      @(negedge clk);
    end
    sv = 0;
    do reg_read(8'h04, st); while (!st[0]);
    if (got != n_run) begin errors++; $display("ERROR: got %0d of %0d", got, n_run); end
  endtask

  function automatic word_t mk(input logic [1:0] op, input int i, input int key, input int unsigned v);
    word_t w; w.op = op; w.seq = 14'(i); w.key = 16'(key); w.value = v; return w;
  endfunction

  initial begin
    word_t words[$]; logic [31:0] v, cyc, lat; int k;

    for (int i = 1; i < 65536; i++) begin a[i] = $urandom % 1000; prefix[i] = prefix[i-1] + a[i]; end
    tree = a;
    for (int i = 1; i < 65536; i++) if (i + (i & -i) < 65536) tree[i + (i & -i)] += tree[i];
    hw_tree = tree;

    repeat (5) @(posedge clk); rstn = 1;

    // 1. load
    for (int i = 1; i < 65536; i++) begin
      words.push_back(mk(OP_STORE, i, i, tree[i]));
      expect_q.push_back(mk(OP_STORE, i, i, tree[i]));
    end
    run(words, 1);

    // 2. balance
    for (int b = 0; b < 16; b++) begin
      reg_read(8'h40 + 8'(4*b), v);
      if (v != 4095) begin errors++; $display("ERROR: bank %0d has %0d", b, v); end
    end
    reg_read(8'h80, v);
    if (v != 15) begin errors++; $display("ERROR: roots %0d", v); end
    $display("load: 65535 stores, every bank 4095, roots 15");

    // 3. queries at full rate
    words.delete();
    for (int i = 0; i < 20000; i++) begin
      k = (i == 0) ? 56086 : $urandom % 65536;
      words.push_back(mk(OP_QUERY, i, k, 0));
      expect_q.push_back(mk(OP_QUERY, i, k, prefix[k]));
    end
    run(words, 0);
    reg_read(8'h0C, cyc); reg_read(8'h18, lat);
    $display("queries: 20000 in %0d cycles (%0.3f per request), latency %0d", cyc, real'(cyc)/20000, lat);

    // 4. queries with backpressure
    words.delete();
    for (int i = 0; i < 20000; i++) begin
      k = $urandom % 65536;
      words.push_back(mk(OP_QUERY, i, k, 0));
      expect_q.push_back(mk(OP_QUERY, i, k, prefix[k]));
    end
    run(words, 1);
    $display("queries with backpressure: 20000 checked");

    // 5. read-after-write: stores and queries interleaved, each query right behind a
    //    store to a node on its chain (roots included); golden from a model tree
    //    updated in stream order
    for (int bp = 0; bp < 2; bp++) begin
      int unsigned t[65536]; int x, q, s; int unsigned nv;
      t = tree;
      for (int i = 1; i < 65536; i++) if (i + (i & -i) < 65536) ; // (tree already built)
      // the hardware still holds the loaded tree plus earlier phases' stores; resync the model
      words.delete();
      for (int i = 0; i < 20000; i += 2) begin
        k  = (i % 64 == 0) ? (($urandom % 15) + 1) << 12 : ($urandom % 65535) + 1;   // some roots
        nv = $urandom;
        words.push_back(mk(OP_STORE, i, k, nv));
        expect_q.push_back(mk(OP_STORE, i, k, nv));
        hw_tree[k] = nv;
        q = ((k & 15) == 0) ? (k | ($urandom % 16)) : k;
        s = 0; x = q;
        while (x > 0) begin s += hw_tree[x]; x -= x & -x; end
        words.push_back(mk(OP_QUERY, i + 1, q, 0));
        expect_q.push_back(mk(OP_QUERY, i + 1, q, s));
      end
      run(words, bp);
      $display("read-after-write%s: 10000 stores + 10000 queries interleaved, checked", bp ? " with backpressure" : "");
    end

    $display("%s (%0d errors)", errors == 0 ? "PASS" : "FAIL", errors);
    $finish;
  end
endmodule
