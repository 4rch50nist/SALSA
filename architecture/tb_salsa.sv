// Exhaustive check of the level-placement front end, against an independent model:
// walk each Fenwick path node by node and place every banked node at
// bank (nu_2(lo) + hi) mod 16, set = lo. Queries: p, p - lsb(p), ... (whole key).
// Updates: p, p + lsb(p), ... within the body (lo), until it overflows into a root.
// Also checks that every path uses each bank at most once.
module tb_fe;
  localparam int W = 16, K = 12, B = 16;
  logic clk = 0, rst_n = 0;
  always #1 clk = ~clk;
  logic q_valid = 0, q_is_update = 0; logic [W-1:0] q_idx = 0;
  logic iss_valid; logic [B-1:0] en; logic [B*K-1:0] set;
  logic [W-K-1:0] reg_en, hi_o; logic [31:0] d;
  salsa_fen_pull_top #(.W(W), .K(K), .B(B), .DW(32))  dut (
    .clk, .rst_n, .q_valid, .q_is_update, .q_idx, .q_data(32'd0),
    .iss_valid, .iss_update(), .iss_root_upd(), .iss_own_en(), .iss_own_root(),
    .iss_bank_en(en), .iss_bank_set(set), .iss_reg_en(reg_en),
    .iss_hi(hi_o), .iss_data(d));

  function automatic int nu2(int x); int v = 0; while ((x & 1) == 0) begin x >>= 1; v++; end return v; endfunction

  int errors = 0, checked = 0;
  task automatic check(input int p, input bit update);
    logic [B-1:0] e_en; logic [K-1:0] e_set [B]; int x, hi, lo, b;
    e_en = '0; for (int i = 0; i < B; i++) e_set[i] = '0;
    hi = p >> K;
    if (update) begin
      for (x = p & ((1 << K) - 1); x != 0 && x < (1 << K); x = x + (x & -x)) begin   // the update path in the body
        b = (nu2(x) + hi) % B;
        if (e_en[b]) begin errors++; $display("model conflict at key %0d", p); end
        e_en[b] = 1; e_set[b] = x[K-1:0];
      end
    end else begin
      x = p;
      while (x != 0) begin                       // the query path, node by node
        lo = x & ((1 << K) - 1);
        if (lo != 0) begin
          b = (nu2(lo) + hi) % B;
          if (e_en[b]) begin errors++; $display("model conflict at key %0d", p); end
          e_en[b] = 1; e_set[b] = lo;
        end
        x = x - (x & -x);
      end
    end
    if (en !== e_en) begin errors++; if (errors < 6) $display("key %0d %s: en %h, want %h", p, update ? "update" : "query", en, e_en); end
    for (int i = 0; i < B; i++)
      if (e_en[i] && set[i*K +: K] !== e_set[i]) begin errors++; if (errors < 6) $display("key %0d bank %0d: set %h, want %h", p, i, set[i*K +: K], e_set[i]); end
    checked++;
  endtask

  initial begin
    repeat (3) @(posedge clk); rst_n = 1;
    for (int up = 0; up < 2; up++)
      for (int p = 1; p < (1 << W); p++) begin
        @(negedge clk); q_valid = 1; q_is_update = up[0]; q_idx = p[W-1:0];
        @(posedge clk); #0.5;                    // tag register loaded: outputs valid now
        check(p, up[0]);
      end
    $display("front end, level placement: %0d checks (every key as query and as update), %0d errors: %s",
             checked, errors, errors ? "FAIL" : "PASS");
    $finish;
  end
endmodule
