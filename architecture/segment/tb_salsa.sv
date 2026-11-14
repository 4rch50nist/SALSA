`timescale 1ns/1ps
module tb_salsa;
  import salsa_pkg::*;

  localparam int N = 1 << W;

  logic clk = 0, rst = 1;
  always #5 clk = ~clk;

  logic in_valid = 0; word_t in_word = '0;
  logic out_valid; word_t out_word;
  logic [B-1:0][31:0] bank_stores; logic [31:0] root_stores;

  salsa_datapath dut (.*);

  logic [31:0] gold [1:2*N-1];
  function automatic logic [31:0] op2(logic [31:0] x, logic [31:0] y); return combine(x, y); endfunction
  task automatic g_update(int i, logic [31:0] v);
    int n; n = N + i; gold[n] = v; n >>= 1;
    while (n >= 1) begin gold[n] = op2(gold[2*n], gold[2*n+1]); n >>= 1; end
  endtask
  function automatic logic [31:0] g_query(int l, int r);
    logic [31:0] acc; acc = ID; l += N; r += N;
    while (l < r) begin
      if (l & 1) begin acc = op2(acc, gold[l]); l++; end
      if (r & 1) begin r--; acc = op2(acc, gold[r]); end
      l >>= 1; r >>= 1;
    end
    return acc;
  endfunction

  logic [31:0] exp_q[$]; int exp_seq[$];
  int errors = 0, checked = 0, seqn = 0;
  always @(posedge clk)
    if (out_valid && out_word.op == OP_QUERY) begin
      logic [31:0] e; int s;
      e = exp_q.pop_front(); s = exp_seq.pop_front();
      checked++;
      if (out_word.value !== e || out_word.seq !== SEQW'(s)) begin
        errors++;
        if (errors <= 10) $display("MISMATCH seq %0d: got %0d expected %0d", s, out_word.value, e);
      end
    end

  task automatic issue(logic [1:0] op, int key, logic [31:0] value);
    word_t w;
    w.op = op; w.seq = SEQW'(seqn); w.key = W'(key); w.value = value;
    in_word = w;
    if (op == OP_UPDATE) g_update(key, value);
    else begin exp_q.push_back(g_query(key, int'(value))); exp_seq.push_back(seqn); end
    seqn++;
    in_valid = 1;
    @(posedge clk); #1;
  endtask

  task automatic run(string kind, int nops);
    int mid; mid = N / 2;
    for (int t = 0; t < nops; t++) begin
      int u, l, r, base, d;
      u = $urandom_range(99);
      case (kind)
        "random": begin
          if (u < 60) issue(OP_UPDATE, $urandom_range(N-1), $urandom_range(999));
          else begin l = $urandom_range(N-1); r = $urandom_range(N, l+1); issue(OP_QUERY, l, 32'(r)); end
        end
        "neighbours": begin
          base = $urandom_range(N-9);
          if (u < 75) issue(OP_UPDATE, base + $urandom_range(7), $urandom_range(999));
          else        issue(OP_QUERY, base, 32'(base + 8));
        end
        default: begin
          mid = mid + $urandom_range(4) - 2;
          if (mid < 64) mid = 64; if (mid > N - 65) mid = N - 65;
          if (u < 65) issue(OP_UPDATE, mid + $urandom_range(32) - 16,
                            ($urandom_range(1) == 1) ? 32'($urandom_range(999)) : ID);
          else if (u < 85) begin d = $urandom_range(47, 1); issue(OP_QUERY, mid - d, 32'(mid + d + 1)); end
          else issue(OP_QUERY, 0, 32'(N));
        end
      endcase
    end
  endtask

  initial begin
    for (int n = 1; n < 2*N; n++) gold[n] = ID;
    repeat (3) @(posedge clk); rst = 0; #1;
    run("random", 20000);
    run("neighbours", 20000);
    run("itch", 20000);
    in_valid = 0;
    repeat (8) @(posedge clk);
    $display("%s tree: %0d queries checked, %0d errors, %0d updates, exp queue left %0d",
             MIN ? "min" : "max", checked, errors, root_stores, exp_q.size());
    if (errors == 0 && exp_q.size() == 0) $display("PASS"); else $display("FAIL");
    $finish;
  end
endmodule
