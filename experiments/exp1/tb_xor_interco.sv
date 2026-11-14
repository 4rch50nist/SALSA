module tb;
  localparam int NIN = 16, NOUT = 16, AW = 32, DW = 32;
  logic clk = 0, rst_n = 0;
  always #5 clk = ~clk;

  logic [NIN-1:0] req, gnt, vld; logic [NIN-1:0][AW-1:0] add; logic [NIN-1:0][DW-1:0] rdata;
  logic [NOUT-1:0] mreq; logic [NOUT-1:0][11:0] madd; logic [NOUT-1:0][DW-1:0] mrdata;
  logic [NOUT-1:0] mwen; logic [NOUT-1:0][DW-1:0] mwdata; logic [NOUT-1:0][3:0] mbe;

  tcdm_interconnect #(.NumIn(NIN), .NumOut(NOUT), .AddrWidth(AW), .DataWidth(DW), .AddrMemWidth(12),
                      .WriteRespOn(1), .RespLat(1), .Topology(tcdm_interconnect_pkg::LIC)) dut (
    .clk_i(clk), .rst_ni(rst_n), .req_i(req), .add_i(add), .wen_i('0), .wdata_i('0), .be_i('1),
    .gnt_o(gnt), .vld_o(vld), .rdata_o(rdata),
    .req_o(mreq), .gnt_i('1), .add_o(madd), .wen_o(mwen), .wdata_o(mwdata), .be_o(mbe), .rdata_i(mrdata));

  always_ff @(posedge clk) for (int k = 0; k < NOUT; k++) mrdata[k] <= {20'd0, madd[k]};

  function automatic int nu2(int v); int n = 0; while (((v >> n) & 1) == 0) n++; return n; endfunction
  function automatic int bank_of(string place, int x);
    if (place == "xor") return (x ^ (x >> 4) ^ (x >> 8) ^ (x >> 12)) & 15;
    return (nu2(x & 12'hfff) + (x >> 12)) % 16;
  endfunction
  function automatic int addr_of(string place, int x);
    if (place == "xor") return x >> 4;
    return x & 12'hfff;
  endfunction

  typedef struct { int qid; logic [AW-1:0] a; } ent_t;
  ent_t fifo [NIN][$];
  int   inflight [NIN][$];
  int   remaining [int], arrival [int], plen [int];
  string place, mode; real lambda; int nq, fd, issued, done, cycle, qid; bit xregs; string outf;

  function automatic bit idle();
    for (int j = 0; j < NIN; j++) if (fifo[j].size() || inflight[j].size()) return 0;
    return 1;
  endfunction

  task automatic inject();
    int key, v, i; key = 1 + ($urandom % 65535); v = key; i = 0;
    while (v != 0) begin
      if ((place == "xor" && !xregs) || (v & 12'hfff) != 0) begin
        ent_t e; e.qid = qid;
        e.a = {AW'(addr_of(place, v)) << 6} | {AW'(bank_of(place, v)) << 2};
        fifo[i].push_back(e); i++;
      end
      v = v - (v & -v);
    end
    arrival[qid] = cycle; plen[qid] = i;
    if (i == 0) begin $fdisplay(fd, "%0d %0d", 4, 0); done++; end
    else remaining[qid] = i;
    qid++; issued++;
  endtask

  initial begin
    if (!$value$plusargs("place=%s", place)) place = "xor";
    if (!$value$plusargs("mode=%s", mode)) mode = "closed";
    if (!$value$plusargs("lambda=%f", lambda)) lambda = 0.5;
    if (!$value$plusargs("n=%d", nq)) nq = 100000;
    xregs = $test$plusargs("xregs");
    if (!$value$plusargs("out=%s", outf)) outf = $sformatf("lat_%s_%s.txt", place, mode);
    fd = $fopen(outf, "w");
    issued = 0; done = 0; cycle = 0; qid = 0;
    req = '0; add = '0;
    repeat (3) @(posedge clk); rst_n = 1;
    while (done < nq) begin
      @(negedge clk);

      if (issued < nq) begin
        if (mode == "closed") begin if (idle()) inject(); end
        else if (($urandom % 1000000) < int'(lambda * 1000000)) inject();
      end

      for (int j = 0; j < NIN; j++) begin
        req[j] = fifo[j].size() != 0;
        add[j] = req[j] ? fifo[j][0].a : '0;
      end
      @(posedge clk);
      for (int j = 0; j < NIN; j++) begin
        if (vld[j]) begin
          automatic int q = inflight[j].pop_front();
          remaining[q]--;
          if (remaining[q] == 0) begin $fdisplay(fd, "%0d %0d", cycle - arrival[q] + 1 + 2, plen[q]); done++; remaining.delete(q); end
        end
        if (req[j] && gnt[j]) begin automatic ent_t e = fifo[j].pop_front(); inflight[j].push_back(e.qid); end
      end
      cycle++;
    end
    $fclose(fd);
    $display("%s %s: %0d queries in %0d cycles", place, mode, done, cycle);
    $finish;
  end
endmodule
