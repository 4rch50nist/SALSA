`default_nettype none

module salsa_fen_pull_top #(
    parameter int unsigned W  = 16,
    parameter int unsigned K  = 12,
    parameter int unsigned B  = 16,
    parameter int unsigned DW = 32
) (
    input  wire  logic                  clk,
    input  wire  logic                  rst_n,
    input  wire  logic                  q_valid,
    input  wire  logic                  q_is_update,
    input  wire  logic [W-1:0]          q_idx,
    input  wire  logic [DW-1:0]         q_data,
    output logic                        iss_valid,
    output logic                        iss_update,
    output logic [(1 << (W-K))-2:0]     iss_root_upd,
    output logic [B-1:0]                iss_own_en,
    output logic                        iss_own_root,
    output logic [B-1:0]                iss_bank_en,
    output logic [B*K-1:0]              iss_bank_set,
    output logic [W-K-1:0]              iss_reg_en,
    output logic [W-K-1:0]              iss_hi,
    output logic [DW-1:0]               iss_data
);
    localparam int unsigned BW = $clog2(B);
    localparam int unsigned HW = W - K;
    localparam int unsigned CW = $clog2(K + 1);
    localparam int unsigned R  = (1 << HW) - 1;

`ifndef SYNTHESIS
    initial begin
        if ((1 << BW) != B) $fatal(1, "B must be a power of two");
        if (K > B)          $fatal(1, "a chain has up to K banked nodes; need K <= B");
        if (HW != BW)       $fatal(1, "need W - K == log2(B) for an injective, balanced map");
    end
`endif

    function automatic logic [BW-1:0] g(input logic [HW-1:0] h);
        return BW'(h);
    endfunction

    function automatic logic [BW-1:0] rank_at(input logic [BW-1:0] b, input logic [BW-1:0] c);
        return b - c;
    endfunction

    logic          iv, iu;
    logic [W-1:0]  ix;
    logic [DW-1:0] id;
    assign iv = q_valid && rst_n;
    assign iu = q_is_update;
    assign ix = q_idx;
    assign id = q_data;

    wire [HW-1:0] i_hi = ix[W-1:K];
    wire [K-1:0]  i_lo = ix[K-1:0];
    wire          i_z  = (i_lo == '0);

    wire [BW-1:0] c_c  = g(i_hi);
    wire [HW-1:0] c_rv = i_hi;

    logic [R-1:0] c_ru;
    always_comb begin
        c_ru = '0;
        for (int j = 0; j < HW; j++) begin
            logic [HW-1:0] node;
            logic          below, ok;
            node  = (i_hi & ~HW'((2 << j) - 1)) | HW'(1 << j);
            below = (i_hi & HW'((1 << j) - 1)) != '0;
            ok    = !i_z ? !i_hi[j] : (i_hi[j] ? !below : below);
            if (ok) c_ru[node - 1'b1] = 1'b1;
        end
    end

    logic [CW-1:0] c_lv;
    always_comb begin
        c_lv = '0;
        for (int j = K - 1; j >= 0; j--)
            if (i_lo[j]) c_lv = CW'(j);
    end

    logic            tv, tu;
    logic [R-1:0]    t_ru;
    logic [K-1:0]    t_lo;
    logic [CW-1:0]   t_lv;
    logic [BW-1:0]   t_c;
    logic [HW-1:0]   t_rv, t_hi;
    logic [DW-1:0]   t_d;
    always_ff @(posedge clk) begin
        if (!rst_n) tv <= 1'b0; else tv <= iv;
        t_rv <= (iv && !iu) ? c_rv : '0;
        t_ru <= (iv &&  iu) ? c_ru : '0;
        t_lv <= c_lv;
        t_c  <= c_c;
        t_lo <= i_lo;
        t_hi <= i_hi;
        tu   <= iu;
        t_d  <= id;
    end

    wire t_z = (t_lo == '0);

    logic [B-1:0]   x_en, x_own;
    logic [B*K-1:0] x_set;
    always_comb
        for (int unsigned b = 0; b < B; b++) begin
            logic [BW-1:0] l;
            logic          has;
            l   = rank_at(BW'(b), t_c);
            has = 1'b0;
            for (int unsigned j = 0; j < K; j++)
                if (BW'(j) == l) has = t_lo[j];
            x_own[b] = tv && tu && !t_z && (CW'(l) == t_lv);
            if (tu)
                x_en[b] = tv && !t_z && (CW'(l) < CW'(K)) &&
                          ((CW'(l) == t_lv) || (CW'(l) > t_lv && !has));
            else
                x_en[b] = tv && has;
            for (int unsigned j = 0; j < K; j++)
                if (tu)
                    x_set[b*K + j] = (CW'(j) > CW'(l)) ? t_lo[j] : (CW'(j) == CW'(l));
                else
                    x_set[b*K + j] = t_lo[j] && (CW'(j) >= CW'(l));
            if (!x_en[b]) x_set[b*K +: K] = '0;
        end

    assign iss_valid    = tv;
    assign iss_update   = tu;
    assign iss_bank_en  = x_en;
    assign iss_bank_set = x_set;
    assign iss_own_en   = x_own;
    assign iss_own_root = tv && tu && t_z;
    assign iss_reg_en   = tv ? t_rv : '0;
    assign iss_root_upd = tv ? t_ru : '0;
    assign iss_hi       = t_hi;
    assign iss_data     = t_d;
endmodule

`default_nettype wire
