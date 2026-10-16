// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb.h for the primary calling header

#ifndef VERILATED_VTB___024ROOT_H_
#define VERILATED_VTB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb__DOT__clk;
        CData/*0:0*/ tb__DOT__rstn;
        CData/*0:0*/ tb__DOT__sv;
        CData/*0:0*/ tb__DOT__sr;
        CData/*0:0*/ tb__DOT__mv;
        CData/*0:0*/ tb__DOT__mr;
        CData/*0:0*/ tb__DOT__ml;
        CData/*7:0*/ tb__DOT__awa;
        CData/*7:0*/ tb__DOT__ara;
        CData/*0:0*/ tb__DOT__awv;
        CData/*0:0*/ tb__DOT__wv;
        CData/*0:0*/ tb__DOT__bv;
        CData/*0:0*/ tb__DOT__arv;
        CData/*0:0*/ tb__DOT__arr;
        CData/*0:0*/ tb__DOT__rv;
        CData/*0:0*/ tb__DOT__backpressure;
        CData/*0:0*/ tb__DOT__dut__DOT__accept;
        CData/*0:0*/ tb__DOT__dut__DOT__out_valid;
        CData/*7:0*/ tb__DOT__dut__DOT__in_flight;
        CData/*7:0*/ tb__DOT__dut__DOT__count;
        CData/*0:0*/ tb__DOT__dut__DOT__start;
        CData/*4:0*/ tb__DOT__dut__DOT__wp;
        CData/*4:0*/ tb__DOT__dut__DOT__rp;
        CData/*0:0*/ tb__DOT__dut__DOT__load;
        CData/*0:0*/ tb__DOT__dut__DOT__send;
        CData/*0:0*/ tb__DOT__dut__DOT__timing;
        CData/*0:0*/ tb__DOT__dut__DOT__done;
        CData/*0:0*/ tb__DOT__dut__DOT__got_first;
        CData/*0:0*/ tb__DOT__dut__DOT__wr;
        CData/*0:0*/ tb__DOT__dut__DOT__u_dp__DOT__iss_valid;
        CData/*0:0*/ tb__DOT__dut__DOT__u_dp__DOT__iss_write;
        CData/*3:0*/ tb__DOT__dut__DOT__u_dp__DOT__lane;
        CData/*3:0*/ tb__DOT__dut__DOT__u_dp__DOT__hi;
        CData/*0:0*/ tb__DOT__dut__DOT__u_dp__DOT__store;
        CData/*0:0*/ tb__DOT__dut__DOT__u_dp__DOT__query;
        CData/*0:0*/ tb__DOT__dut__DOT__u_dp__DOT__v1;
        CData/*0:0*/ tb__DOT__dut__DOT__u_dp__DOT__v2;
        CData/*0:0*/ tb__DOT__dut__DOT__u_dp__DOT__v3;
        CData/*0:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__iv;
        CData/*0:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__iw;
        CData/*0:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv;
        CData/*0:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw;
        CData/*3:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc;
        CData/*3:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c;
        CData/*3:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_rv;
        CData/*3:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_hi;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__clk__0;
        SData/*15:0*/ tb__DOT__dut__DOT__u_dp__DOT__en;
        SData/*14:0*/ tb__DOT__dut__DOT__u_dp__DOT__rflag;
        SData/*15:0*/ tb__DOT__dut__DOT__u_dp__DOT__en1;
        SData/*15:0*/ tb__DOT__dut__DOT__u_dp__DOT__en2;
        SData/*15:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix;
        SData/*11:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo;
        SData/*15:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en;
        IData/*31:0*/ tb__DOT__wd;
        IData/*31:0*/ tb__DOT__rd;
        IData/*31:0*/ tb__DOT__errors;
        IData/*31:0*/ tb__DOT__got;
        IData/*31:0*/ tb__DOT__n_run;
        IData/*31:0*/ tb__DOT__unnamedblk3__DOT__v;
        IData/*31:0*/ tb__DOT__unnamedblk3__DOT__cyc;
        IData/*31:0*/ tb__DOT__unnamedblk3__DOT__lat;
        IData/*31:0*/ tb__DOT__unnamedblk3__DOT__k;
        VlWide<16>/*511:0*/ tb__DOT__dut__DOT__bank_stores;
    };
    struct {
        IData/*31:0*/ tb__DOT__dut__DOT__root_stores;
        IData/*31:0*/ tb__DOT__dut__DOT__run_len;
        IData/*31:0*/ tb__DOT__dut__DOT__pushed;
        IData/*31:0*/ tb__DOT__dut__DOT__cycles;
        IData/*31:0*/ tb__DOT__dut__DOT__req_count;
        IData/*31:0*/ tb__DOT__dut__DOT__res_count;
        IData/*31:0*/ tb__DOT__dut__DOT__latency;
        VlWide<6>/*191:0*/ tb__DOT__dut__DOT__u_dp__DOT__set;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__data;
        VlWide<16>/*511:0*/ tb__DOT__dut__DOT__u_dp__DOT__rd;
        VlWide<15>/*479:0*/ tb__DOT__dut__DOT__u_dp__DOT__root;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__root_sum;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__rs1;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__rs2;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__rs3;
        VlWide<4>/*127:0*/ tb__DOT__dut__DOT__u_dp__DOT__part;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__q;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__id;
        IData/*31:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_d;
        VlWide<6>/*191:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set;
        IData/*31:0*/ __VdfgRegularize_hebeb780c_0_1;
        IData/*31:0*/ __VdfgRegularize_hebeb780c_0_2;
        IData/*31:0*/ __VdfgRegularize_hebeb780c_0_5;
        IData/*31:0*/ __VdfgRegularize_hebeb780c_0_8;
        IData/*31:0*/ __Vi;
        QData/*63:0*/ tb__DOT____VlemCall_5__mk;
        QData/*63:0*/ tb__DOT____VlemCall_4__mk;
        QData/*63:0*/ tb__DOT____VlemCall_3__mk;
        QData/*63:0*/ tb__DOT____VlemCall_2__mk;
        QData/*63:0*/ tb__DOT____VlemCall_1__mk;
        QData/*63:0*/ tb__DOT____VlemCall_0__mk;
        QData/*63:0*/ tb__DOT__sd;
        QData/*63:0*/ tb__DOT__md;
        QData/*63:0*/ tb__DOT__unnamedblk1__DOT__r;
        QData/*63:0*/ tb__DOT__unnamedblk1__DOT__e;
        QData/*63:0*/ tb__DOT__dut__DOT__out_word;
        QData/*63:0*/ tb__DOT__dut__DOT__u_dp__DOT__w0;
        QData/*63:0*/ tb__DOT__dut__DOT__u_dp__DOT__w1;
        QData/*63:0*/ tb__DOT__dut__DOT__u_dp__DOT__w2;
        QData/*63:0*/ tb__DOT__dut__DOT__u_dp__DOT__x1;
        QData/*63:0*/ tb__DOT__dut__DOT__u_dp__DOT__x2;
        QData/*63:0*/ tb__DOT__dut__DOT__u_dp__DOT__x3;
        QData/*47:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts;
        QData/*51:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r;
        VlUnpacked<IData/*31:0*/, 65536> tb__DOT__a;
        VlUnpacked<IData/*31:0*/, 65536> tb__DOT__tree;
        VlUnpacked<IData/*31:0*/, 65536> tb__DOT__prefix;
        VlUnpacked<VlWide<3>/*64:0*/, 32> tb__DOT__dut__DOT__fifo;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem;
    };
    struct {
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem;
        VlUnpacked<VlUnpacked<CData/*3:0*/, 12>, 5> tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };
    VlQueue<QData/*63:0*/> tb__DOT__expect_q;
    VlQueue<QData/*63:0*/> tb__DOT__unnamedblk3__DOT__words;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h6018ce7f__0;
    VlTriggerScheduler __VtrigSched_h6018ce40__0;

    // INTERNAL VARIABLES
    Vtb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb___024root(Vtb__Syms* symsp, const char* namep);
    ~Vtb___024root();
    VL_UNCOPYABLE(Vtb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
