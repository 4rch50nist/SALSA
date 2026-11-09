`default_nettype none

module salsa_segment_pull_top #(
    parameter int unsigned W  = 16,
    parameter int unsigned K  = 12,
    parameter int unsigned B  = 16,
    parameter int unsigned DW = 32
) (
    input  wire  logic                              clk,
    input  wire  logic                              rst_n,
    input  wire  logic                              q_valid,
    input  wire  logic                              q_is_update,
    input  wire  logic [W-1:0]                      q_idx,
    input  wire  logic [DW-1:0]                     q_data,
    output logic                                    iss_valid,
    output logic                                    iss_update,
    output logic [W:0][1:0][W:0]                    iss_cand,
    output logic [W:0][1:0]                         iss_cval,
    output logic [W:0][1:0]                         iss_isp,
    output logic [1:0][B-1:0]                       iss_ren,
    output logic [1:0][B-1:0]                       iss_wen,
    output logic [1:0][B-1:0][K-1:0]                iss_addr,
    output logic [1:0][B-1:0][$clog2(W+1)-1:0]      iss_lvl,
    output logic [DW-1:0]                           iss_data
);
    localparam int unsigned BW = $clog2(B);
    localparam int unsigned HW = W - K;
    localparam int unsigned NL = W + 1;
    localparam int unsigned LW = $clog2(NL);
    localparam int unsigned N  = 1 << W;

`ifndef SYNTHESIS
    initial begin
        if ((1 << BW) != B) $fatal(1, "B must be a power of two");
        if (HW != BW)       $fatal(1, "need W - K == log2(B): one anchor per rotation");
        if (K > B - 2)      $fatal(1, "the signed rotation needs K <= B - 2");
    end
`endif

    function automatic logic [BW-1:0] bank_of(input logic [W:0] n, input int unsigned L);
        logic [BW-1:0] l, a;
        l = BW'(L - HW);
        a = BW'(n >> (L - HW));
        return n[0] ? BW'(l - a) : BW'(l + a);
    endfunction

    function automatic logic [K-1:0] addr_of(input logic [W:0] n, input int unsigned L);
        int unsigned l;
        logic [W:0]  r;
        l = L - HW;
        if (l == 0) return '0;
        r = n & (((W+1)'(1) << l) - 1'b1);
        return K'(((W+1)'(1) << (l - 1)) | (r >> 1));
    endfunction

    logic [NL-1:0][1:0][W:0] c_cand;
    logic [NL-1:0][1:0]      c_cval, c_isp;
    always_comb begin
        c_cand = '0; c_cval = '0; c_isp = '0;
        for (int L = 0; L < NL; L++) begin
            automatic logic [W+1:0] lh   = (W+2)'(q_idx)  + (W+2)'(N);
            automatic logic [W+1:0] rh   = (W+2)'(q_data) + (W+2)'(N);
            automatic logic [W+1:0] lk   = (lh + ((W+2)'(1) << (W - L)) - 1'b1) >> (W - L);
            automatic logic [W+1:0] rk   = rh >> (W - L);
            automatic logic [W:0]   path = (W+1)'(lh >> (W - L));
            automatic logic [W:0]   sib  = path ^ (W+1)'(1);
            if (q_is_update) begin
                c_cand[L][path[0]] = path; c_cval[L][path[0]] = 1'b1; c_isp[L][path[0]] = 1'b1;
                if (L > 0) begin c_cand[L][!path[0]] = sib; c_cval[L][!path[0]] = 1'b1; end
            end else if (lk < rk) begin
                c_cand[L][1] = (W+1)'(lk);        c_cval[L][1] = lk[0];
                c_cand[L][0] = (W+1)'(rk - 1'b1); c_cval[L][0] = rk[0];
            end
        end
    end

    logic                    tv, tu;
    logic [NL-1:0][1:0][W:0] t_cand;
    logic [NL-1:0][1:0]      t_cval, t_isp;
    logic [DW-1:0]           t_d;
    always_ff @(posedge clk) begin
        if (!rst_n) tv <= 1'b0; else tv <= q_valid;
        t_cval <= (rst_n && q_valid) ? c_cval : '0;
        t_cand <= c_cand;
        t_isp  <= c_isp;
        tu     <= q_is_update;
        t_d    <= q_data;
    end

    logic [1:0][B-1:0]          x_ren, x_wen;
    logic [1:0][B-1:0][K-1:0]   x_addr;
    logic [1:0][B-1:0][LW-1:0]  x_lvl;
    always_comb begin
        x_ren = '0; x_wen = '0; x_addr = '0; x_lvl = '0;
        for (int unsigned p = 0; p < 2; p++)
            for (int unsigned b = 0; b < B; b++)
                for (int unsigned L = HW; L < NL; L++)
                    if (t_cval[L][p] && bank_of(t_cand[L][p], L) == BW'(b)) begin
                        x_ren [p][b] = !(tu && t_isp[L][p]);
                        x_wen [p][b] =   tu && t_isp[L][p];
                        x_addr[p][b] = addr_of(t_cand[L][p], L);
                        x_lvl [p][b] = LW'(L);
                    end
    end

    assign iss_valid  = tv;
    assign iss_update = tu;
    assign iss_cand   = t_cand;
    assign iss_cval   = t_cval;
    assign iss_isp    = t_isp;
    assign iss_ren    = x_ren;
    assign iss_wen    = x_wen;
    assign iss_addr   = x_addr;
    assign iss_lvl    = x_lvl;
    assign iss_data   = t_d;
endmodule

`default_nettype wire
