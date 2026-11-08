// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_fe.h for the primary calling header

#ifndef VERILATED_VTB_FE___024ROOT_H_
#define VERILATED_VTB_FE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_fe__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_fe___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_fe__DOT__clk;
    CData/*0:0*/ tb_fe__DOT__rst_n;
    CData/*0:0*/ tb_fe__DOT__q_valid;
    CData/*0:0*/ tb_fe__DOT__q_is_update;
    CData/*0:0*/ tb_fe__DOT__dut__DOT__tv;
    CData/*0:0*/ tb_fe__DOT__dut__DOT__tu;
    CData/*3:0*/ tb_fe__DOT__dut__DOT__t_lv;
    CData/*3:0*/ tb_fe__DOT__dut__DOT__t_c;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_fe__DOT__clk__0;
    SData/*15:0*/ tb_fe__DOT__q_idx;
    SData/*11:0*/ tb_fe__DOT__dut__DOT__t_lo;
    SData/*15:0*/ tb_fe__DOT__dut__DOT__x_en;
    IData/*31:0*/ tb_fe__DOT__errors;
    IData/*31:0*/ tb_fe__DOT__checked;
    IData/*31:0*/ tb_fe__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p;
    VlWide<6>/*191:0*/ tb_fe__DOT__dut__DOT__x_set;
    IData/*31:0*/ __Vi;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h521be442__0;
    VlTriggerScheduler __VtrigSched_h521be501__0;

    // INTERNAL VARIABLES
    Vtb_fe__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_fe___024root(Vtb_fe__Syms* symsp, const char* namep);
    ~Vtb_fe___024root();
    VL_UNCOPYABLE(Vtb_fe___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
