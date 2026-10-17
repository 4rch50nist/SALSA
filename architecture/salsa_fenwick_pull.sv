// ===========================================================================
//  SALSA issue front-end, Fenwick instance, Zynq-7020
//
//  Scope: placement and issue only. SALSA turns one request into a
//  conflict-free per-bank schedule (enable + set address for every bank);
//  the memory or cache behind it belongs to the integrator. No storage, no
//  arbitration, no aggregation here.
//
//  Requests
//    query p   (q_is_write = 0): issue every node of the query chain
//              p, p-lsb(p), ... , in one cycle.
//    add x, d  (q_is_write = 1): issue node x alone, with d passed through.
//
//  Geometry, W = 15, K = 11, B = 16
//    lo = x[K-1:0], hi = x[W-1:K].
//    Banked nodes (lo != 0):   bank = (popcount(lo) + hi) mod B,  set = lo.
//    Registered nodes (lo = 0, the 15 roots of the 4-bit sub-tree) are not
//    banked; SALSA flags them on iss_reg_en for the integrator's flops.
//
//  Lazy chain generation
//    Every set bit i of lo stands for exactly one chain node: lo with all
//    bits below i cleared. So chain_gen never builds node addresses. It
//    emits one 5-bit tag per bit position, (valid, bank), where
//        valid_i = lo[i]
//        bank_i  = (popcount(lo[K-1:i]) + hi) mod B
//    e.g. lo = 1101, hi = 0  ->  bit3 (1,b1)  bit2 (1,b2)  bit1 (0,b2)  bit0 (1,b3).
//    The node address is materialised only at the crossbar, as the mask
//    {lo[K-1:i], i'b0}, which is wiring. The pipeline register between the
//    two carries 5 bits per lane instead of a full address.
//    Popcount falls by one per chain step and hi is fixed, so the valid
//    tags of one request carry distinct banks whenever K <= B.
//
//  Pipeline: input reg -> tag reg -> issue reg. Latency 3, one request per
//  cycle, q_ready tied high. With IN_REG = 0 the input register is removed
//  (the request must then come from a register, e.g. an AXI-Stream source):
//  tag reg -> issue reg, latency 2. With ISS_REG = 0 the issue register is
//  removed too: the iss_* outputs come straight from the pull logic, for banks
//  that register their own address (block RAM), latency 1 with IN_REG = 0.
// ===========================================================================

`default_nettype none

// ---------------------------------------------------------------------------
//  Parallel prefix popcount (Sklansky). pcb[i] = popcount(v[i-1:0]),
//  pcb[0] = 0, pcb[N] = popcount(v). ceil(log2 N) adder levels.
// ---------------------------------------------------------------------------
module prefix_popcount #(
    parameter int unsigned N  = 11,
    parameter int unsigned CW = $clog2(N + 1)
) (
    input  wire  logic [N-1:0]      v,
    output logic [(N+1)*CW-1:0]     pcb          // CW bits per entry
);
    localparam int unsigned LV = (N > 1) ? $clog2(N) : 1;
    logic [CW-1:0] s [0:LV][0:N-1];

    always_comb begin
        for (int unsigned i = 0; i < N; i++) s[0][i] = CW'(v[i]);
        for (int unsigned l = 0; l < LV; l++)
            for (int unsigned i = 0; i < N; i++)
                if ((i >> l) & 1)
                    s[l+1][i] = s[l][i] + s[l][((i >> l) << l) - 1];
                else
                    s[l+1][i] = s[l][i];
        pcb[CW-1:0] = '0;
        for (int unsigned i = 0; i < N; i++)
            pcb[(i+1)*CW +: CW] = s[LV][i];
    end
endmodule

// ---------------------------------------------------------------------------
//  Lazy chain generation: one (valid, bank) tag per bit position of lo,
//  plus one valid bit per bit position of hi for the registered region.
// ---------------------------------------------------------------------------
module chain_gen #(
    parameter int unsigned K  = 11,
    parameter int unsigned HW = 4,
    parameter int unsigned BW = 4,
    parameter int unsigned CW = $clog2(K + 1)
) (
    input  wire  logic [K-1:0]      lo,
    input  wire  logic [HW-1:0]     hi,
    input  wire  logic              is_query,
    output logic [K-1:0]            tag_v,       // lane i <-> bit i of lo
    output logic [K*BW-1:0]         tag_b,       // BW bits per lane
    output logic [K*CW-1:0]         tag_s,       // sigma_i per lane (pull form)
    output logic [HW-1:0]           reg_v        // lane j <-> bit j of hi
);
    // suffix popcount: run the prefix network on lo bit-reversed,
    // so popcount(lo[K-1:i]) = pcb_r[K-i]
    logic [K-1:0]          lo_r;
    logic [(K+1)*CW-1:0]   pcb_r;
    always_comb for (int unsigned i = 0; i < K; i++) lo_r[i] = lo[K-1-i];
    prefix_popcount #(.N(K), .CW(CW)) u_pc (.v(lo_r), .pcb(pcb_r));

    // an add issues only the node itself, i.e. the lane of lo's lowest set bit
    wire [K-1:0]  lo_low = lo & (~lo + 1'b1);
    wire [HW-1:0] hi_low = hi & (~hi + 1'b1);

    always_comb begin
        for (int unsigned i = 0; i < K; i++) begin
            tag_v[i]           = is_query ? lo[i] : lo_low[i];
            tag_b[i*BW +: BW]  = BW'(pcb_r[(K-i)*CW +: CW]) + BW'(hi);
            tag_s[i*CW +: CW]  = pcb_r[(K-i)*CW +: CW];
        end
        // registered region: a query touches every hi-chain root; an add
        // touches one only when the node itself has lo = 0
        reg_v = is_query ? hi : ((lo == '0) ? hi_low : '0);
    end
endmodule

// ===========================================================================
//  SALSA top, pull form (no crossbar)
// ===========================================================================
module salsa_fen_pull_top #(
    parameter int unsigned W  = 15,
    parameter int unsigned K  = 11,
    parameter int unsigned B  = 16,
    parameter int unsigned DW = 32,
    parameter bit          IN_REG  = 1'b1,    // 1: register the request first; 0: no input register
    parameter bit          ISS_REG = 1'b1     // 1: register the issue outputs; 0: drive them directly
) (
    input  wire  logic             clk,
    input  wire  logic             rst_n,
    // request
    input  wire  logic             q_valid,
    input  wire  logic             q_is_write,
    input  wire  logic [W-1:0]     q_idx,
    input  wire  logic [DW-1:0]    q_data,
    output logic                   q_ready,
    // issue schedule, one request per cycle
    output logic                   iss_valid,
    output logic                   iss_write,
    output logic [B-1:0]           iss_bank_en,
    output logic [B*K-1:0]         iss_bank_set,   // K bits per bank
    output logic [W-K-1:0]         iss_reg_en,     // lane j: root {hi with bits below j cleared}
    output logic [W-K-1:0]         iss_hi,
    output logic [DW-1:0]          iss_data
);
    localparam int unsigned BW = $clog2(B);
    localparam int unsigned HW = W - K;

`ifndef SYNTHESIS
    initial begin
        if ((1 << BW) != B) $fatal(1, "B must be a power of two");
        if (K > B)          $fatal(1, "a chain has up to K banked nodes; need K <= B");
        if (HW != BW)       $fatal(1, "need W - K == log2(B) for an injective, balanced map");
    end
`endif

    assign q_ready = 1'b1;

    // ---- stage 1: input register (optional) ------------------------------
    logic          iv, iw;
    logic [W-1:0]  ix;
    logic [DW-1:0] id;
    if (IN_REG) begin : g_in_reg
        always_ff @(posedge clk) begin
            if (!rst_n) iv <= 1'b0; else iv <= q_valid;
            iw <= q_is_write; ix <= q_idx; id <= q_data;
        end
    end else begin : g_in_wire
        assign iv = q_valid && rst_n;
        assign iw = q_is_write;
        assign ix = q_idx;
        assign id = q_data;
    end

    // ---- lazy tags: (valid, sigma) per lane; the offset is applied at the bank
    localparam int unsigned CW = $clog2(K + 1);
    logic [K-1:0]    c_tv;
    logic [K*CW-1:0] c_ts;
    logic [HW-1:0]   c_rv;
    chain_gen #(.K(K), .HW(HW), .BW(BW)) u_chain (
        .lo(ix[K-1:0]), .hi(ix[W-1:K]), .is_query(!iw),
        .tag_v(c_tv), .tag_b(), .tag_s(c_ts), .reg_v(c_rv));
    wire [CW-1:0] c_pc = c_ts[0 +: CW];          // sigma_0 = popcount(lo)
    wire [BW-1:0] c_c  = BW'(ix[W-1:K]);         // c = g(hi), identity

    // ---- stage 2: tag register (5 bits per lane, plus lo for the masks) ----
    logic            tv, tw;
    logic [K-1:0]    t_tv, t_lo;
    logic [K*CW-1:0] t_ts;
    logic [CW-1:0]   t_pc;
    logic [BW-1:0]   t_c;
    logic [HW-1:0]   t_rv, t_hi;
    logic [DW-1:0]   t_d;
    always_ff @(posedge clk) begin
        if (!rst_n) tv <= 1'b0; else tv <= iv;
        t_tv <= iv ? c_tv : '0;
        t_rv <= iv ? c_rv : '0;
        t_ts <= c_ts;
        t_pc <= c_pc;
        t_c  <= c_c;
        t_lo <= ix[K-1:0];
        t_hi <= ix[W-1:K];
        tw   <= iw;
        t_d  <= id;
    end

    // ---- stage 2, pull form: no crossbar ---------------------------------------
    //  bank b owns rank r_b = b - c; it keeps bit j of lo iff sigma_j <= r_b.
    //  A query uses every rank 1..popcount(lo); an add only its own node,
    //  whose rank is popcount(lo).
    logic [B-1:0]   x_en;
    logic [B*K-1:0] x_set;
    always_comb
        for (int unsigned b = 0; b < B; b++) begin
            logic [BW-1:0] r;
            r = BW'(b) - t_c;
            x_en[b] = tv && (r != '0) && (CW'(r) <= t_pc) && (!tw || CW'(r) == t_pc);
            for (int unsigned j = 0; j < K; j++)
                x_set[b*K + j] = t_lo[j] && (t_ts[j*CW +: CW] <= CW'(r));
            if (!x_en[b]) x_set[b*K +: K] = '0;
        end

    // ---- stage 3: issue register (optional) -------------------------------
    if (ISS_REG) begin : g_iss_reg
        always_ff @(posedge clk) begin
            if (!rst_n) begin
                iss_valid <= 1'b0; iss_bank_en <= '0; iss_reg_en <= '0;
            end else begin
                iss_valid   <= tv;
                iss_bank_en <= x_en;
                iss_reg_en  <= t_rv;
            end
            iss_write    <= tw;
            iss_bank_set <= x_set;
            iss_hi       <= t_hi;
            iss_data     <= t_d;
        end
    end else begin : g_iss_wire
        assign iss_valid    = tv;
        assign iss_bank_en  = x_en;          // already gated by tv
        assign iss_reg_en   = tv ? t_rv : '0;
        assign iss_write    = tw;
        assign iss_bank_set = x_set;
        assign iss_hi       = t_hi;
        assign iss_data     = t_d;
    end

    // no conflict assertion: each bank selects exactly one rank by construction
endmodule

`default_nettype wire
