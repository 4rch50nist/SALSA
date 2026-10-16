// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"

VL_ATTR_COLD void Vtb___024root___eval_initial__TOP(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf);

void Vtb___024root___eval_initial(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_initial__TOP(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vtb___024root___eval_sample(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_sample\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb___024root___eval_ico(Vtb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_ico\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vtb___024root___timing_ready(Vtb___024root* vlSelf);
void Vtb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vtb___024root___timing_resume(Vtb___024root* vlSelf);

bool Vtb___024root___eval_act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                          << 2U) 
                                                         | ((((~ (IData)(vlSelfRef.tb__DOT__clk)) 
                                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.tb__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0 
            = vlSelfRef.tb__DOT__clk;
    }
    Vtb___024root___timing_ready(vlSelf);
    Vtb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb___024root___timing_resume(vlSelf);
        {
            // Inlined CFunc: _eval_body__act
            if ((3ULL & vlSelfRef.__VactTriggered[0U])) {
                {
                    // Inlined CFunc: _act_comb__TOP__0
                    vlSelfRef.tb__DOT__sr = ((IData)(vlSelfRef.tb__DOT__rstn) 
                                             & (0x00000020U 
                                                > ((IData)(vlSelfRef.tb__DOT__dut__DOT__in_flight) 
                                                   + (IData)(vlSelfRef.tb__DOT__dut__DOT__count))));
                    vlSelfRef.tb__DOT__dut__DOT__accept 
                        = ((IData)(vlSelfRef.tb__DOT__sv) 
                           & ((IData)(vlSelfRef.tb__DOT__rstn) 
                              & (0x00000020U > ((IData)(vlSelfRef.tb__DOT__dut__DOT__in_flight) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__count)))));
                }
            }
        }
    }
    return (__VactExecute);
}

bool Vtb___024root___eval_inact(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_inact\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb_salsa.sv", 8, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb___024root___nba_sequent__TOP__0(Vtb___024root* vlSelf);
void Vtb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vtb___024root___eval_nba(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_nba\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtb___024root___nba_sequent__TOP__0(vlSelf);
            }
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _act_comb__TOP__0
                    vlSelfRef.tb__DOT__sr = ((IData)(vlSelfRef.tb__DOT__rstn) 
                                             & (0x00000020U 
                                                > ((IData)(vlSelfRef.tb__DOT__dut__DOT__in_flight) 
                                                   + (IData)(vlSelfRef.tb__DOT__dut__DOT__count))));
                    vlSelfRef.tb__DOT__dut__DOT__accept 
                        = ((IData)(vlSelfRef.tb__DOT__sv) 
                           & ((IData)(vlSelfRef.tb__DOT__rstn) 
                              & (0x00000020U > ((IData)(vlSelfRef.tb__DOT__dut__DOT__in_flight) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__count)))));
                }
            }
        }
        Vtb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vtb___024root___eval_obs(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_obs\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtb___024root___eval_react(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_react\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vtb___024root___eval_postponed(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_postponed\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb___024root____VbeforeTrig_h6018ce7f__0(Vtb___024root* vlSelf, const char* __VeventDescription);
void Vtb___024root____VbeforeTrig_h6018ce40__0(Vtb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i;
    tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i = 0;
    IData/*31:0*/ tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i;
    tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i = 0;
    IData/*31:0*/ tb__DOT__unnamedblk3__DOT__unnamedblk1_1__DOT____Vrepeat0;
    tb__DOT__unnamedblk3__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ tb__DOT__unnamedblk3__DOT__unnamedblk6__DOT__i;
    tb__DOT__unnamedblk3__DOT__unnamedblk6__DOT__i = 0;
    IData/*31:0*/ tb__DOT__unnamedblk3__DOT__unnamedblk7__DOT__b;
    tb__DOT__unnamedblk3__DOT__unnamedblk7__DOT__b = 0;
    IData/*31:0*/ tb__DOT__unnamedblk3__DOT__unnamedblk8__DOT__i;
    tb__DOT__unnamedblk3__DOT__unnamedblk8__DOT__i = 0;
    IData/*31:0*/ tb__DOT__unnamedblk3__DOT__unnamedblk9__DOT__i;
    tb__DOT__unnamedblk3__DOT__unnamedblk9__DOT__i = 0;
    CData/*1:0*/ __Vfunc_tb__DOT__mk__0__op;
    __Vfunc_tb__DOT__mk__0__op = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__0__i;
    __Vfunc_tb__DOT__mk__0__i = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__0__key;
    __Vfunc_tb__DOT__mk__0__key = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__0__v;
    __Vfunc_tb__DOT__mk__0__v = 0;
    QData/*63:0*/ __Vfunc_tb__DOT__mk__0__w;
    __Vfunc_tb__DOT__mk__0__w = 0;
    CData/*1:0*/ __Vfunc_tb__DOT__mk__1__op;
    __Vfunc_tb__DOT__mk__1__op = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__1__i;
    __Vfunc_tb__DOT__mk__1__i = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__1__key;
    __Vfunc_tb__DOT__mk__1__key = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__1__v;
    __Vfunc_tb__DOT__mk__1__v = 0;
    QData/*63:0*/ __Vfunc_tb__DOT__mk__1__w;
    __Vfunc_tb__DOT__mk__1__w = 0;
    VlQueue<QData/*63:0*/> __Vtask_tb__DOT__run__2__words;
    __Vtask_tb__DOT__run__2__words.atDefault() = 0;
    CData/*0:0*/ __Vtask_tb__DOT__run__2__bp;
    __Vtask_tb__DOT__run__2__bp = 0;
    IData/*31:0*/ __Vtask_tb__DOT__run__2__unnamedblk2__DOT__i;
    __Vtask_tb__DOT__run__2__unnamedblk2__DOT__i = 0;
    IData/*31:0*/ __Vtask_tb__DOT__run__2__st;
    __Vtask_tb__DOT__run__2__st = 0;
    CData/*7:0*/ __Vtask_tb__DOT__reg_write__3__a;
    __Vtask_tb__DOT__reg_write__3__a = 0;
    IData/*31:0*/ __Vtask_tb__DOT__reg_write__3__d;
    __Vtask_tb__DOT__reg_write__3__d = 0;
    CData/*7:0*/ __Vtask_tb__DOT__reg_write__4__a;
    __Vtask_tb__DOT__reg_write__4__a = 0;
    IData/*31:0*/ __Vtask_tb__DOT__reg_write__4__d;
    __Vtask_tb__DOT__reg_write__4__d = 0;
    CData/*7:0*/ __Vtask_tb__DOT__reg_read__5__a;
    __Vtask_tb__DOT__reg_read__5__a = 0;
    IData/*31:0*/ __Vtask_tb__DOT__reg_read__5__d;
    __Vtask_tb__DOT__reg_read__5__d = 0;
    CData/*7:0*/ __Vtask_tb__DOT__reg_read__6__a;
    __Vtask_tb__DOT__reg_read__6__a = 0;
    IData/*31:0*/ __Vtask_tb__DOT__reg_read__6__d;
    __Vtask_tb__DOT__reg_read__6__d = 0;
    CData/*7:0*/ __Vtask_tb__DOT__reg_read__7__a;
    __Vtask_tb__DOT__reg_read__7__a = 0;
    IData/*31:0*/ __Vtask_tb__DOT__reg_read__7__d;
    __Vtask_tb__DOT__reg_read__7__d = 0;
    CData/*1:0*/ __Vfunc_tb__DOT__mk__8__op;
    __Vfunc_tb__DOT__mk__8__op = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__8__i;
    __Vfunc_tb__DOT__mk__8__i = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__8__key;
    __Vfunc_tb__DOT__mk__8__key = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__8__v;
    __Vfunc_tb__DOT__mk__8__v = 0;
    QData/*63:0*/ __Vfunc_tb__DOT__mk__8__w;
    __Vfunc_tb__DOT__mk__8__w = 0;
    CData/*1:0*/ __Vfunc_tb__DOT__mk__9__op;
    __Vfunc_tb__DOT__mk__9__op = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__9__i;
    __Vfunc_tb__DOT__mk__9__i = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__9__key;
    __Vfunc_tb__DOT__mk__9__key = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__9__v;
    __Vfunc_tb__DOT__mk__9__v = 0;
    QData/*63:0*/ __Vfunc_tb__DOT__mk__9__w;
    __Vfunc_tb__DOT__mk__9__w = 0;
    VlQueue<QData/*63:0*/> __Vtask_tb__DOT__run__10__words;
    __Vtask_tb__DOT__run__10__words.atDefault() = 0;
    CData/*0:0*/ __Vtask_tb__DOT__run__10__bp;
    __Vtask_tb__DOT__run__10__bp = 0;
    IData/*31:0*/ __Vtask_tb__DOT__run__10__unnamedblk2__DOT__i;
    __Vtask_tb__DOT__run__10__unnamedblk2__DOT__i = 0;
    IData/*31:0*/ __Vtask_tb__DOT__run__10__st;
    __Vtask_tb__DOT__run__10__st = 0;
    CData/*7:0*/ __Vtask_tb__DOT__reg_write__11__a;
    __Vtask_tb__DOT__reg_write__11__a = 0;
    IData/*31:0*/ __Vtask_tb__DOT__reg_write__11__d;
    __Vtask_tb__DOT__reg_write__11__d = 0;
    CData/*7:0*/ __Vtask_tb__DOT__reg_write__12__a;
    __Vtask_tb__DOT__reg_write__12__a = 0;
    IData/*31:0*/ __Vtask_tb__DOT__reg_write__12__d;
    __Vtask_tb__DOT__reg_write__12__d = 0;
    CData/*7:0*/ __Vtask_tb__DOT__reg_read__13__a;
    __Vtask_tb__DOT__reg_read__13__a = 0;
    IData/*31:0*/ __Vtask_tb__DOT__reg_read__13__d;
    __Vtask_tb__DOT__reg_read__13__d = 0;
    CData/*7:0*/ __Vtask_tb__DOT__reg_read__14__a;
    __Vtask_tb__DOT__reg_read__14__a = 0;
    IData/*31:0*/ __Vtask_tb__DOT__reg_read__14__d;
    __Vtask_tb__DOT__reg_read__14__d = 0;
    CData/*7:0*/ __Vtask_tb__DOT__reg_read__15__a;
    __Vtask_tb__DOT__reg_read__15__a = 0;
    IData/*31:0*/ __Vtask_tb__DOT__reg_read__15__d;
    __Vtask_tb__DOT__reg_read__15__d = 0;
    CData/*1:0*/ __Vfunc_tb__DOT__mk__16__op;
    __Vfunc_tb__DOT__mk__16__op = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__16__i;
    __Vfunc_tb__DOT__mk__16__i = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__16__key;
    __Vfunc_tb__DOT__mk__16__key = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__16__v;
    __Vfunc_tb__DOT__mk__16__v = 0;
    QData/*63:0*/ __Vfunc_tb__DOT__mk__16__w;
    __Vfunc_tb__DOT__mk__16__w = 0;
    CData/*1:0*/ __Vfunc_tb__DOT__mk__17__op;
    __Vfunc_tb__DOT__mk__17__op = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__17__i;
    __Vfunc_tb__DOT__mk__17__i = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__17__key;
    __Vfunc_tb__DOT__mk__17__key = 0;
    IData/*31:0*/ __Vfunc_tb__DOT__mk__17__v;
    __Vfunc_tb__DOT__mk__17__v = 0;
    QData/*63:0*/ __Vfunc_tb__DOT__mk__17__w;
    __Vfunc_tb__DOT__mk__17__w = 0;
    VlQueue<QData/*63:0*/> __Vtask_tb__DOT__run__18__words;
    __Vtask_tb__DOT__run__18__words.atDefault() = 0;
    CData/*0:0*/ __Vtask_tb__DOT__run__18__bp;
    __Vtask_tb__DOT__run__18__bp = 0;
    IData/*31:0*/ __Vtask_tb__DOT__run__18__unnamedblk2__DOT__i;
    __Vtask_tb__DOT__run__18__unnamedblk2__DOT__i = 0;
    IData/*31:0*/ __Vtask_tb__DOT__run__18__st;
    __Vtask_tb__DOT__run__18__st = 0;
    CData/*7:0*/ __Vtask_tb__DOT__reg_write__19__a;
    __Vtask_tb__DOT__reg_write__19__a = 0;
    IData/*31:0*/ __Vtask_tb__DOT__reg_write__19__d;
    __Vtask_tb__DOT__reg_write__19__d = 0;
    CData/*7:0*/ __Vtask_tb__DOT__reg_write__20__a;
    __Vtask_tb__DOT__reg_write__20__a = 0;
    IData/*31:0*/ __Vtask_tb__DOT__reg_write__20__d;
    __Vtask_tb__DOT__reg_write__20__d = 0;
    CData/*7:0*/ __Vtask_tb__DOT__reg_read__21__a;
    __Vtask_tb__DOT__reg_read__21__a = 0;
    IData/*31:0*/ __Vtask_tb__DOT__reg_read__21__d;
    __Vtask_tb__DOT__reg_read__21__d = 0;
    // Body
    tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i = 1U;
    while (VL_GTS_III(32, 0x00010000U, tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)) {
        vlSelfRef.tb__DOT__a[(0x0000ffffU & tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)] 
            = VL_MODDIV_III(32, (IData)(VL_RANDOM_I()), (IData)(0x000003e8U));
        vlSelfRef.tb__DOT__prefix[(0x0000ffffU & tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)] 
            = (vlSelfRef.tb__DOT__prefix[(0x0000ffffU 
                                          & (tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i 
                                             - (IData)(1U)))] 
               + vlSelfRef.tb__DOT__a[(0x0000ffffU 
                                       & tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)]);
        tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i 
            = ((IData)(1U) + tb__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i);
    }
    vlSelfRef.tb__DOT__tree = vlSelfRef.tb__DOT__a;
    tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i = 1U;
    while (VL_GTS_III(32, 0x00010000U, tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i)) {
        if (VL_GTS_III(32, 0x00010000U, (tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i 
                                         + (tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i 
                                            & (- tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i))))) {
            vlSelfRef.tb__DOT__tree[(0x0000ffffU & 
                                     (tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i 
                                      + (tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i 
                                         & (- tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i))))] 
                = (vlSelfRef.tb__DOT__tree[(0x0000ffffU 
                                            & (tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i 
                                               + (tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i 
                                                  & (- tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i))))] 
                   + vlSelfRef.tb__DOT__tree[(0x0000ffffU 
                                              & tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i)]);
        }
        tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i 
            = ((IData)(1U) + tb__DOT__unnamedblk3__DOT__unnamedblk5__DOT__i);
    }
    tb__DOT__unnamedblk3__DOT__unnamedblk1_1__DOT____Vrepeat0 = 5U;
    while (VL_LTS_III(32, 0U, tb__DOT__unnamedblk3__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb___024root____VbeforeTrig_h6018ce7f__0(vlSelf, 
                                                  "@(posedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce7f__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             88);
        tb__DOT__unnamedblk3__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (tb__DOT__unnamedblk3__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb__DOT__rstn = 1U;
    tb__DOT__unnamedblk3__DOT__unnamedblk6__DOT__i = 1U;
    while (VL_GTS_III(32, 0x00010000U, tb__DOT__unnamedblk3__DOT__unnamedblk6__DOT__i)) {
        __Vfunc_tb__DOT__mk__0__v = vlSelfRef.tb__DOT__tree
            [(0x0000ffffU & tb__DOT__unnamedblk3__DOT__unnamedblk6__DOT__i)];
        __Vfunc_tb__DOT__mk__0__key = tb__DOT__unnamedblk3__DOT__unnamedblk6__DOT__i;
        __Vfunc_tb__DOT__mk__0__i = tb__DOT__unnamedblk3__DOT__unnamedblk6__DOT__i;
        __Vfunc_tb__DOT__mk__0__op = 1U;
        vlSelfRef.tb__DOT____VlemCall_0__mk = 0;
        __Vfunc_tb__DOT__mk__0__w = 0;
        __Vfunc_tb__DOT__mk__0__w = ((0x00000000ffffffffULL 
                                      & __Vfunc_tb__DOT__mk__0__w) 
                                     | ((QData)((IData)(
                                                        (((IData)(__Vfunc_tb__DOT__mk__0__op) 
                                                          << 0x0000001eU) 
                                                         | ((0x3fff0000U 
                                                             & (__Vfunc_tb__DOT__mk__0__i 
                                                                << 0x00000010U)) 
                                                            | (0x0000ffffU 
                                                               & __Vfunc_tb__DOT__mk__0__key))))) 
                                        << 0x00000020U));
        __Vfunc_tb__DOT__mk__0__w = ((0xffffffff00000000ULL 
                                      & __Vfunc_tb__DOT__mk__0__w) 
                                     | (IData)((IData)(__Vfunc_tb__DOT__mk__0__v)));
        vlSelfRef.tb__DOT____VlemCall_0__mk = __Vfunc_tb__DOT__mk__0__w;
        vlSelfRef.tb__DOT__unnamedblk3__DOT__words.push_back(vlSelfRef.tb__DOT____VlemCall_0__mk);
        __Vfunc_tb__DOT__mk__1__v = vlSelfRef.tb__DOT__tree
            [(0x0000ffffU & tb__DOT__unnamedblk3__DOT__unnamedblk6__DOT__i)];
        __Vfunc_tb__DOT__mk__1__key = tb__DOT__unnamedblk3__DOT__unnamedblk6__DOT__i;
        __Vfunc_tb__DOT__mk__1__i = tb__DOT__unnamedblk3__DOT__unnamedblk6__DOT__i;
        __Vfunc_tb__DOT__mk__1__op = 1U;
        vlSelfRef.tb__DOT____VlemCall_1__mk = 0;
        __Vfunc_tb__DOT__mk__1__w = 0;
        __Vfunc_tb__DOT__mk__1__w = ((0x00000000ffffffffULL 
                                      & __Vfunc_tb__DOT__mk__1__w) 
                                     | ((QData)((IData)(
                                                        (((IData)(__Vfunc_tb__DOT__mk__1__op) 
                                                          << 0x0000001eU) 
                                                         | ((0x3fff0000U 
                                                             & (__Vfunc_tb__DOT__mk__1__i 
                                                                << 0x00000010U)) 
                                                            | (0x0000ffffU 
                                                               & __Vfunc_tb__DOT__mk__1__key))))) 
                                        << 0x00000020U));
        __Vfunc_tb__DOT__mk__1__w = ((0xffffffff00000000ULL 
                                      & __Vfunc_tb__DOT__mk__1__w) 
                                     | (IData)((IData)(__Vfunc_tb__DOT__mk__1__v)));
        vlSelfRef.tb__DOT____VlemCall_1__mk = __Vfunc_tb__DOT__mk__1__w;
        vlSelfRef.tb__DOT__expect_q.push_back(vlSelfRef.tb__DOT____VlemCall_1__mk);
        tb__DOT__unnamedblk3__DOT__unnamedblk6__DOT__i 
            = ((IData)(1U) + tb__DOT__unnamedblk3__DOT__unnamedblk6__DOT__i);
    }
    __Vtask_tb__DOT__run__2__bp = 1U;
    __Vtask_tb__DOT__run__2__words = vlSelfRef.tb__DOT__unnamedblk3__DOT__words;
    __Vtask_tb__DOT__run__2__unnamedblk2__DOT__i = 0U;
    __Vtask_tb__DOT__run__2__st = 0;
    vlSelfRef.tb__DOT__backpressure = __Vtask_tb__DOT__run__2__bp;
    vlSelfRef.tb__DOT__n_run = __Vtask_tb__DOT__run__2__words.size();
    vlSelfRef.tb__DOT__got = 0U;
    __Vtask_tb__DOT__reg_write__3__d = vlSelfRef.tb__DOT__n_run;
    __Vtask_tb__DOT__reg_write__3__a = 8U;
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         28);
    vlSelfRef.tb__DOT__awa = __Vtask_tb__DOT__reg_write__3__a;
    vlSelfRef.tb__DOT__wd = __Vtask_tb__DOT__reg_write__3__d;
    vlSelfRef.tb__DOT__awv = 1U;
    vlSelfRef.tb__DOT__wv = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__wr)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             29);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         30);
    vlSelfRef.tb__DOT__awv = 0U;
    vlSelfRef.tb__DOT__wv = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__bv)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             31);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         32);
    __Vtask_tb__DOT__reg_write__4__d = 1U;
    __Vtask_tb__DOT__reg_write__4__a = 0U;
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         28);
    vlSelfRef.tb__DOT__awa = __Vtask_tb__DOT__reg_write__4__a;
    vlSelfRef.tb__DOT__wd = __Vtask_tb__DOT__reg_write__4__d;
    vlSelfRef.tb__DOT__awv = 1U;
    vlSelfRef.tb__DOT__wv = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__wr)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             29);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         30);
    vlSelfRef.tb__DOT__awv = 0U;
    vlSelfRef.tb__DOT__wv = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__bv)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             31);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         32);
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         66);
    __Vtask_tb__DOT__run__2__unnamedblk2__DOT__i = 0U;
    while (VL_LTS_III(32, __Vtask_tb__DOT__run__2__unnamedblk2__DOT__i, __Vtask_tb__DOT__run__2__words.size())) {
        vlSelfRef.tb__DOT__sd = __Vtask_tb__DOT__run__2__words.at(__Vtask_tb__DOT__run__2__unnamedblk2__DOT__i);
        vlSelfRef.tb__DOT__sv = 1U;
        while ((1U & (~ (IData)(vlSelfRef.tb__DOT__sr)))) {
            Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                      "@(negedge tb.clk)");
            co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb.clk)", 
                                                                 "tb_salsa.sv", 
                                                                 69);
        }
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             70);
        __Vtask_tb__DOT__run__2__unnamedblk2__DOT__i 
            = ((IData)(1U) + __Vtask_tb__DOT__run__2__unnamedblk2__DOT__i);
    }
    vlSelfRef.tb__DOT__sv = 0U;
    do {
        __Vtask_tb__DOT__reg_read__5__a = 4U;
        __Vtask_tb__DOT__reg_read__5__d = 0;
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             36);
        vlSelfRef.tb__DOT__ara = __Vtask_tb__DOT__reg_read__5__a;
        vlSelfRef.tb__DOT__arv = 1U;
        while (vlSelfRef.tb__DOT__rv) {
            Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                      "@(negedge tb.clk)");
            co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb.clk)", 
                                                                 "tb_salsa.sv", 
                                                                 37);
        }
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             38);
        vlSelfRef.tb__DOT__arv = 0U;
        while ((1U & (~ (IData)(vlSelfRef.tb__DOT__rv)))) {
            Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                      "@(negedge tb.clk)");
            co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb.clk)", 
                                                                 "tb_salsa.sv", 
                                                                 39);
        }
        __Vtask_tb__DOT__reg_read__5__d = vlSelfRef.tb__DOT__rd;
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             40);
        __Vtask_tb__DOT__run__2__st = __Vtask_tb__DOT__reg_read__5__d;
    } while ((1U & (~ __Vtask_tb__DOT__run__2__st)));
    tb__DOT__unnamedblk3__DOT__unnamedblk7__DOT__b = 0U;
    if (VL_UNLIKELY(((vlSelfRef.tb__DOT__got != vlSelfRef.tb__DOT__n_run)))) {
        vlSelfRef.tb__DOT__errors = ((IData)(1U) + vlSelfRef.tb__DOT__errors);
        VL_WRITEF_NX("ERROR: got %0d of %0d\n",2, '~',32,vlSelfRef.tb__DOT__got
                     , '~',32,vlSelfRef.tb__DOT__n_run);
    }
    while (VL_GTS_III(32, 0x00000010U, tb__DOT__unnamedblk3__DOT__unnamedblk7__DOT__b)) {
        __Vtask_tb__DOT__reg_read__6__a = (0x000000ffU 
                                           & ((IData)(0x40U) 
                                              + VL_MULS_III(32, (IData)(4U), tb__DOT__unnamedblk3__DOT__unnamedblk7__DOT__b)));
        __Vtask_tb__DOT__reg_read__6__d = 0;
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             36);
        vlSelfRef.tb__DOT__ara = __Vtask_tb__DOT__reg_read__6__a;
        vlSelfRef.tb__DOT__arv = 1U;
        while (vlSelfRef.tb__DOT__rv) {
            Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                      "@(negedge tb.clk)");
            co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb.clk)", 
                                                                 "tb_salsa.sv", 
                                                                 37);
        }
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             38);
        vlSelfRef.tb__DOT__arv = 0U;
        while ((1U & (~ (IData)(vlSelfRef.tb__DOT__rv)))) {
            Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                      "@(negedge tb.clk)");
            co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb.clk)", 
                                                                 "tb_salsa.sv", 
                                                                 39);
        }
        __Vtask_tb__DOT__reg_read__6__d = vlSelfRef.tb__DOT__rd;
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             40);
        vlSelfRef.tb__DOT__unnamedblk3__DOT__v = __Vtask_tb__DOT__reg_read__6__d;
        if (VL_UNLIKELY(((0x00000fffU != vlSelfRef.tb__DOT__unnamedblk3__DOT__v)))) {
            vlSelfRef.tb__DOT__errors = ((IData)(1U) 
                                         + vlSelfRef.tb__DOT__errors);
            VL_WRITEF_NX("ERROR: bank %0d has %0d\n",2
                         , '~',32,tb__DOT__unnamedblk3__DOT__unnamedblk7__DOT__b
                         , '#',32,vlSelfRef.tb__DOT__unnamedblk3__DOT__v);
        }
        tb__DOT__unnamedblk3__DOT__unnamedblk7__DOT__b 
            = ((IData)(1U) + tb__DOT__unnamedblk3__DOT__unnamedblk7__DOT__b);
    }
    __Vtask_tb__DOT__reg_read__7__a = 0x80U;
    __Vtask_tb__DOT__reg_read__7__d = 0;
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         36);
    vlSelfRef.tb__DOT__ara = __Vtask_tb__DOT__reg_read__7__a;
    vlSelfRef.tb__DOT__arv = 1U;
    while (vlSelfRef.tb__DOT__rv) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             37);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         38);
    vlSelfRef.tb__DOT__arv = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__rv)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             39);
    }
    __Vtask_tb__DOT__reg_read__7__d = vlSelfRef.tb__DOT__rd;
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         40);
    vlSelfRef.tb__DOT__unnamedblk3__DOT__v = __Vtask_tb__DOT__reg_read__7__d;
    if (VL_UNLIKELY(((0x0000000fU != vlSelfRef.tb__DOT__unnamedblk3__DOT__v)))) {
        vlSelfRef.tb__DOT__errors = ((IData)(1U) + vlSelfRef.tb__DOT__errors);
        VL_WRITEF_NX("ERROR: roots %0d\n",1, '#',32,vlSelfRef.tb__DOT__unnamedblk3__DOT__v);
    }
    VL_WRITEF_NX("load: 65535 stores, every bank 4095, roots 15\n",0);
    vlSelfRef.tb__DOT__unnamedblk3__DOT__words.clear();
    tb__DOT__unnamedblk3__DOT__unnamedblk8__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00004e20U, tb__DOT__unnamedblk3__DOT__unnamedblk8__DOT__i)) {
        vlSelfRef.tb__DOT__unnamedblk3__DOT__k = ((0U 
                                                   == tb__DOT__unnamedblk3__DOT__unnamedblk8__DOT__i)
                                                   ? 0x0000db16U
                                                   : 
                                                  (0x0000ffffU 
                                                   & VL_RANDOM_I()));
        __Vfunc_tb__DOT__mk__8__v = 0U;
        __Vfunc_tb__DOT__mk__8__key = vlSelfRef.tb__DOT__unnamedblk3__DOT__k;
        __Vfunc_tb__DOT__mk__8__i = tb__DOT__unnamedblk3__DOT__unnamedblk8__DOT__i;
        __Vfunc_tb__DOT__mk__8__op = 0U;
        vlSelfRef.tb__DOT____VlemCall_2__mk = 0;
        __Vfunc_tb__DOT__mk__8__w = 0;
        __Vfunc_tb__DOT__mk__8__w = ((0x00000000ffffffffULL 
                                      & __Vfunc_tb__DOT__mk__8__w) 
                                     | ((QData)((IData)(
                                                        (((IData)(__Vfunc_tb__DOT__mk__8__op) 
                                                          << 0x0000001eU) 
                                                         | ((0x3fff0000U 
                                                             & (__Vfunc_tb__DOT__mk__8__i 
                                                                << 0x00000010U)) 
                                                            | (0x0000ffffU 
                                                               & __Vfunc_tb__DOT__mk__8__key))))) 
                                        << 0x00000020U));
        __Vfunc_tb__DOT__mk__8__w = ((0xffffffff00000000ULL 
                                      & __Vfunc_tb__DOT__mk__8__w) 
                                     | (IData)((IData)(__Vfunc_tb__DOT__mk__8__v)));
        vlSelfRef.tb__DOT____VlemCall_2__mk = __Vfunc_tb__DOT__mk__8__w;
        vlSelfRef.tb__DOT__unnamedblk3__DOT__words.push_back(vlSelfRef.tb__DOT____VlemCall_2__mk);
        __Vfunc_tb__DOT__mk__9__v = vlSelfRef.tb__DOT__prefix
            [(0x0000ffffU & vlSelfRef.tb__DOT__unnamedblk3__DOT__k)];
        __Vfunc_tb__DOT__mk__9__key = vlSelfRef.tb__DOT__unnamedblk3__DOT__k;
        __Vfunc_tb__DOT__mk__9__i = tb__DOT__unnamedblk3__DOT__unnamedblk8__DOT__i;
        __Vfunc_tb__DOT__mk__9__op = 0U;
        vlSelfRef.tb__DOT____VlemCall_3__mk = 0;
        __Vfunc_tb__DOT__mk__9__w = 0;
        __Vfunc_tb__DOT__mk__9__w = ((0x00000000ffffffffULL 
                                      & __Vfunc_tb__DOT__mk__9__w) 
                                     | ((QData)((IData)(
                                                        (((IData)(__Vfunc_tb__DOT__mk__9__op) 
                                                          << 0x0000001eU) 
                                                         | ((0x3fff0000U 
                                                             & (__Vfunc_tb__DOT__mk__9__i 
                                                                << 0x00000010U)) 
                                                            | (0x0000ffffU 
                                                               & __Vfunc_tb__DOT__mk__9__key))))) 
                                        << 0x00000020U));
        __Vfunc_tb__DOT__mk__9__w = ((0xffffffff00000000ULL 
                                      & __Vfunc_tb__DOT__mk__9__w) 
                                     | (IData)((IData)(__Vfunc_tb__DOT__mk__9__v)));
        vlSelfRef.tb__DOT____VlemCall_3__mk = __Vfunc_tb__DOT__mk__9__w;
        vlSelfRef.tb__DOT__expect_q.push_back(vlSelfRef.tb__DOT____VlemCall_3__mk);
        tb__DOT__unnamedblk3__DOT__unnamedblk8__DOT__i 
            = ((IData)(1U) + tb__DOT__unnamedblk3__DOT__unnamedblk8__DOT__i);
    }
    __Vtask_tb__DOT__run__10__bp = 0U;
    __Vtask_tb__DOT__run__10__words = vlSelfRef.tb__DOT__unnamedblk3__DOT__words;
    __Vtask_tb__DOT__run__10__unnamedblk2__DOT__i = 0U;
    __Vtask_tb__DOT__run__10__st = 0;
    vlSelfRef.tb__DOT__backpressure = __Vtask_tb__DOT__run__10__bp;
    vlSelfRef.tb__DOT__n_run = __Vtask_tb__DOT__run__10__words.size();
    vlSelfRef.tb__DOT__got = 0U;
    __Vtask_tb__DOT__reg_write__11__d = vlSelfRef.tb__DOT__n_run;
    __Vtask_tb__DOT__reg_write__11__a = 8U;
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         28);
    vlSelfRef.tb__DOT__awa = __Vtask_tb__DOT__reg_write__11__a;
    vlSelfRef.tb__DOT__wd = __Vtask_tb__DOT__reg_write__11__d;
    vlSelfRef.tb__DOT__awv = 1U;
    vlSelfRef.tb__DOT__wv = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__wr)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             29);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         30);
    vlSelfRef.tb__DOT__awv = 0U;
    vlSelfRef.tb__DOT__wv = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__bv)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             31);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         32);
    __Vtask_tb__DOT__reg_write__12__d = 1U;
    __Vtask_tb__DOT__reg_write__12__a = 0U;
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         28);
    vlSelfRef.tb__DOT__awa = __Vtask_tb__DOT__reg_write__12__a;
    vlSelfRef.tb__DOT__wd = __Vtask_tb__DOT__reg_write__12__d;
    vlSelfRef.tb__DOT__awv = 1U;
    vlSelfRef.tb__DOT__wv = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__wr)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             29);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         30);
    vlSelfRef.tb__DOT__awv = 0U;
    vlSelfRef.tb__DOT__wv = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__bv)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             31);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         32);
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         66);
    __Vtask_tb__DOT__run__10__unnamedblk2__DOT__i = 0U;
    while (VL_LTS_III(32, __Vtask_tb__DOT__run__10__unnamedblk2__DOT__i, __Vtask_tb__DOT__run__10__words.size())) {
        vlSelfRef.tb__DOT__sd = __Vtask_tb__DOT__run__10__words.at(__Vtask_tb__DOT__run__10__unnamedblk2__DOT__i);
        vlSelfRef.tb__DOT__sv = 1U;
        while ((1U & (~ (IData)(vlSelfRef.tb__DOT__sr)))) {
            Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                      "@(negedge tb.clk)");
            co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb.clk)", 
                                                                 "tb_salsa.sv", 
                                                                 69);
        }
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             70);
        __Vtask_tb__DOT__run__10__unnamedblk2__DOT__i 
            = ((IData)(1U) + __Vtask_tb__DOT__run__10__unnamedblk2__DOT__i);
    }
    vlSelfRef.tb__DOT__sv = 0U;
    do {
        __Vtask_tb__DOT__reg_read__13__a = 4U;
        __Vtask_tb__DOT__reg_read__13__d = 0;
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             36);
        vlSelfRef.tb__DOT__ara = __Vtask_tb__DOT__reg_read__13__a;
        vlSelfRef.tb__DOT__arv = 1U;
        while (vlSelfRef.tb__DOT__rv) {
            Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                      "@(negedge tb.clk)");
            co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb.clk)", 
                                                                 "tb_salsa.sv", 
                                                                 37);
        }
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             38);
        vlSelfRef.tb__DOT__arv = 0U;
        while ((1U & (~ (IData)(vlSelfRef.tb__DOT__rv)))) {
            Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                      "@(negedge tb.clk)");
            co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb.clk)", 
                                                                 "tb_salsa.sv", 
                                                                 39);
        }
        __Vtask_tb__DOT__reg_read__13__d = vlSelfRef.tb__DOT__rd;
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             40);
        __Vtask_tb__DOT__run__10__st = __Vtask_tb__DOT__reg_read__13__d;
    } while ((1U & (~ __Vtask_tb__DOT__run__10__st)));
    __Vtask_tb__DOT__reg_read__14__a = 0x0cU;
    __Vtask_tb__DOT__reg_read__14__d = 0;
    if (VL_UNLIKELY(((vlSelfRef.tb__DOT__got != vlSelfRef.tb__DOT__n_run)))) {
        vlSelfRef.tb__DOT__errors = ((IData)(1U) + vlSelfRef.tb__DOT__errors);
        VL_WRITEF_NX("ERROR: got %0d of %0d\n",2, '~',32,vlSelfRef.tb__DOT__got
                     , '~',32,vlSelfRef.tb__DOT__n_run);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         36);
    vlSelfRef.tb__DOT__ara = __Vtask_tb__DOT__reg_read__14__a;
    vlSelfRef.tb__DOT__arv = 1U;
    while (vlSelfRef.tb__DOT__rv) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             37);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         38);
    vlSelfRef.tb__DOT__arv = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__rv)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             39);
    }
    __Vtask_tb__DOT__reg_read__14__d = vlSelfRef.tb__DOT__rd;
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         40);
    vlSelfRef.tb__DOT__unnamedblk3__DOT__cyc = __Vtask_tb__DOT__reg_read__14__d;
    __Vtask_tb__DOT__reg_read__15__a = 0x18U;
    __Vtask_tb__DOT__reg_read__15__d = 0;
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         36);
    vlSelfRef.tb__DOT__ara = __Vtask_tb__DOT__reg_read__15__a;
    vlSelfRef.tb__DOT__arv = 1U;
    while (vlSelfRef.tb__DOT__rv) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             37);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         38);
    vlSelfRef.tb__DOT__arv = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__rv)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             39);
    }
    __Vtask_tb__DOT__reg_read__15__d = vlSelfRef.tb__DOT__rd;
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         40);
    vlSelfRef.tb__DOT__unnamedblk3__DOT__lat = __Vtask_tb__DOT__reg_read__15__d;
    VL_WRITEF_NX("queries: 20000 in %0d cycles (%0.3f per request), latency %0d\n",3
                 , '#',32,vlSelfRef.tb__DOT__unnamedblk3__DOT__cyc
                 , 'D',(VL_ITOR_D_I(32, vlSelfRef.tb__DOT__unnamedblk3__DOT__cyc) 
                        / 2.00000000000000000e+04), '#',32,vlSelfRef.tb__DOT__unnamedblk3__DOT__lat);
    vlSelfRef.tb__DOT__unnamedblk3__DOT__words.clear();
    tb__DOT__unnamedblk3__DOT__unnamedblk9__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00004e20U, tb__DOT__unnamedblk3__DOT__unnamedblk9__DOT__i)) {
        vlSelfRef.tb__DOT__unnamedblk3__DOT__k = (0x0000ffffU 
                                                  & VL_RANDOM_I());
        __Vfunc_tb__DOT__mk__16__v = 0U;
        __Vfunc_tb__DOT__mk__16__key = vlSelfRef.tb__DOT__unnamedblk3__DOT__k;
        __Vfunc_tb__DOT__mk__16__i = tb__DOT__unnamedblk3__DOT__unnamedblk9__DOT__i;
        __Vfunc_tb__DOT__mk__16__op = 0U;
        vlSelfRef.tb__DOT____VlemCall_4__mk = 0;
        __Vfunc_tb__DOT__mk__16__w = 0;
        __Vfunc_tb__DOT__mk__16__w = ((0x00000000ffffffffULL 
                                       & __Vfunc_tb__DOT__mk__16__w) 
                                      | ((QData)((IData)(
                                                         (((IData)(__Vfunc_tb__DOT__mk__16__op) 
                                                           << 0x0000001eU) 
                                                          | ((0x3fff0000U 
                                                              & (__Vfunc_tb__DOT__mk__16__i 
                                                                 << 0x00000010U)) 
                                                             | (0x0000ffffU 
                                                                & __Vfunc_tb__DOT__mk__16__key))))) 
                                         << 0x00000020U));
        __Vfunc_tb__DOT__mk__16__w = ((0xffffffff00000000ULL 
                                       & __Vfunc_tb__DOT__mk__16__w) 
                                      | (IData)((IData)(__Vfunc_tb__DOT__mk__16__v)));
        vlSelfRef.tb__DOT____VlemCall_4__mk = __Vfunc_tb__DOT__mk__16__w;
        vlSelfRef.tb__DOT__unnamedblk3__DOT__words.push_back(vlSelfRef.tb__DOT____VlemCall_4__mk);
        __Vfunc_tb__DOT__mk__17__v = vlSelfRef.tb__DOT__prefix
            [(0x0000ffffU & vlSelfRef.tb__DOT__unnamedblk3__DOT__k)];
        __Vfunc_tb__DOT__mk__17__key = vlSelfRef.tb__DOT__unnamedblk3__DOT__k;
        __Vfunc_tb__DOT__mk__17__i = tb__DOT__unnamedblk3__DOT__unnamedblk9__DOT__i;
        __Vfunc_tb__DOT__mk__17__op = 0U;
        vlSelfRef.tb__DOT____VlemCall_5__mk = 0;
        __Vfunc_tb__DOT__mk__17__w = 0;
        __Vfunc_tb__DOT__mk__17__w = ((0x00000000ffffffffULL 
                                       & __Vfunc_tb__DOT__mk__17__w) 
                                      | ((QData)((IData)(
                                                         (((IData)(__Vfunc_tb__DOT__mk__17__op) 
                                                           << 0x0000001eU) 
                                                          | ((0x3fff0000U 
                                                              & (__Vfunc_tb__DOT__mk__17__i 
                                                                 << 0x00000010U)) 
                                                             | (0x0000ffffU 
                                                                & __Vfunc_tb__DOT__mk__17__key))))) 
                                         << 0x00000020U));
        __Vfunc_tb__DOT__mk__17__w = ((0xffffffff00000000ULL 
                                       & __Vfunc_tb__DOT__mk__17__w) 
                                      | (IData)((IData)(__Vfunc_tb__DOT__mk__17__v)));
        vlSelfRef.tb__DOT____VlemCall_5__mk = __Vfunc_tb__DOT__mk__17__w;
        vlSelfRef.tb__DOT__expect_q.push_back(vlSelfRef.tb__DOT____VlemCall_5__mk);
        tb__DOT__unnamedblk3__DOT__unnamedblk9__DOT__i 
            = ((IData)(1U) + tb__DOT__unnamedblk3__DOT__unnamedblk9__DOT__i);
    }
    __Vtask_tb__DOT__run__18__bp = 1U;
    __Vtask_tb__DOT__run__18__words = vlSelfRef.tb__DOT__unnamedblk3__DOT__words;
    __Vtask_tb__DOT__run__18__unnamedblk2__DOT__i = 0U;
    __Vtask_tb__DOT__run__18__st = 0;
    vlSelfRef.tb__DOT__backpressure = __Vtask_tb__DOT__run__18__bp;
    vlSelfRef.tb__DOT__n_run = __Vtask_tb__DOT__run__18__words.size();
    vlSelfRef.tb__DOT__got = 0U;
    __Vtask_tb__DOT__reg_write__19__d = vlSelfRef.tb__DOT__n_run;
    __Vtask_tb__DOT__reg_write__19__a = 8U;
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         28);
    vlSelfRef.tb__DOT__awa = __Vtask_tb__DOT__reg_write__19__a;
    vlSelfRef.tb__DOT__wd = __Vtask_tb__DOT__reg_write__19__d;
    vlSelfRef.tb__DOT__awv = 1U;
    vlSelfRef.tb__DOT__wv = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__wr)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             29);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         30);
    vlSelfRef.tb__DOT__awv = 0U;
    vlSelfRef.tb__DOT__wv = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__bv)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             31);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         32);
    __Vtask_tb__DOT__reg_write__20__d = 1U;
    __Vtask_tb__DOT__reg_write__20__a = 0U;
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         28);
    vlSelfRef.tb__DOT__awa = __Vtask_tb__DOT__reg_write__20__a;
    vlSelfRef.tb__DOT__wd = __Vtask_tb__DOT__reg_write__20__d;
    vlSelfRef.tb__DOT__awv = 1U;
    vlSelfRef.tb__DOT__wv = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__wr)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             29);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         30);
    vlSelfRef.tb__DOT__awv = 0U;
    vlSelfRef.tb__DOT__wv = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__bv)))) {
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             31);
    }
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         32);
    Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                              "@(negedge tb.clk)");
    co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb.clk)", 
                                                         "tb_salsa.sv", 
                                                         66);
    __Vtask_tb__DOT__run__18__unnamedblk2__DOT__i = 0U;
    while (VL_LTS_III(32, __Vtask_tb__DOT__run__18__unnamedblk2__DOT__i, __Vtask_tb__DOT__run__18__words.size())) {
        vlSelfRef.tb__DOT__sd = __Vtask_tb__DOT__run__18__words.at(__Vtask_tb__DOT__run__18__unnamedblk2__DOT__i);
        vlSelfRef.tb__DOT__sv = 1U;
        while ((1U & (~ (IData)(vlSelfRef.tb__DOT__sr)))) {
            Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                      "@(negedge tb.clk)");
            co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb.clk)", 
                                                                 "tb_salsa.sv", 
                                                                 69);
        }
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             70);
        __Vtask_tb__DOT__run__18__unnamedblk2__DOT__i 
            = ((IData)(1U) + __Vtask_tb__DOT__run__18__unnamedblk2__DOT__i);
    }
    vlSelfRef.tb__DOT__sv = 0U;
    do {
        __Vtask_tb__DOT__reg_read__21__a = 4U;
        __Vtask_tb__DOT__reg_read__21__d = 0;
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             36);
        vlSelfRef.tb__DOT__ara = __Vtask_tb__DOT__reg_read__21__a;
        vlSelfRef.tb__DOT__arv = 1U;
        while (vlSelfRef.tb__DOT__rv) {
            Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                      "@(negedge tb.clk)");
            co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb.clk)", 
                                                                 "tb_salsa.sv", 
                                                                 37);
        }
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             38);
        vlSelfRef.tb__DOT__arv = 0U;
        while ((1U & (~ (IData)(vlSelfRef.tb__DOT__rv)))) {
            Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                      "@(negedge tb.clk)");
            co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb.clk)", 
                                                                 "tb_salsa.sv", 
                                                                 39);
        }
        __Vtask_tb__DOT__reg_read__21__d = vlSelfRef.tb__DOT__rd;
        Vtb___024root____VbeforeTrig_h6018ce40__0(vlSelf, 
                                                  "@(negedge tb.clk)");
        co_await vlSelfRef.__VtrigSched_h6018ce40__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb.clk)", 
                                                             "tb_salsa.sv", 
                                                             40);
        __Vtask_tb__DOT__run__18__st = __Vtask_tb__DOT__reg_read__21__d;
    } while ((1U & (~ __Vtask_tb__DOT__run__18__st)));
    if (VL_UNLIKELY(((vlSelfRef.tb__DOT__got != vlSelfRef.tb__DOT__n_run)))) {
        vlSelfRef.tb__DOT__errors = ((IData)(1U) + vlSelfRef.tb__DOT__errors);
        VL_WRITEF_NX("ERROR: got %0d of %0d\n",2, '~',32,vlSelfRef.tb__DOT__got
                     , '~',32,vlSelfRef.tb__DOT__n_run);
    }
    VL_WRITEF_NX("queries with backpressure: 20000 checked\n%s (%0d errors)\n",2
                 , '#',32,((0U == vlSelfRef.tb__DOT__errors)
                            ? 0x50415353U : 0x4641494cU)
                 , '~',32,vlSelfRef.tb__DOT__errors);
    VL_FINISH_MT("tb_salsa.sv", 128, "");
    co_return;
}

VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "tb_salsa.sv", 
                                             10);
        vlSelfRef.tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb__DOT__clk)));
    }
    co_return;
}

bool Vtb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

bool Vtb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlWide<15>/*479:0*/ Vtb__ConstPool__CONST_hbd99daea_0;

void Vtb___024root___nba_sequent__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r;
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r = 0;
    SData/*11:0*/ tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r;
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_0;
    __VdfgRegularize_hebeb780c_0_0 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_3;
    __VdfgRegularize_hebeb780c_0_3 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_4;
    __VdfgRegularize_hebeb780c_0_4 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_6;
    __VdfgRegularize_hebeb780c_0_6 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_7;
    __VdfgRegularize_hebeb780c_0_7 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_9;
    __VdfgRegularize_hebeb780c_0_9 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_10;
    __VdfgRegularize_hebeb780c_0_10 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_11;
    __VdfgRegularize_hebeb780c_0_11 = 0;
    IData/*31:0*/ __Vdly__tb__DOT__dut__DOT__pushed;
    __Vdly__tb__DOT__dut__DOT__pushed = 0;
    CData/*4:0*/ __Vdly__tb__DOT__dut__DOT__rp;
    __Vdly__tb__DOT__dut__DOT__rp = 0;
    CData/*7:0*/ __Vdly__tb__DOT__dut__DOT__count;
    __Vdly__tb__DOT__dut__DOT__count = 0;
    IData/*31:0*/ __Vdly__tb__DOT__dut__DOT__req_count;
    __Vdly__tb__DOT__dut__DOT__req_count = 0;
    CData/*0:0*/ __Vdly__tb__DOT__dut__DOT__timing;
    __Vdly__tb__DOT__dut__DOT__timing = 0;
    IData/*31:0*/ __Vdly__tb__DOT__dut__DOT__cycles;
    __Vdly__tb__DOT__dut__DOT__cycles = 0;
    IData/*31:0*/ __Vdly__tb__DOT__dut__DOT__latency;
    __Vdly__tb__DOT__dut__DOT__latency = 0;
    IData/*31:0*/ __Vdly__tb__DOT__dut__DOT__res_count;
    __Vdly__tb__DOT__dut__DOT__res_count = 0;
    CData/*0:0*/ __Vdly__tb__DOT__dut__DOT__wr;
    __Vdly__tb__DOT__dut__DOT__wr = 0;
    VlWide<16>/*511:0*/ __Vdly__tb__DOT__dut__DOT__bank_stores;
    VL_ZERO_W(512, __Vdly__tb__DOT__dut__DOT__bank_stores);
    IData/*31:0*/ __Vdly__tb__DOT__dut__DOT__root_stores;
    __Vdly__tb__DOT__dut__DOT__root_stores = 0;
    VlWide<3>/*64:0*/ __VdlyVal__tb__DOT__dut__DOT__fifo__v0;
    VL_ZERO_W(65, __VdlyVal__tb__DOT__dut__DOT__fifo__v0);
    CData/*4:0*/ __VdlyDim0__tb__DOT__dut__DOT__fifo__v0;
    __VdlyDim0__tb__DOT__dut__DOT__fifo__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__fifo__v0;
    __VdlySet__tb__DOT__dut__DOT__fifo__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem__v0;
    __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem__v0;
    __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem__v0;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem__v0 = 0;
    // Body
    __Vdly__tb__DOT__dut__DOT__wr = vlSelfRef.tb__DOT__dut__DOT__wr;
    __Vdly__tb__DOT__dut__DOT__rp = vlSelfRef.tb__DOT__dut__DOT__rp;
    __Vdly__tb__DOT__dut__DOT__root_stores = vlSelfRef.tb__DOT__dut__DOT__root_stores;
    __Vdly__tb__DOT__dut__DOT__res_count = vlSelfRef.tb__DOT__dut__DOT__res_count;
    __Vdly__tb__DOT__dut__DOT__req_count = vlSelfRef.tb__DOT__dut__DOT__req_count;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem__v0 = 0U;
    __Vdly__tb__DOT__dut__DOT__count = vlSelfRef.tb__DOT__dut__DOT__count;
    __Vdly__tb__DOT__dut__DOT__timing = vlSelfRef.tb__DOT__dut__DOT__timing;
    __Vdly__tb__DOT__dut__DOT__cycles = vlSelfRef.tb__DOT__dut__DOT__cycles;
    __Vdly__tb__DOT__dut__DOT__latency = vlSelfRef.tb__DOT__dut__DOT__latency;
    __Vdly__tb__DOT__dut__DOT__bank_stores[0U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[0U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[1U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[1U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[2U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[2U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[3U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[3U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[4U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[4U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[5U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[5U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[6U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[6U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[7U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[7U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[8U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[8U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[9U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[9U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[10U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[10U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[11U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[11U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[12U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[12U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[13U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[13U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[14U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[14U];
    __Vdly__tb__DOT__dut__DOT__bank_stores[15U] = vlSelfRef.tb__DOT__dut__DOT__bank_stores[15U];
    __Vdly__tb__DOT__dut__DOT__pushed = vlSelfRef.tb__DOT__dut__DOT__pushed;
    __VdlySet__tb__DOT__dut__DOT__fifo__v0 = 0U;
    if (((IData)(vlSelfRef.tb__DOT__mv) & (IData)(vlSelfRef.tb__DOT__mr))) {
        vlSelfRef.tb__DOT__unnamedblk1__DOT__r = vlSelfRef.tb__DOT__md;
        vlSelfRef.tb__DOT__unnamedblk1__DOT__e = vlSelfRef.tb__DOT__expect_q.pop_front();
        if ((vlSelfRef.tb__DOT__unnamedblk1__DOT__r 
             != vlSelfRef.tb__DOT__unnamedblk1__DOT__e)) {
            vlSelfRef.tb__DOT__errors = ((IData)(1U) 
                                         + vlSelfRef.tb__DOT__errors);
            if (VL_UNLIKELY((VL_GTS_III(32, 5U, vlSelfRef.tb__DOT__errors)))) {
                VL_WRITEF_NX("ERROR key %0d: got %0d want %0d\n",3
                             , '#',16,(0x0000ffffU 
                                       & (IData)((vlSelfRef.tb__DOT__unnamedblk1__DOT__e 
                                                  >> 0x00000020U)))
                             , '#',32,(IData)(vlSelfRef.tb__DOT__unnamedblk1__DOT__r)
                             , '#',32,(IData)(vlSelfRef.tb__DOT__unnamedblk1__DOT__e));
            }
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.tb__DOT__ml) 
                          != (vlSelfRef.tb__DOT__got 
                              == (vlSelfRef.tb__DOT__n_run 
                                  - (IData)(1U))))))) {
            vlSelfRef.tb__DOT__errors = ((IData)(1U) 
                                         + vlSelfRef.tb__DOT__errors);
            VL_WRITEF_NX("ERROR: tlast at %0d\n",1, '~',32,vlSelfRef.tb__DOT__got);
        }
        vlSelfRef.tb__DOT__got = ((IData)(1U) + vlSelfRef.tb__DOT__got);
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem__v0 
            = (0x00000fffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[0U]);
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 1U))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem__v0 
            = (0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[0U] 
                              >> 0x0000000cU));
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 2U))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem__v0 
            = (0x00000fffU & ((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[1U] 
                               << 8U) | (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[0U] 
                                         >> 0x00000018U)));
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 3U))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem__v0 
            = (0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[1U] 
                              >> 4U));
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 4U))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem__v0 
            = (0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[1U] 
                              >> 0x00000010U));
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 5U))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem__v0 
            = (0x00000fffU & ((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[2U] 
                               << 4U) | (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[1U] 
                                         >> 0x0000001cU)));
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 6U))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem__v0 
            = (0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[2U] 
                              >> 8U));
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 7U))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem__v0 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[2U] 
               >> 0x00000014U);
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 8U))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem__v0 
            = (0x00000fffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[3U]);
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 9U))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem__v0 
            = (0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[3U] 
                              >> 0x0000000cU));
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 0x0aU))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem__v0 
            = (0x00000fffU & ((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[4U] 
                               << 8U) | (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[3U] 
                                         >> 0x00000018U)));
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 0x0bU))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem__v0 
            = (0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[4U] 
                              >> 4U));
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 0x0cU))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem__v0 
            = (0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[4U] 
                              >> 0x00000010U));
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 0x0dU))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem__v0 
            = (0x00000fffU & ((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[5U] 
                               << 4U) | (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[4U] 
                                         >> 0x0000001cU)));
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 0x0eU))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem__v0 
            = (0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[5U] 
                              >> 8U));
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 0x0fU))) {
        __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem__v0 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
        __VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem__v0 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[5U] 
               >> 0x00000014U);
        __VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem__v0 = 1U;
    }
    if (vlSelfRef.tb__DOT__dut__DOT__out_valid) {
        __VdlyVal__tb__DOT__dut__DOT__fifo__v0[0U] 
            = (IData)(vlSelfRef.tb__DOT__dut__DOT__out_word);
        __VdlyVal__tb__DOT__dut__DOT__fifo__v0[1U] 
            = (IData)((vlSelfRef.tb__DOT__dut__DOT__out_word 
                       >> 0x00000020U));
        __VdlyVal__tb__DOT__dut__DOT__fifo__v0[2U] 
            = (vlSelfRef.tb__DOT__dut__DOT__pushed 
               == (vlSelfRef.tb__DOT__dut__DOT__run_len 
                   - (IData)(1U)));
        __VdlyDim0__tb__DOT__dut__DOT__fifo__v0 = vlSelfRef.tb__DOT__dut__DOT__wp;
        __VdlySet__tb__DOT__dut__DOT__fifo__v0 = 1U;
    }
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
        = (((QData)((IData)((((((0x000000f0U & ((IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
                                                         >> 4U)) 
                                                << 4U)) 
                                | (0x0000000fU & (IData)(
                                                         (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
                                                          >> 8U)))) 
                               << 0x00000018U) | ((
                                                   (0x000000f0U 
                                                    & ((IData)(
                                                               (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
                                                                >> 0x0000000cU)) 
                                                       << 4U)) 
                                                   | (0x0000000fU 
                                                      & (IData)(
                                                                (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
                                                                 >> 0x00000010U)))) 
                                                  << 0x00000010U)) 
                             | ((((0x000000f0U & ((IData)(
                                                          (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
                                                           >> 0x00000014U)) 
                                                  << 4U)) 
                                  | (0x0000000fU & (IData)(
                                                           (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
                                                            >> 0x00000018U)))) 
                                 << 8U) | ((0x000000f0U 
                                            & ((IData)(
                                                       (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
                                                        >> 0x0000001cU)) 
                                               << 4U)) 
                                           | (0x0000000fU 
                                              & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
                                                         >> 0x00000020U)))))))) 
            << 0x00000010U) | (QData)((IData)(((((0x000000f0U 
                                                  & ((IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
                                                              >> 0x00000024U)) 
                                                     << 4U)) 
                                                 | (0x0000000fU 
                                                    & (IData)(
                                                              (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
                                                               >> 0x00000028U)))) 
                                                << 8U) 
                                               | ((0x000000f0U 
                                                   & ((IData)(
                                                              (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
                                                               >> 0x0000002cU)) 
                                                      << 4U)) 
                                                  | (0x0000000fU 
                                                     & (IData)(
                                                               (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
                                                                >> 0x00000030U))))))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc 
        = (0x0000000fU & (IData)((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
                                  >> 0x00000030U)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                          >> 0x0000000cU));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo 
        = (0x00000fffU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__hi = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_hi;
    vlSelfRef.tb__DOT__rv = ((IData)(vlSelfRef.tb__DOT__rstn) 
                             && ((IData)(vlSelfRef.tb__DOT__arv) 
                                 & (IData)(vlSelfRef.tb__DOT__arr)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__iss_write 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw;
    vlSelfRef.tb__DOT__rd = ((1U == (0x0000003fU & 
                                     ((IData)(vlSelfRef.tb__DOT__ara) 
                                      >> 2U))) ? (IData)(vlSelfRef.tb__DOT__dut__DOT__done)
                              : ((2U == (0x0000003fU 
                                         & ((IData)(vlSelfRef.tb__DOT__ara) 
                                            >> 2U)))
                                  ? vlSelfRef.tb__DOT__dut__DOT__run_len
                                  : ((3U == (0x0000003fU 
                                             & ((IData)(vlSelfRef.tb__DOT__ara) 
                                                >> 2U)))
                                      ? vlSelfRef.tb__DOT__dut__DOT__cycles
                                      : ((4U == (0x0000003fU 
                                                 & ((IData)(vlSelfRef.tb__DOT__ara) 
                                                    >> 2U)))
                                          ? vlSelfRef.tb__DOT__dut__DOT__req_count
                                          : ((5U == 
                                              (0x0000003fU 
                                               & ((IData)(vlSelfRef.tb__DOT__ara) 
                                                  >> 2U)))
                                              ? vlSelfRef.tb__DOT__dut__DOT__res_count
                                              : ((6U 
                                                  == 
                                                  (0x0000003fU 
                                                   & ((IData)(vlSelfRef.tb__DOT__ara) 
                                                      >> 2U)))
                                                  ? vlSelfRef.tb__DOT__dut__DOT__latency
                                                  : 
                                                 ((0x20U 
                                                   == 
                                                   (0x0000003fU 
                                                    & ((IData)(vlSelfRef.tb__DOT__ara) 
                                                       >> 2U)))
                                                   ? vlSelfRef.tb__DOT__dut__DOT__root_stores
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (3U 
                                                     & ((IData)(vlSelfRef.tb__DOT__ara) 
                                                        >> 6U)))
                                                    ? vlSelfRef.tb__DOT__dut__DOT__bank_stores
                                                   [
                                                   (0x0000000fU 
                                                    & ((IData)(vlSelfRef.tb__DOT__ara) 
                                                       >> 2U))]
                                                    : 0U))))))));
    if ((1U & ((~ (IData)(vlSelfRef.tb__DOT__rstn)) 
               | (IData)(vlSelfRef.tb__DOT__dut__DOT__start)))) {
        __Vdly__tb__DOT__dut__DOT__res_count = 0U;
        __Vdly__tb__DOT__dut__DOT__req_count = 0U;
        __Vdly__tb__DOT__dut__DOT__timing = 0U;
        __Vdly__tb__DOT__dut__DOT__cycles = 0U;
        __Vdly__tb__DOT__dut__DOT__latency = 0U;
        __Vdly__tb__DOT__dut__DOT__pushed = 0U;
        vlSelfRef.tb__DOT__dut__DOT__got_first = 0U;
        vlSelfRef.tb__DOT__dut__DOT__done = 0U;
    } else {
        __Vdly__tb__DOT__dut__DOT__res_count = (vlSelfRef.tb__DOT__dut__DOT__res_count 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__send));
        __Vdly__tb__DOT__dut__DOT__req_count = (vlSelfRef.tb__DOT__dut__DOT__req_count 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__accept));
        if ((((IData)(vlSelfRef.tb__DOT__dut__DOT__accept) 
              & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__timing))) 
             & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__done)))) {
            __Vdly__tb__DOT__dut__DOT__timing = 1U;
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__timing) 
             | ((IData)(vlSelfRef.tb__DOT__dut__DOT__accept) 
                & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__done))))) {
            __Vdly__tb__DOT__dut__DOT__cycles = ((IData)(1U) 
                                                 + vlSelfRef.tb__DOT__dut__DOT__cycles);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__timing) 
             & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__got_first)))) {
            __Vdly__tb__DOT__dut__DOT__latency = ((IData)(1U) 
                                                  + vlSelfRef.tb__DOT__dut__DOT__latency);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__send) 
             & (IData)(vlSelfRef.tb__DOT__ml))) {
            __Vdly__tb__DOT__dut__DOT__timing = 0U;
            vlSelfRef.tb__DOT__dut__DOT__done = 1U;
        }
        if (vlSelfRef.tb__DOT__dut__DOT__out_valid) {
            __Vdly__tb__DOT__dut__DOT__pushed = ((IData)(1U) 
                                                 + vlSelfRef.tb__DOT__dut__DOT__pushed);
        }
        if (vlSelfRef.tb__DOT__dut__DOT__send) {
            vlSelfRef.tb__DOT__dut__DOT__got_first = 1U;
        }
    }
    if (vlSelfRef.tb__DOT__rstn) {
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & (0U != (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag)))) {
            __Vdly__tb__DOT__dut__DOT__root_stores 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__root_stores);
        }
        vlSelfRef.tb__DOT__dut__DOT__in_flight = (0x000000ffU 
                                                  & (((IData)(vlSelfRef.tb__DOT__dut__DOT__in_flight) 
                                                      + (IData)(vlSelfRef.tb__DOT__dut__DOT__accept)) 
                                                     - (IData)(vlSelfRef.tb__DOT__dut__DOT__out_valid)));
        __Vdly__tb__DOT__dut__DOT__count = (0x000000ffU 
                                            & (((IData)(vlSelfRef.tb__DOT__dut__DOT__count) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__out_valid)) 
                                               - (IData)(vlSelfRef.tb__DOT__dut__DOT__load)));
        if ((1U & ((~ (IData)(vlSelfRef.tb__DOT__mv)) 
                   | (IData)(vlSelfRef.tb__DOT__mr)))) {
            vlSelfRef.tb__DOT__mv = (0U != (IData)(vlSelfRef.tb__DOT__dut__DOT__count));
        }
        vlSelfRef.tb__DOT__dut__DOT__count = __Vdly__tb__DOT__dut__DOT__count;
        vlSelfRef.tb__DOT__dut__DOT__timing = __Vdly__tb__DOT__dut__DOT__timing;
        vlSelfRef.tb__DOT__dut__DOT__pushed = __Vdly__tb__DOT__dut__DOT__pushed;
        vlSelfRef.tb__DOT__dut__DOT__cycles = __Vdly__tb__DOT__dut__DOT__cycles;
        vlSelfRef.tb__DOT__dut__DOT__req_count = __Vdly__tb__DOT__dut__DOT__req_count;
        vlSelfRef.tb__DOT__dut__DOT__res_count = __Vdly__tb__DOT__dut__DOT__res_count;
        vlSelfRef.tb__DOT__dut__DOT__latency = __Vdly__tb__DOT__dut__DOT__latency;
        vlSelfRef.tb__DOT__dut__DOT__root_stores = __Vdly__tb__DOT__dut__DOT__root_stores;
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[0U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[0U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 1U))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[1U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[1U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 2U))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[2U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[2U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 3U))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[3U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[3U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 4U))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[4U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[4U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 5U))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[5U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[5U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 6U))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[6U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[6U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 7U))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[7U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[7U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 8U))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[8U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[8U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 9U))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[9U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[9U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 0x0aU))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[10U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[10U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 0x0bU))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[11U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[11U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 0x0cU))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[12U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[12U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 0x0dU))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[13U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[13U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 0x0eU))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[14U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[14U]);
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
                >> 0x0fU))) {
            __Vdly__tb__DOT__dut__DOT__bank_stores[15U] 
                = ((IData)(1U) + vlSelfRef.tb__DOT__dut__DOT__bank_stores[15U]);
        }
    } else {
        __Vdly__tb__DOT__dut__DOT__root_stores = 0U;
        vlSelfRef.tb__DOT__dut__DOT__in_flight = 0U;
        __Vdly__tb__DOT__dut__DOT__count = 0U;
        vlSelfRef.tb__DOT__mv = 0U;
        vlSelfRef.tb__DOT__dut__DOT__count = __Vdly__tb__DOT__dut__DOT__count;
        vlSelfRef.tb__DOT__dut__DOT__timing = __Vdly__tb__DOT__dut__DOT__timing;
        vlSelfRef.tb__DOT__dut__DOT__pushed = __Vdly__tb__DOT__dut__DOT__pushed;
        vlSelfRef.tb__DOT__dut__DOT__cycles = __Vdly__tb__DOT__dut__DOT__cycles;
        vlSelfRef.tb__DOT__dut__DOT__req_count = __Vdly__tb__DOT__dut__DOT__req_count;
        vlSelfRef.tb__DOT__dut__DOT__res_count = __Vdly__tb__DOT__dut__DOT__res_count;
        vlSelfRef.tb__DOT__dut__DOT__latency = __Vdly__tb__DOT__dut__DOT__latency;
        vlSelfRef.tb__DOT__dut__DOT__root_stores = __Vdly__tb__DOT__dut__DOT__root_stores;
        __Vdly__tb__DOT__dut__DOT__bank_stores[0U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[1U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[2U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[3U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[4U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[5U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[6U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[7U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[8U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[9U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[10U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[11U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[12U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[13U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[14U] = 0U;
        __Vdly__tb__DOT__dut__DOT__bank_stores[15U] = 0U;
    }
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[0U] = __Vdly__tb__DOT__dut__DOT__bank_stores[0U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[1U] = __Vdly__tb__DOT__dut__DOT__bank_stores[1U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[2U] = __Vdly__tb__DOT__dut__DOT__bank_stores[2U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[3U] = __Vdly__tb__DOT__dut__DOT__bank_stores[3U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[4U] = __Vdly__tb__DOT__dut__DOT__bank_stores[4U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[5U] = __Vdly__tb__DOT__dut__DOT__bank_stores[5U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[6U] = __Vdly__tb__DOT__dut__DOT__bank_stores[6U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[7U] = __Vdly__tb__DOT__dut__DOT__bank_stores[7U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[8U] = __Vdly__tb__DOT__dut__DOT__bank_stores[8U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[9U] = __Vdly__tb__DOT__dut__DOT__bank_stores[9U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[10U] = __Vdly__tb__DOT__dut__DOT__bank_stores[10U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[11U] = __Vdly__tb__DOT__dut__DOT__bank_stores[11U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[12U] = __Vdly__tb__DOT__dut__DOT__bank_stores[12U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[13U] = __Vdly__tb__DOT__dut__DOT__bank_stores[13U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[14U] = __Vdly__tb__DOT__dut__DOT__bank_stores[14U];
    vlSelfRef.tb__DOT__dut__DOT__bank_stores[15U] = __Vdly__tb__DOT__dut__DOT__bank_stores[15U];
    vlSelfRef.tb__DOT__mr = (1U & ((~ (IData)(vlSelfRef.tb__DOT__backpressure)) 
                                   | (0U != VL_MODDIV_III(32, (IData)(
                                                                      VL_RANDOM_I()), (IData)(3U)))));
    if (vlSelfRef.tb__DOT__rstn) {
        if (vlSelfRef.tb__DOT__dut__DOT__out_valid) {
            vlSelfRef.tb__DOT__dut__DOT__wp = (0x0000001fU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.tb__DOT__dut__DOT__wp)));
        }
        vlSelfRef.tb__DOT__dut__DOT__out_valid = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__v3;
    } else {
        vlSelfRef.tb__DOT__dut__DOT__wp = 0U;
        vlSelfRef.tb__DOT__dut__DOT__out_valid = 0U;
    }
    vlSelfRef.tb__DOT__dut__DOT__out_word = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__x3;
    if ((0U == (3U & (IData)((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__x3 
                              >> 0x0000003eU))))) {
        vlSelfRef.tb__DOT__dut__DOT__out_word = ((0xffffffff00000000ULL 
                                                  & vlSelfRef.tb__DOT__dut__DOT__out_word) 
                                                 | (IData)((IData)(
                                                                   ((((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__part[0U] 
                                                                       + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__part[1U]) 
                                                                      + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__part[2U]) 
                                                                     + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__part[3U]) 
                                                                    + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rs3))));
    }
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_hi 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                          >> 0x0cU));
    vlSelfRef.tb__DOT__arr = (1U & (~ (IData)(vlSelfRef.tb__DOT__rv)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__iw;
    if (vlSelfRef.tb__DOT__rstn) {
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store) 
             & (0U != (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag)))) {
            if ((1U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[0U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((2U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[1U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[2U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((8U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[3U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((0x00000010U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[4U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((0x00000020U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[5U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((0x00000040U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[6U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((0x00000080U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[7U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((0x00000100U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[8U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((0x00000200U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[9U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((0x00000400U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[10U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((0x00000800U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[11U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((0x00001000U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[12U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((0x00002000U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[13U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
            if ((0x00004000U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
                vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[14U] 
                    = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data;
            }
        }
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_d;
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__lane 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_rv;
    } else {
        VL_ASSIGN_W(480, vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root, Vtb__ConstPool__CONST_hbd99daea_0);
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__data 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_d;
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__lane = 0U;
    }
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_rv 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__iv)
            ? (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__iw)
                               ? (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                                   >> 0x0000000cU) 
                                  & (((IData)(1U) + 
                                      (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                                          >> 0x0000000cU))) 
                                     & (- (IData)((0U 
                                                   == 
                                                   (0x00000fffU 
                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix)))))))
                               : ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                                  >> 0x0000000cU)))
            : 0U);
    vlSelfRef.tb__DOT__dut__DOT__send = ((IData)(vlSelfRef.tb__DOT__mv) 
                                         & (IData)(vlSelfRef.tb__DOT__mr));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__v3 = ((IData)(vlSelfRef.tb__DOT__rstn) 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__v2));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rs3 = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rs2;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__x3 = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__x2;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__part[0U] 
        = ((8U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2))
            ? (vlSelfRef.__VdfgRegularize_hebeb780c_0_1 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[3U])
            : vlSelfRef.__VdfgRegularize_hebeb780c_0_1);
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__part[1U] 
        = ((0x00000080U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2))
            ? (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[7U] 
               + vlSelfRef.__VdfgRegularize_hebeb780c_0_8)
            : vlSelfRef.__VdfgRegularize_hebeb780c_0_8);
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__part[2U] 
        = ((0x00000800U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2))
            ? (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[11U] 
               + vlSelfRef.__VdfgRegularize_hebeb780c_0_5)
            : vlSelfRef.__VdfgRegularize_hebeb780c_0_5);
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__part[3U] 
        = ((0x00008000U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2))
            ? (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[15U] 
               + vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
            : vlSelfRef.__VdfgRegularize_hebeb780c_0_2);
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_d 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__id;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__iw 
        = (1U == (3U & (IData)((vlSelfRef.tb__DOT__sd 
                                >> 0x0000003eU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix 
        = (0x0000ffffU & (IData)((vlSelfRef.tb__DOT__sd 
                                  >> 0x00000020U)));
    if (vlSelfRef.tb__DOT__dut__DOT__load) {
        vlSelfRef.tb__DOT__ml = (1U & vlSelfRef.tb__DOT__dut__DOT__fifo
                                 [vlSelfRef.tb__DOT__dut__DOT__rp][2U]);
        vlSelfRef.tb__DOT__md = (((QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__fifo
                                                  [vlSelfRef.tb__DOT__dut__DOT__rp][1U])) 
                                  << 0x00000020U) | (QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__fifo
                                                                    [vlSelfRef.tb__DOT__dut__DOT__rp][0U])));
    }
    __Vdly__tb__DOT__dut__DOT__wr = ((((IData)(vlSelfRef.tb__DOT__rstn) 
                                       & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__wr))) 
                                      & (IData)(vlSelfRef.tb__DOT__awv)) 
                                     & (IData)(vlSelfRef.tb__DOT__wv));
    vlSelfRef.tb__DOT__dut__DOT__start = (((IData)(vlSelfRef.tb__DOT__dut__DOT__wr) 
                                           & (0U == 
                                              (0xfcU 
                                               & (IData)(vlSelfRef.tb__DOT__awa)))) 
                                          & vlSelfRef.tb__DOT__wd);
    vlSelfRef.tb__DOT__bv = ((IData)(vlSelfRef.tb__DOT__rstn) 
                             && (IData)(vlSelfRef.tb__DOT__dut__DOT__wr));
    if (vlSelfRef.tb__DOT__rstn) {
        if (vlSelfRef.tb__DOT__dut__DOT__load) {
            __Vdly__tb__DOT__dut__DOT__rp = (0x0000001fU 
                                             & ((IData)(1U) 
                                                + (IData)(vlSelfRef.tb__DOT__dut__DOT__rp)));
        }
    } else {
        __Vdly__tb__DOT__dut__DOT__rp = 0U;
    }
    vlSelfRef.tb__DOT__dut__DOT__rp = __Vdly__tb__DOT__dut__DOT__rp;
    if (__VdlySet__tb__DOT__dut__DOT__fifo__v0) {
        vlSelfRef.tb__DOT__dut__DOT__fifo[__VdlyDim0__tb__DOT__dut__DOT__fifo__v0][0U] 
            = __VdlyVal__tb__DOT__dut__DOT__fifo__v0[0U];
        vlSelfRef.tb__DOT__dut__DOT__fifo[__VdlyDim0__tb__DOT__dut__DOT__fifo__v0][1U] 
            = __VdlyVal__tb__DOT__dut__DOT__fifo__v0[1U];
        vlSelfRef.tb__DOT__dut__DOT__fifo[__VdlyDim0__tb__DOT__dut__DOT__fifo__v0][2U] 
            = __VdlyVal__tb__DOT__dut__DOT__fifo__v0[2U];
    }
    vlSelfRef.tb__DOT__dut__DOT__load = (((~ (IData)(vlSelfRef.tb__DOT__mv)) 
                                          | (IData)(vlSelfRef.tb__DOT__mr)) 
                                         & (0U != (IData)(vlSelfRef.tb__DOT__dut__DOT__count)));
    if (vlSelfRef.tb__DOT__rstn) {
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__wr) 
             & (8U == (0xfcU & (IData)(vlSelfRef.tb__DOT__awa))))) {
            vlSelfRef.tb__DOT__dut__DOT__run_len = vlSelfRef.tb__DOT__wd;
        }
        vlSelfRef.tb__DOT__dut__DOT__wr = __Vdly__tb__DOT__dut__DOT__wr;
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__v2 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__v1;
    } else {
        vlSelfRef.tb__DOT__dut__DOT__run_len = 0U;
        vlSelfRef.tb__DOT__dut__DOT__wr = __Vdly__tb__DOT__dut__DOT__wr;
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__v2 = 0U;
    }
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rs2 = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rs1;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__x2 = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__x1;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2 = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en1;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[0U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__q;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[1U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__q;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[2U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__q)) 
                    << 0x00000020U) | (QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__q))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[3U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__q)) 
                     << 0x00000020U) | (QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__q))) 
                   >> 0x00000020U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[4U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__q;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[5U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__q;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[6U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__q)) 
                    << 0x00000020U) | (QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__q))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[7U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__q)) 
                     << 0x00000020U) | (QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__q))) 
                   >> 0x00000020U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[8U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__q;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[9U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__q;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[10U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__q)) 
                    << 0x00000020U) | (QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__q))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[11U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__q)) 
                     << 0x00000020U) | (QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__q))) 
                   >> 0x00000020U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[12U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__q;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[13U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__q;
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[14U] 
        = (IData)((((QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__q)) 
                    << 0x00000020U) | (QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__q))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[15U] 
        = (IData)(((((QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__q)) 
                     << 0x00000020U) | (QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__q))) 
                   >> 0x00000020U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__id 
        = (IData)(vlSelfRef.tb__DOT__sd);
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r 
        = (((((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                     << 2U)) | ((2U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix)) 
                                | (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                                         >> 2U)))) 
             << 9U) | (((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                               >> 1U)) | ((2U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                                                 >> 3U)) 
                                          | (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                                                   >> 5U)))) 
                       << 6U)) | ((((4U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                                           >> 4U)) 
                                    | ((2U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                                              >> 6U)) 
                                       | (1U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                                                >> 8U)))) 
                                   << 3U) | ((4U & 
                                              ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                                               >> 7U)) 
                                             | ((2U 
                                                 & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                                                    >> 9U)) 
                                                | (1U 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__ix) 
                                                      >> 0x0000000bU))))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][0U] 
        = (1U & (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][1U] 
        = (1U & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r) 
                 >> 1U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][2U] 
        = (1U & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r) 
                 >> 2U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][3U] 
        = (1U & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r) 
                 >> 3U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][4U] 
        = (1U & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r) 
                 >> 4U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][5U] 
        = (1U & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r) 
                 >> 5U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][6U] 
        = (1U & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r) 
                 >> 6U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][7U] 
        = (1U & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r) 
                 >> 7U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][8U] 
        = (1U & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r) 
                 >> 8U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][9U] 
        = (1U & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r) 
                 >> 9U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][10U] 
        = (1U & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r) 
                 >> 0x0aU));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][11U] 
        = (1U & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__lo_r) 
                 >> 0x0bU));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][0U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][0U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][1U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][1U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][0U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][2U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][2U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][3U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][3U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][2U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][4U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][4U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][5U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][5U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][4U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][6U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][6U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][7U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][7U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][6U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][8U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][8U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][9U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][9U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][8U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][10U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][10U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][11U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][11U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[0U][10U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][0U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][0U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][1U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][1U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][2U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][2U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][1U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][3U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][3U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][1U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][4U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][4U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][5U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][5U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][6U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][6U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][5U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][7U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][7U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][5U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][8U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][8U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][9U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][9U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][10U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][10U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][9U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][11U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][11U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[1U][9U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][0U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][0U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][1U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][1U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][2U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][2U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][3U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][3U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][4U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][4U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][3U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][5U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][5U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][3U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][6U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][6U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][3U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][7U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][7U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][3U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][8U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][8U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][9U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][9U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][10U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][10U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][11U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[2U][11U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][0U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][0U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][1U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][1U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][2U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][2U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][3U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][3U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][4U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][4U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][5U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][5U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][6U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][6U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][7U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][7U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][8U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][8U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][7U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][9U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][9U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][7U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][10U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][10U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][7U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][11U] 
        = (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][11U]) 
                          + (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[3U][7U])));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
        = ((0x000fffffffffff00ULL & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r) 
           | (IData)((IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][0U]) 
                              << 4U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
        = ((0x000fffffffff00ffULL & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r) 
           | ((QData)((IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][2U]) 
                                << 4U) | vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][1U]))) 
              << 8U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
        = ((0x000fffffff00ffffULL & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r) 
           | ((QData)((IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][4U]) 
                                << 4U) | vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][3U]))) 
              << 0x00000010U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
        = ((0x000fffff00ffffffULL & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r) 
           | ((QData)((IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][6U]) 
                                << 4U) | vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][5U]))) 
              << 0x00000018U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
        = ((0x000fff00ffffffffULL & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r) 
           | ((QData)((IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][8U]) 
                                << 4U) | vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][7U]))) 
              << 0x00000020U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
        = ((0x000f00ffffffffffULL & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r) 
           | ((QData)((IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][10U]) 
                                << 4U) | vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][9U]))) 
              << 0x00000028U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r 
        = ((0x0000ffffffffffffULL & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__pcb_r) 
           | ((QData)((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__u_chain__DOT__u_pc__DOT__s[4U][11U])) 
              << 0x00000030U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__v1 = ((IData)(vlSelfRef.tb__DOT__rstn) 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__iss_valid));
    if (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rs1 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum;
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en1 
            = (0x0000ffffU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en));
    } else {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rs1 = 0U;
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en1 = 0U;
    }
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__x1 = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__w2;
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem
            [(0x00000fffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[0U])];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 1U))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem
            [(0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[0U] 
                             >> 0x0000000cU))];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 2U))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem
            [(0x00000fffU & ((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[1U] 
                              << 8U) | (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[0U] 
                                        >> 0x00000018U)))];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 3U))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem
            [(0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[1U] 
                             >> 4U))];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 4U))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem
            [(0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[1U] 
                             >> 0x00000010U))];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 5U))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem
            [(0x00000fffU & ((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[2U] 
                              << 4U) | (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[1U] 
                                        >> 0x0000001cU)))];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 6U))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem
            [(0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[2U] 
                             >> 8U))];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 7U))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem
            [(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[2U] 
              >> 0x00000014U)];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 8U))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem
            [(0x00000fffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[3U])];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 9U))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem
            [(0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[3U] 
                             >> 0x0000000cU))];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 0x0aU))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem
            [(0x00000fffU & ((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[4U] 
                              << 8U) | (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[3U] 
                                        >> 0x00000018U)))];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 0x0bU))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem
            [(0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[4U] 
                             >> 4U))];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 0x0cU))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem
            [(0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[4U] 
                             >> 0x00000010U))];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 0x0dU))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem
            [(0x00000fffU & ((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[5U] 
                              << 4U) | (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[4U] 
                                        >> 0x0000001cU)))];
    }
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 0x0eU))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem
            [(0x00000fffU & (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[5U] 
                             >> 8U))];
    }
    __VdfgRegularize_hebeb780c_0_4 = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[12U] 
                                      & (- (IData)(
                                                   (1U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2) 
                                                       >> 0x0000000cU)))));
    __VdfgRegularize_hebeb780c_0_7 = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[8U] 
                                      & (- (IData)(
                                                   (1U 
                                                    & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2) 
                                                       >> 8U)))));
    __VdfgRegularize_hebeb780c_0_10 = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[4U] 
                                       & (- (IData)(
                                                    (1U 
                                                     & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2) 
                                                        >> 4U)))));
    __VdfgRegularize_hebeb780c_0_11 = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[0U] 
                                       & (- (IData)(
                                                    (1U 
                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2)))));
    if (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query) 
         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en) 
            >> 0x0fU))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__q 
            = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem
            [(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[5U] 
              >> 0x00000014U)];
    }
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en = ((IData)(vlSelfRef.tb__DOT__rstn)
                                                   ? (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)
                                                   : 0U);
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag = 0U;
    if ((1U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__lane))) {
        if ((0x0eU >= (0x0000000fU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__hi) 
                                      - (IData)(1U))))) {
            vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag 
                = ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag) 
                   | (0x7fffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__hi) 
                                                    - (IData)(1U))))));
        }
    }
    if ((2U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__lane))) {
        if ((0x0eU >= (0x0000000fU & ((0x0eU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__hi)) 
                                      - (IData)(1U))))) {
            vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag 
                = ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag) 
                   | (0x7fffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((0x0eU 
                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__hi)) 
                                                    - (IData)(1U))))));
        }
    }
    if ((4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__lane))) {
        if ((0x0eU >= (0x0000000fU & ((0x0cU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__hi)) 
                                      - (IData)(1U))))) {
            vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag 
                = ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag) 
                   | (0x7fffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((0x0cU 
                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__hi)) 
                                                    - (IData)(1U))))));
        }
    }
    if ((8U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__lane))) {
        if ((0x0eU >= (0x0000000fU & ((8U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__hi)) 
                                      - (IData)(1U))))) {
            vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag 
                = ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag) 
                   | (0x7fffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((8U 
                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__hi)) 
                                                    - (IData)(1U))))));
        }
    }
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum = 0U;
    if ((1U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[0U]);
    }
    if ((2U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[1U]);
    }
    if ((4U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[2U]);
    }
    if ((8U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[3U]);
    }
    if ((0x00000010U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[4U]);
    }
    if ((0x00000020U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[5U]);
    }
    if ((0x00000040U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[6U]);
    }
    if ((0x00000080U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[7U]);
    }
    if ((0x00000100U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[8U]);
    }
    if ((0x00000200U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[9U]);
    }
    if ((0x00000400U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[10U]);
    }
    if ((0x00000800U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[11U]);
    }
    if ((0x00001000U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[12U]);
    }
    if ((0x00002000U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[13U]);
    }
    if ((0x00004000U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rflag))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
            = (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root_sum 
               + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__root[14U]);
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__0__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__1__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__2__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__3__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__4__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__5__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__6__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__7__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__8__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__9__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__10__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__11__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__12__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__13__KET____DOT__mem__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__14__KET____DOT__mem__v0;
    }
    __VdfgRegularize_hebeb780c_0_3 = ((0x00002000U 
                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2))
                                       ? (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[13U] 
                                          + __VdfgRegularize_hebeb780c_0_4)
                                       : __VdfgRegularize_hebeb780c_0_4);
    __VdfgRegularize_hebeb780c_0_6 = ((0x00000200U 
                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2))
                                       ? (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[9U] 
                                          + __VdfgRegularize_hebeb780c_0_7)
                                       : __VdfgRegularize_hebeb780c_0_7);
    __VdfgRegularize_hebeb780c_0_9 = ((0x00000020U 
                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2))
                                       ? (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[5U] 
                                          + __VdfgRegularize_hebeb780c_0_10)
                                       : __VdfgRegularize_hebeb780c_0_10);
    __VdfgRegularize_hebeb780c_0_0 = ((2U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2))
                                       ? (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[1U] 
                                          + __VdfgRegularize_hebeb780c_0_11)
                                       : __VdfgRegularize_hebeb780c_0_11);
    if (__VdlySet__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem__v0) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem[__VdlyDim0__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem__v0] 
            = __VdlyVal__tb__DOT__dut__DOT__u_dp__DOT__g_bank__BRA__15__KET____DOT__mem__v0;
    }
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__iss_valid 
        = ((IData)(vlSelfRef.tb__DOT__rstn) && (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__w2 = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__w1;
    vlSelfRef.__VdfgRegularize_hebeb780c_0_2 = ((0x00004000U 
                                                 & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2))
                                                 ? 
                                                (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[14U] 
                                                 + __VdfgRegularize_hebeb780c_0_3)
                                                 : __VdfgRegularize_hebeb780c_0_3);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_5 = ((0x00000400U 
                                                 & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2))
                                                 ? 
                                                (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[10U] 
                                                 + __VdfgRegularize_hebeb780c_0_6)
                                                 : __VdfgRegularize_hebeb780c_0_6);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_8 = ((0x00000040U 
                                                 & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2))
                                                 ? 
                                                (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[6U] 
                                                 + __VdfgRegularize_hebeb780c_0_9)
                                                 : __VdfgRegularize_hebeb780c_0_9);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_1 = ((4U 
                                                 & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__en2))
                                                 ? 
                                                (__VdfgRegularize_hebeb780c_0_0 
                                                 + vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__rd[2U])
                                                 : __VdfgRegularize_hebeb780c_0_0);
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[0U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[1U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[2U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[3U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[4U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__set[5U] 
        = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U];
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__store = 
        ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__iss_valid) 
         & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__iss_write));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__query = 
        ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__iss_write)) 
         & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__iss_valid));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv 
        = ((IData)(vlSelfRef.tb__DOT__rstn) & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__iv));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__w1 = vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__w0;
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & (- (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xfffeU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | ((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
               & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                  <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
              & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                 | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                    == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfffffffeU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
              & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfffffffdU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xfffffffeU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 4U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 1U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfffffffbU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xfffffffcU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 8U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 2U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfffffff7U & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xfffffff8U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x0cU))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 3U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xffffffefU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xfffffff0U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x10U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 4U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xffffffdfU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xffffffe0U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x14U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 5U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xffffffbfU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xffffffc0U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x18U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 6U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xffffff7fU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xffffff80U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x1cU))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 7U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfffffeffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xffffff00U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x20U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 8U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfffffdffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xfffffe00U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x24U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 9U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfffffbffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xfffffc00U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x28U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 0x0000000aU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfffff7ffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xfffff800U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x2cU))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 0x0000000bU))));
    if ((1U & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
            = (0xfffff000U & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(1U) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xfffdU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 1U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xffffefffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 0x0000000cU));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xffffdfffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xffffe000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 4U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000000dU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xffffbfffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xffffc000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 8U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000000eU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xffff7fffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xffff8000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x0cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000000fU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfffeffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xffff0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x10U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000010U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfffdffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xfffe0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x14U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000011U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfffbffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xfffc0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x18U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000012U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfff7ffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xfff80000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x1cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000013U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xffefffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xfff00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x20U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000014U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xffdfffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xffe00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x24U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000015U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xffbfffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xffc00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x28U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000016U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xff7fffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xff800000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x2cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000017U))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 1U)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
            = (0xff000fffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(2U) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xfffbU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 2U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfeffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 0x00000018U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfdffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xfe000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 4U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000019U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xfbffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xfc000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 8U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001aU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xf7ffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xf8000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x0cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001bU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xefffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xf0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x10U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001cU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xdfffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xe0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x14U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001dU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0xbfffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0xc0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x18U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001eU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
        = ((0x7fffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]) 
           | (0x80000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x1cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001fU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfffffffeU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               >> 8U) & ((0x0000000fU & (IData)((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                 >> 0x20U))) 
                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfffffffdU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0x00fffffeU & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x24U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 1U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfffffffbU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0x00fffffcU & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x28U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 2U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfffffff7U & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0x00fffff8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x2cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 3U))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 2U)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U] 
            = (0x00ffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[0U]);
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
            = (0xfffffff0U & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(3U) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xfff7U & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 3U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xffffffefU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 4U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xffffffdfU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xffffffe0U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 4U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 5U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xffffffbfU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xffffffc0U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 8U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 6U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xffffff7fU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xffffff80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x0cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 7U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfffffeffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xffffff00U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x10U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 8U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfffffdffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xfffffe00U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x14U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 9U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfffffbffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xfffffc00U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x18U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000aU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfffff7ffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xfffff800U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x1cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000bU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xffffefffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xfffff000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x20U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000cU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xffffdfffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xffffe000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x24U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000dU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xffffbfffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xffffc000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x28U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000eU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xffff7fffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xffff8000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x2cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000fU))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 3U)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
            = (0xffff000fU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(4U) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xffefU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 4U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfffeffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 0x00000010U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfffdffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xfffe0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 4U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000011U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfffbffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xfffc0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 8U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000012U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfff7ffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xfff80000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x0cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000013U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xffefffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xfff00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x10U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000014U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xffdfffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xffe00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x14U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000015U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xffbfffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xffc00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x18U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000016U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xff7fffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xff800000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x1cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000017U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfeffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xff000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x20U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000018U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfdffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xfe000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x24U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000019U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xfbffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xfc000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x28U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001aU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xf7ffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xf8000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x2cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001bU))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 4U)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
            = (0xf000ffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(5U) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xffdfU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 5U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xefffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 0x0000001cU));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xdfffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xe0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000001cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 4U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001dU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0xbfffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0xc0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000001cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 8U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001eU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
        = ((0x7fffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]) 
           | (0x80000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000001cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x0cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001fU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfffffffeU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               >> 4U) & ((0x0000000fU & (IData)((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                 >> 0x10U))) 
                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfffffffdU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0x0ffffffeU & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x14U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 1U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfffffffbU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0x0ffffffcU & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x18U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 2U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfffffff7U & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0x0ffffff8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x1cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 3U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xffffffefU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0x0ffffff0U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x20U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 4U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xffffffdfU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0x0fffffe0U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x24U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 5U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xffffffbfU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0x0fffffc0U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x28U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 6U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xffffff7fU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0x0fffff80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x2cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 7U))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 5U)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U] 
            = (0x0fffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[1U]);
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
            = (0xffffff00U & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(6U) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xffbfU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 6U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfffffeffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 8U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfffffdffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xfffffe00U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 4U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 9U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfffffbffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xfffffc00U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 8U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000aU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfffff7ffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xfffff800U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x0cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000bU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xffffefffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xfffff000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x10U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000cU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xffffdfffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xffffe000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x14U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000dU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xffffbfffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xffffc000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x18U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000eU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xffff7fffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xffff8000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x1cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000fU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfffeffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xffff0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x20U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x00000010U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfffdffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xfffe0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x24U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x00000011U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfffbffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xfffc0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x28U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x00000012U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfff7ffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xfff80000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x2cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x00000013U))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 6U)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
            = (0xfff000ffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(7U) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xff7fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 7U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xffefffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 0x00000014U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xffdfffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xffe00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 4U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000015U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xffbfffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xffc00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 8U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000016U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xff7fffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xff800000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x0cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000017U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfeffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xff000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x10U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000018U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfdffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xfe000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x14U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000019U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xfbffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xfc000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x18U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001aU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xf7ffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xf8000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x1cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001bU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xefffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xf0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x20U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001cU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xdfffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xe0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x24U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001dU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0xbfffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0xc0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x28U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001eU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
        = ((0x7fffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]) 
           | (0x80000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x2cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001fU))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 7U)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U] 
            = (0x000fffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[2U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(8U) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xfeffU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 8U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfffffffeU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
              & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfffffffdU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xfffffffeU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 4U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 1U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfffffffbU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xfffffffcU & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 8U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 2U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfffffff7U & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xfffffff8U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x0cU))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 3U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xffffffefU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xfffffff0U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x10U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 4U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xffffffdfU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xffffffe0U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x14U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 5U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xffffffbfU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xffffffc0U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x18U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 6U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xffffff7fU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xffffff80U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x1cU))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 7U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfffffeffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xffffff00U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x20U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 8U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfffffdffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xfffffe00U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x24U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 9U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfffffbffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xfffffc00U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x28U))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 0x0000000aU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfffff7ffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xfffff800U & ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                             & (((0x0000000fU & (IData)(
                                                        (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                         >> 0x2cU))) 
                                 <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                << 0x0000000bU))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 8U)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
            = (0xfffff000U & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(9U) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xfdffU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 9U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xffffefffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 0x0000000cU));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xffffdfffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xffffe000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 4U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000000dU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xffffbfffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xffffc000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 8U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000000eU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xffff7fffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xffff8000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x0cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000000fU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfffeffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xffff0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x10U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000010U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfffdffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xfffe0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x14U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000011U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfffbffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xfffc0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x18U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000012U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfff7ffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xfff80000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x1cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000013U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xffefffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xfff00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x20U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000014U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xffdfffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xffe00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x24U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000015U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xffbfffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xffc00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x28U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000016U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xff7fffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xff800000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000000cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x2cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000017U))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 9U)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
            = (0xff000fffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(0x0aU) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xfbffU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 0x0000000aU));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfeffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 0x00000018U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfdffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xfe000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 4U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000019U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xfbffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xfc000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 8U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001aU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xf7ffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xf8000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x0cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001bU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xefffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xf0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x10U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001cU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xdfffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xe0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x14U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001dU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0xbfffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0xc0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x18U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001eU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
        = ((0x7fffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]) 
           | (0x80000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000018U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x1cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001fU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfffffffeU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               >> 8U) & ((0x0000000fU & (IData)((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                 >> 0x20U))) 
                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfffffffdU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0x00fffffeU & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x24U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 1U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfffffffbU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0x00fffffcU & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x28U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 2U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfffffff7U & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0x00fffff8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x2cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 3U))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 0x0aU)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U] 
            = (0x00ffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[3U]);
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
            = (0xfffffff0U & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(0x0bU) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xf7ffU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 0x0000000bU));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xffffffefU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 4U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xffffffdfU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xffffffe0U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 4U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 5U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xffffffbfU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xffffffc0U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 8U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 6U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xffffff7fU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xffffff80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x0cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 7U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfffffeffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xffffff00U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x10U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 8U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfffffdffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xfffffe00U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x14U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 9U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfffffbffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xfffffc00U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x18U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000aU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfffff7ffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xfffff800U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x1cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000bU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xffffefffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xfffff000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x20U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000cU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xffffdfffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xffffe000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x24U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000dU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xffffbfffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xffffc000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x28U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000eU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xffff7fffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xffff8000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x2cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000fU))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 0x0bU)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
            = (0xffff000fU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(0x0cU) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xefffU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 0x0000000cU));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfffeffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 0x00000010U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfffdffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xfffe0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 4U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000011U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfffbffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xfffc0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 8U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000012U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfff7ffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xfff80000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x0cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000013U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xffefffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xfff00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x10U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000014U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xffdfffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xffe00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x14U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000015U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xffbfffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xffc00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x18U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000016U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xff7fffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xff800000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x1cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000017U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfeffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xff000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x20U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000018U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfdffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xfe000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x24U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000019U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xfbffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xfc000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x28U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001aU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xf7ffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xf8000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000010U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x2cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001bU))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 0x0cU)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
            = (0xf000ffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(0x0dU) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xdfffU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 0x0000000dU));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xefffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 0x0000001cU));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xdfffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xe0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000001cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 4U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001dU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0xbfffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0xc0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000001cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 8U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001eU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
        = ((0x7fffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]) 
           | (0x80000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x0000001cU) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x0cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001fU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfffffffeU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               >> 4U) & ((0x0000000fU & (IData)((vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                 >> 0x10U))) 
                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfffffffdU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0x0ffffffeU & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x14U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 1U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfffffffbU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0x0ffffffcU & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x18U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 2U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfffffff7U & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0x0ffffff8U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x1cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 3U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xffffffefU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0x0ffffff0U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x20U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 4U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xffffffdfU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0x0fffffe0U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x24U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 5U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xffffffbfU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0x0fffffc0U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x28U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 6U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xffffff7fU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0x0fffff80U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              >> 4U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x2cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 7U))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 0x0dU)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U] 
            = (0x0fffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[4U]);
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
            = (0xffffff00U & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(0x0eU) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0xbfffU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 0x0000000eU));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfffffeffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 8U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfffffdffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xfffffe00U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 4U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 9U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfffffbffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xfffffc00U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 8U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000aU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfffff7ffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xfffff800U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x0cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000bU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xffffefffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xfffff000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x10U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000cU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xffffdfffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xffffe000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x14U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000dU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xffffbfffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xffffc000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x18U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000eU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xffff7fffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xffff8000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x1cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x0000000fU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfffeffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xffff0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x20U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x00000010U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfffdffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xfffe0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x24U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x00000011U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfffbffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xfffc0000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x28U))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x00000012U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfff7ffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xfff80000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 8U) & (((0x0000000fU 
                                          & (IData)(
                                                    (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                     >> 0x2cU))) 
                                         <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                        << 0x00000013U))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 0x0eU)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
            = (0xfff000ffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]);
    }
    tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r 
        = (0x0000000fU & ((IData)(0x0fU) - (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_c)));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en 
        = ((0x7fffU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en)) 
           | (((((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tv) 
                 & (0U != (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
                & ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                   <= (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc))) 
               & ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__tw)) 
                  | ((IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r) 
                     == (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_pc)))) 
              << 0x0000000fU));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xffefffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
               & ((0x0000000fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts)) 
                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r))) 
              << 0x00000014U));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xffdfffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xffe00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 4U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000015U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xffbfffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xffc00000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 8U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000016U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xff7fffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xff800000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x0cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000017U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfeffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xff000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x10U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000018U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfdffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xfe000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x14U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x00000019U))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xfbffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xfc000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x18U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001aU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xf7ffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xf8000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x1cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001bU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xefffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xf0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x20U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001cU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xdfffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xe0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x24U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001dU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0xbfffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0xc0000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x28U))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001eU))));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
        = ((0x7fffffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]) 
           | (0x80000000U & (((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_lo) 
                              << 0x00000014U) & (((0x0000000fU 
                                                   & (IData)(
                                                             (vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__t_ts 
                                                              >> 0x2cU))) 
                                                  <= (IData)(tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__unnamedblk1__DOT__unnamedblk2__DOT__r)) 
                                                 << 0x0000001fU))));
    if ((1U & (~ ((IData)(vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_en) 
                  >> 0x0fU)))) {
        vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U] 
            = (0x000fffffU & vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__x_set[5U]);
    }
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__u_fe__DOT__iv 
        = ((IData)(vlSelfRef.tb__DOT__rstn) & (IData)(vlSelfRef.tb__DOT__dut__DOT__accept));
    vlSelfRef.tb__DOT__dut__DOT__u_dp__DOT__w0 = vlSelfRef.tb__DOT__sd;
}

void Vtb___024root___timing_ready(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_ready\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h6018ce7f__0.ready("@(posedge tb.clk)");
    }
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h6018ce40__0.ready("@(negedge tb.clk)");
    }
}

void Vtb___024root___timing_resume(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_resume\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h6018ce7f__0.moveToResumeQueue(
                                                          "@(posedge tb.clk)");
    vlSelfRef.__VtrigSched_h6018ce40__0.moveToResumeQueue(
                                                          "@(negedge tb.clk)");
    vlSelfRef.__VtrigSched_h6018ce7f__0.resume("@(posedge tb.clk)");
    vlSelfRef.__VtrigSched_h6018ce40__0.resume("@(negedge tb.clk)");
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vtb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vtb___024root____VbeforeTrig_h6018ce7f__0(Vtb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root____VbeforeTrig_h6018ce7f__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.tb__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0)) 
                                   << 1U) | ((IData)(vlSelfRef.tb__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0 
        = vlSelfRef.tb__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h6018ce7f__0.ready(__VeventDescription);
    }
    if ((2ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vtb___024root____VbeforeTrig_h6018ce40__0(Vtb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root____VbeforeTrig_h6018ce40__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.tb__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0)) 
                                   << 1U) | ((IData)(vlSelfRef.tb__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0 
        = vlSelfRef.tb__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h6018ce7f__0.ready(__VeventDescription);
    }
    if ((2ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h6018ce40__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtb___024root___eval_debug_assertions(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_debug_assertions\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
