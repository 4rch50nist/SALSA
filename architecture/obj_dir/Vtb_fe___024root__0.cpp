// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fe.h for the primary calling header

#include "Vtb_fe__pch.h"

VlCoroutine Vtb_fe___024root___eval_initial__TOP__Vtiming__0(Vtb_fe___024root* vlSelf);
VlCoroutine Vtb_fe___024root___eval_initial__TOP__Vtiming__1(Vtb_fe___024root* vlSelf);

void Vtb_fe___024root___eval_initial(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___eval_initial\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_fe___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_fe___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vtb_fe___024root___eval_sample(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___eval_sample\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fe___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_fe___024root___eval_ico(Vtb_fe___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___eval_ico\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_fe___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vtb_fe___024root___timing_ready(Vtb_fe___024root* vlSelf);
void Vtb_fe___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fe___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtb_fe___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vtb_fe___024root___timing_resume(Vtb_fe___024root* vlSelf);

bool Vtb_fe___024root___eval_act(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___eval_act\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                          << 2U) 
                                                         | ((((~ (IData)(vlSelfRef.tb_fe__DOT__clk)) 
                                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_fe__DOT__clk__0)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.tb_fe__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_fe__DOT__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__tb_fe__DOT__clk__0 
            = vlSelfRef.tb_fe__DOT__clk;
    }
    Vtb_fe___024root___timing_ready(vlSelf);
    Vtb_fe___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_fe___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_fe___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_fe___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_fe___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_fe___024root___eval_inact(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___eval_inact\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb_salsa.sv", 6, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_fe___024root___nba_sequent__TOP__0(Vtb_fe___024root* vlSelf);
void Vtb_fe___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vtb_fe___024root___eval_nba(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___eval_nba\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_fe___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtb_fe___024root___nba_sequent__TOP__0(vlSelf);
            }
        }
        Vtb_fe___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vtb_fe___024root___eval_obs(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___eval_obs\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtb_fe___024root___eval_react(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___eval_react\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vtb_fe___024root___eval_postponed(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___eval_postponed\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb_fe___024root____VbeforeTrig_h521be442__0(Vtb_fe___024root* vlSelf, const char* __VeventDescription);
void Vtb_fe___024root____VbeforeTrig_h521be501__0(Vtb_fe___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtb_fe___024root___eval_initial__TOP__Vtiming__0(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_fe__DOT__unnamedblk1_1__DOT____Vrepeat0;
    tb_fe__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ tb_fe__DOT__unnamedblk3__DOT__up;
    tb_fe__DOT__unnamedblk3__DOT__up = 0;
    IData/*31:0*/ __Vtask_tb_fe__DOT__check__0__p;
    __Vtask_tb_fe__DOT__check__0__p = 0;
    CData/*0:0*/ __Vtask_tb_fe__DOT__check__0__update;
    __Vtask_tb_fe__DOT__check__0__update = 0;
    IData/*31:0*/ __Vtask_tb_fe__DOT__check__0____VlefCall_1__nu2;
    __Vtask_tb_fe__DOT__check__0____VlefCall_1__nu2 = 0;
    IData/*31:0*/ __Vtask_tb_fe__DOT__check__0____VlefCall_0__nu2;
    __Vtask_tb_fe__DOT__check__0____VlefCall_0__nu2 = 0;
    SData/*15:0*/ __Vtask_tb_fe__DOT__check__0__e_en;
    __Vtask_tb_fe__DOT__check__0__e_en = 0;
    VlUnpacked<SData/*11:0*/, 16> __Vtask_tb_fe__DOT__check__0__e_set;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        __Vtask_tb_fe__DOT__check__0__e_set[__Vi0] = 0;
    }
    IData/*31:0*/ __Vtask_tb_fe__DOT__check__0__x;
    __Vtask_tb_fe__DOT__check__0__x = 0;
    IData/*31:0*/ __Vtask_tb_fe__DOT__check__0__hi;
    __Vtask_tb_fe__DOT__check__0__hi = 0;
    IData/*31:0*/ __Vtask_tb_fe__DOT__check__0__lo;
    __Vtask_tb_fe__DOT__check__0__lo = 0;
    IData/*31:0*/ __Vtask_tb_fe__DOT__check__0__b;
    __Vtask_tb_fe__DOT__check__0__b = 0;
    IData/*31:0*/ __Vfunc_tb_fe__DOT__nu2__1__Vfuncout;
    __Vfunc_tb_fe__DOT__nu2__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_fe__DOT__nu2__1__x;
    __Vfunc_tb_fe__DOT__nu2__1__x = 0;
    IData/*31:0*/ __Vfunc_tb_fe__DOT__nu2__1__v;
    __Vfunc_tb_fe__DOT__nu2__1__v = 0;
    IData/*31:0*/ __Vfunc_tb_fe__DOT__nu2__2__Vfuncout;
    __Vfunc_tb_fe__DOT__nu2__2__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_fe__DOT__nu2__2__x;
    __Vfunc_tb_fe__DOT__nu2__2__x = 0;
    IData/*31:0*/ __Vfunc_tb_fe__DOT__nu2__2__v;
    __Vfunc_tb_fe__DOT__nu2__2__v = 0;
    // Body
    tb_fe__DOT__unnamedblk1_1__DOT____Vrepeat0 = 3U;
    while (VL_LTS_III(32, 0U, tb_fe__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_fe___024root____VbeforeTrig_h521be442__0(vlSelf, 
                                                     "@(posedge tb_fe.clk)");
        co_await vlSelfRef.__VtrigSched_h521be442__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_fe.clk)", 
                                                             "tb_salsa.sv", 
                                                             51);
        tb_fe__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (tb_fe__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_fe__DOT__rst_n = 1U;
    tb_fe__DOT__unnamedblk3__DOT__up = 0U;
    while (VL_GTS_III(32, 2U, tb_fe__DOT__unnamedblk3__DOT__up)) {
        vlSelfRef.tb_fe__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p = 1U;
        while (VL_GTS_III(32, 0x00010000U, vlSelfRef.tb_fe__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p)) {
            Vtb_fe___024root____VbeforeTrig_h521be501__0(vlSelf, 
                                                         "@(negedge tb_fe.clk)");
            co_await vlSelfRef.__VtrigSched_h521be501__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_fe.clk)", 
                                                                 "tb_salsa.sv", 
                                                                 54);
            vlSelfRef.tb_fe__DOT__q_valid = 1U;
            vlSelfRef.tb_fe__DOT__q_is_update = (1U 
                                                 & tb_fe__DOT__unnamedblk3__DOT__up);
            vlSelfRef.tb_fe__DOT__q_idx = (0x0000ffffU 
                                           & vlSelfRef.tb_fe__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p);
            Vtb_fe___024root____VbeforeTrig_h521be442__0(vlSelf, 
                                                         "@(posedge tb_fe.clk)");
            co_await vlSelfRef.__VtrigSched_h521be442__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_fe.clk)", 
                                                                 "tb_salsa.sv", 
                                                                 55);
            co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                                 nullptr, 
                                                 "tb_salsa.sv", 
                                                 55);
            __Vtask_tb_fe__DOT__check__0__update = 
                (1U & tb_fe__DOT__unnamedblk3__DOT__up);
            __Vtask_tb_fe__DOT__check__0__p = vlSelfRef.tb_fe__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p;
            __Vtask_tb_fe__DOT__check__0__e_en = 0;
            for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
                __Vtask_tb_fe__DOT__check__0__e_set[__Vi0] = 0;
            }
            __Vtask_tb_fe__DOT__check__0__x = 0U;
            __Vtask_tb_fe__DOT__check__0__hi = 0U;
            __Vtask_tb_fe__DOT__check__0__lo = 0U;
            __Vtask_tb_fe__DOT__check__0__b = 0U;
            __Vtask_tb_fe__DOT__check__0__e_en = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[0U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[1U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[2U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[3U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[4U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[5U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[6U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[7U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[8U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[9U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[10U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[11U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[12U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[13U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[14U] = 0U;
            __Vtask_tb_fe__DOT__check__0__e_set[15U] = 0U;
            __Vtask_tb_fe__DOT__check__0__hi = (__Vtask_tb_fe__DOT__check__0__p 
                                                >> 0x0000000cU);
            if (__Vtask_tb_fe__DOT__check__0__update) {
                __Vtask_tb_fe__DOT__check__0__x = (0x00000fffU 
                                                   & __Vtask_tb_fe__DOT__check__0__p);
                while (((0U != __Vtask_tb_fe__DOT__check__0__x) 
                        & VL_GTS_III(32, 0x00001000U, __Vtask_tb_fe__DOT__check__0__x))) {
                    __Vfunc_tb_fe__DOT__nu2__1__x = __Vtask_tb_fe__DOT__check__0__x;
                    __Vfunc_tb_fe__DOT__nu2__1__Vfuncout = 0U;
                    __Vfunc_tb_fe__DOT__nu2__1__v = 0U;
                    while ((0U == (1U & __Vfunc_tb_fe__DOT__nu2__1__x))) {
                        __Vfunc_tb_fe__DOT__nu2__1__x 
                            = (__Vfunc_tb_fe__DOT__nu2__1__x 
                               >> 1U);
                        __Vfunc_tb_fe__DOT__nu2__1__v 
                            = ((IData)(1U) + __Vfunc_tb_fe__DOT__nu2__1__v);
                    }
                    __Vfunc_tb_fe__DOT__nu2__1__Vfuncout 
                        = __Vfunc_tb_fe__DOT__nu2__1__v;
                    __Vtask_tb_fe__DOT__check__0____VlefCall_0__nu2 
                        = __Vfunc_tb_fe__DOT__nu2__1__Vfuncout;
                    __Vtask_tb_fe__DOT__check__0__b 
                        = VL_MODDIVS_III(32, (__Vtask_tb_fe__DOT__check__0____VlefCall_0__nu2 
                                              + __Vtask_tb_fe__DOT__check__0__hi), (IData)(0x00000010U));
                    if (VL_UNLIKELY(((1U & ((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                                            >> (0x0000000fU 
                                                & __Vtask_tb_fe__DOT__check__0__b)))))) {
                        vlSelfRef.tb_fe__DOT__errors 
                            = ((IData)(1U) + vlSelfRef.tb_fe__DOT__errors);
                        VL_WRITEF_NX("model conflict at key %0d\n",1
                                     , '~',32,__Vtask_tb_fe__DOT__check__0__p);
                    }
                    __Vtask_tb_fe__DOT__check__0__e_en 
                        = ((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                           | (0x0000ffffU & ((IData)(1U) 
                                             << (0x0000000fU 
                                                 & __Vtask_tb_fe__DOT__check__0__b))));
                    __Vtask_tb_fe__DOT__check__0__e_set[(0x0000000fU 
                                                         & __Vtask_tb_fe__DOT__check__0__b)] 
                        = (0x00000fffU & __Vtask_tb_fe__DOT__check__0__x);
                    __Vtask_tb_fe__DOT__check__0__x 
                        = (__Vtask_tb_fe__DOT__check__0__x 
                           + (__Vtask_tb_fe__DOT__check__0__x 
                              & (- __Vtask_tb_fe__DOT__check__0__x)));
                }
            } else {
                __Vtask_tb_fe__DOT__check__0__x = __Vtask_tb_fe__DOT__check__0__p;
                while ((0U != __Vtask_tb_fe__DOT__check__0__x)) {
                    __Vtask_tb_fe__DOT__check__0__lo 
                        = (0x00000fffU & __Vtask_tb_fe__DOT__check__0__x);
                    if ((0U != __Vtask_tb_fe__DOT__check__0__lo)) {
                        __Vfunc_tb_fe__DOT__nu2__2__x 
                            = __Vtask_tb_fe__DOT__check__0__lo;
                        __Vfunc_tb_fe__DOT__nu2__2__Vfuncout = 0U;
                        __Vfunc_tb_fe__DOT__nu2__2__v = 0U;
                        while ((0U == (1U & __Vfunc_tb_fe__DOT__nu2__2__x))) {
                            __Vfunc_tb_fe__DOT__nu2__2__x 
                                = (__Vfunc_tb_fe__DOT__nu2__2__x 
                                   >> 1U);
                            __Vfunc_tb_fe__DOT__nu2__2__v 
                                = ((IData)(1U) + __Vfunc_tb_fe__DOT__nu2__2__v);
                        }
                        __Vfunc_tb_fe__DOT__nu2__2__Vfuncout 
                            = __Vfunc_tb_fe__DOT__nu2__2__v;
                        __Vtask_tb_fe__DOT__check__0____VlefCall_1__nu2 
                            = __Vfunc_tb_fe__DOT__nu2__2__Vfuncout;
                        __Vtask_tb_fe__DOT__check__0__b 
                            = VL_MODDIVS_III(32, (__Vtask_tb_fe__DOT__check__0____VlefCall_1__nu2 
                                                  + __Vtask_tb_fe__DOT__check__0__hi), (IData)(0x00000010U));
                        if (VL_UNLIKELY(((1U & ((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                                                >> 
                                                (0x0000000fU 
                                                 & __Vtask_tb_fe__DOT__check__0__b)))))) {
                            vlSelfRef.tb_fe__DOT__errors 
                                = ((IData)(1U) + vlSelfRef.tb_fe__DOT__errors);
                            VL_WRITEF_NX("model conflict at key %0d\n",1
                                         , '~',32,__Vtask_tb_fe__DOT__check__0__p);
                        }
                        __Vtask_tb_fe__DOT__check__0__e_en 
                            = ((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                               | (0x0000ffffU & ((IData)(1U) 
                                                 << 
                                                 (0x0000000fU 
                                                  & __Vtask_tb_fe__DOT__check__0__b))));
                        __Vtask_tb_fe__DOT__check__0__e_set[(0x0000000fU 
                                                             & __Vtask_tb_fe__DOT__check__0__b)] 
                            = (0x00000fffU & __Vtask_tb_fe__DOT__check__0__lo);
                    }
                    __Vtask_tb_fe__DOT__check__0__x 
                        = (__Vtask_tb_fe__DOT__check__0__x 
                           - (__Vtask_tb_fe__DOT__check__0__x 
                              & (- __Vtask_tb_fe__DOT__check__0__x)));
                }
            }
            if (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                 != (IData)(__Vtask_tb_fe__DOT__check__0__e_en))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d %s: en %h, want %h\n",4
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',48,((IData)(__Vtask_tb_fe__DOT__check__0__update)
                                            ? 0x0000757064617465ULL
                                            : 0x0000007175657279ULL)
                                 , '#',16,(IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)
                                 , '#',16,__Vtask_tb_fe__DOT__check__0__e_en);
                }
            }
            if (((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                 & ((0x00000fffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                    != __Vtask_tb_fe__DOT__check__0__e_set[0U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 0: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U])
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[0U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 1U) & ((0x00000fffU & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] 
                                            >> 0x0000000cU)) 
                            != __Vtask_tb_fe__DOT__check__0__e_set[1U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 1: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] 
                                              >> 0x0000000cU))
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[1U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 2U) & ((0x00000fffU & ((vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] 
                                             << 8U) 
                                            | (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] 
                                               >> 0x00000018U))) 
                            != __Vtask_tb_fe__DOT__check__0__e_set[2U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 2: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & ((vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] 
                                               << 8U) 
                                              | (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] 
                                                 >> 0x00000018U)))
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[2U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 3U) & ((0x00000fffU & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] 
                                            >> 4U)) 
                            != __Vtask_tb_fe__DOT__check__0__e_set[3U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 3: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] 
                                              >> 4U))
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[3U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 4U) & ((0x00000fffU & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] 
                                            >> 0x00000010U)) 
                            != __Vtask_tb_fe__DOT__check__0__e_set[4U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 4: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] 
                                              >> 0x00000010U))
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[4U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 5U) & ((0x00000fffU & ((vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] 
                                             << 4U) 
                                            | (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] 
                                               >> 0x0000001cU))) 
                            != __Vtask_tb_fe__DOT__check__0__e_set[5U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 5: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & ((vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] 
                                               << 4U) 
                                              | (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] 
                                                 >> 0x0000001cU)))
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[5U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 6U) & ((0x00000fffU & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] 
                                            >> 8U)) 
                            != __Vtask_tb_fe__DOT__check__0__e_set[6U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 6: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] 
                                              >> 8U))
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[6U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 7U) & ((vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] 
                             >> 0x00000014U) != __Vtask_tb_fe__DOT__check__0__e_set[7U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 7: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] 
                                           >> 0x00000014U)
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[7U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 8U) & ((0x00000fffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                            != __Vtask_tb_fe__DOT__check__0__e_set[8U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 8: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U])
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[8U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 9U) & ((0x00000fffU & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] 
                                            >> 0x0000000cU)) 
                            != __Vtask_tb_fe__DOT__check__0__e_set[9U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 9: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] 
                                              >> 0x0000000cU))
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[9U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 0x0aU) & ((0x00000fffU & ((vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] 
                                                << 8U) 
                                               | (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] 
                                                  >> 0x00000018U))) 
                               != __Vtask_tb_fe__DOT__check__0__e_set[10U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 10: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & ((vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] 
                                               << 8U) 
                                              | (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] 
                                                 >> 0x00000018U)))
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[10U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 0x0bU) & ((0x00000fffU & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] 
                                               >> 4U)) 
                               != __Vtask_tb_fe__DOT__check__0__e_set[11U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 11: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] 
                                              >> 4U))
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[11U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 0x0cU) & ((0x00000fffU & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] 
                                               >> 0x00000010U)) 
                               != __Vtask_tb_fe__DOT__check__0__e_set[12U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 12: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] 
                                              >> 0x00000010U))
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[12U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 0x0dU) & ((0x00000fffU & ((vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] 
                                                << 4U) 
                                               | (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] 
                                                  >> 0x0000001cU))) 
                               != __Vtask_tb_fe__DOT__check__0__e_set[13U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 13: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & ((vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] 
                                               << 4U) 
                                              | (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] 
                                                 >> 0x0000001cU)))
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[13U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 0x0eU) & ((0x00000fffU & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] 
                                               >> 8U)) 
                               != __Vtask_tb_fe__DOT__check__0__e_set[14U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 14: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(0x00000fffU 
                                           & (vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] 
                                              >> 8U))
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[14U]);
                }
            }
            if ((((IData)(__Vtask_tb_fe__DOT__check__0__e_en) 
                  >> 0x0fU) & ((vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] 
                                >> 0x00000014U) != __Vtask_tb_fe__DOT__check__0__e_set[15U]))) {
                vlSelfRef.tb_fe__DOT__errors = ((IData)(1U) 
                                                + vlSelfRef.tb_fe__DOT__errors);
                if (VL_UNLIKELY((VL_GTS_III(32, 6U, vlSelfRef.tb_fe__DOT__errors)))) {
                    VL_WRITEF_NX("key %0d bank 15: set %h, want %h\n",3
                                 , '~',32,__Vtask_tb_fe__DOT__check__0__p
                                 , '#',12,(vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] 
                                           >> 0x00000014U)
                                 , '#',12,__Vtask_tb_fe__DOT__check__0__e_set[15U]);
                }
            }
            vlSelfRef.tb_fe__DOT__checked = ((IData)(1U) 
                                             + vlSelfRef.tb_fe__DOT__checked);
            vlSelfRef.tb_fe__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p 
                = ((IData)(1U) + vlSelfRef.tb_fe__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p);
        }
        tb_fe__DOT__unnamedblk3__DOT__up = ((IData)(1U) 
                                            + tb_fe__DOT__unnamedblk3__DOT__up);
    }
    VL_WRITEF_NX("front end, level placement: %0d checks (every key as query and as update), %0d errors: %s\n",3
                 , '~',32,vlSelfRef.tb_fe__DOT__checked
                 , '~',32,vlSelfRef.tb_fe__DOT__errors
                 , '#',32,((0U != vlSelfRef.tb_fe__DOT__errors)
                            ? 0x4641494cU : 0x50415353U));
    VL_FINISH_MT("tb_salsa.sv", 60, "");
    co_return;
}

VlCoroutine Vtb_fe___024root___eval_initial__TOP__Vtiming__1(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "tb_salsa.sv", 
                                             9);
        vlSelfRef.tb_fe__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_fe__DOT__clk)));
    }
    co_return;
}

bool Vtb_fe___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___trigger_anySet__ico\n"); );
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

bool Vtb_fe___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___trigger_anySet__act\n"); );
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

void Vtb_fe___024root___nba_sequent__TOP__0(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___nba_sequent__TOP__0\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ tb_fe__DOT__dut__DOT__x_own;
    tb_fe__DOT__dut__DOT__x_own = 0;
    CData/*3:0*/ tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l;
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l = 0;
    CData/*0:0*/ tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has;
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0;
    // Body
    vlSelfRef.tb_fe__DOT__dut__DOT__tu = vlSelfRef.tb_fe__DOT__q_is_update;
    vlSelfRef.tb_fe__DOT__dut__DOT__tv = ((IData)(vlSelfRef.tb_fe__DOT__rst_n) 
                                          & (IData)(vlSelfRef.tb_fe__DOT__q_valid));
    vlSelfRef.tb_fe__DOT__dut__DOT__t_lo = (0x00000fffU 
                                            & (IData)(vlSelfRef.tb_fe__DOT__q_idx));
    vlSelfRef.tb_fe__DOT__dut__DOT__t_lv = (((2U & (IData)(vlSelfRef.tb_fe__DOT__q_idx))
                                              ? 1U : 
                                             ((4U & (IData)(vlSelfRef.tb_fe__DOT__q_idx))
                                               ? 2U
                                               : ((8U 
                                                   & (IData)(vlSelfRef.tb_fe__DOT__q_idx))
                                                   ? 3U
                                                   : 
                                                  ((0x00000010U 
                                                    & (IData)(vlSelfRef.tb_fe__DOT__q_idx))
                                                    ? 4U
                                                    : 
                                                   ((0x00000020U 
                                                     & (IData)(vlSelfRef.tb_fe__DOT__q_idx))
                                                     ? 5U
                                                     : 
                                                    ((0x00000040U 
                                                      & (IData)(vlSelfRef.tb_fe__DOT__q_idx))
                                                      ? 6U
                                                      : 
                                                     ((0x00000080U 
                                                       & (IData)(vlSelfRef.tb_fe__DOT__q_idx))
                                                       ? 7U
                                                       : 
                                                      ((0x00000100U 
                                                        & (IData)(vlSelfRef.tb_fe__DOT__q_idx))
                                                        ? 8U
                                                        : 
                                                       ((0x00000200U 
                                                         & (IData)(vlSelfRef.tb_fe__DOT__q_idx))
                                                         ? 9U
                                                         : 
                                                        ((0x00000400U 
                                                          & (IData)(vlSelfRef.tb_fe__DOT__q_idx))
                                                          ? 0x0aU
                                                          : 
                                                         (0x0bU 
                                                          & (- (IData)(
                                                                       (1U 
                                                                        & ((IData)(vlSelfRef.tb_fe__DOT__q_idx) 
                                                                           >> 0x0000000bU))))))))))))))) 
                                            & (- (IData)(
                                                         (1U 
                                                          & (~ (IData)(vlSelfRef.tb_fe__DOT__q_idx))))));
    vlSelfRef.tb_fe__DOT__dut__DOT__t_c = (0x0000000fU 
                                           & ((IData)(vlSelfRef.tb_fe__DOT__q_idx) 
                                              >> 0x0000000cU));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & (- (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    tb_fe__DOT__dut__DOT__x_own = ((0xfffeU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                        & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                       & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                      & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                         == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))));
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xfffeU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                ? (
                                                   (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                     & (0U 
                                                        != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                    & (0x0cU 
                                                       > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                   & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                       == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                      | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                          > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                         & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                : ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfffffffeU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                     ? 
                                                    (0U 
                                                     == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                     : 
                                                    ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                     & (0U 
                                                        >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfffffffdU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (2U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 1U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfffffffbU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (4U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 2U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfffffff7U 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (8U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 3U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xffffffefU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00000010U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 4U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xffffffdfU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00000020U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 5U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xffffffbfU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00000040U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 6U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xffffff7fU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00000080U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 7U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfffffeffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00000100U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 8U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfffffdffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00000200U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 9U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfffffbffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00000400U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000aU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfffff7ffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00000800U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000bU)));
    if ((1U & (~ (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = 
            (0xfffff000U & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(1U) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    tb_fe__DOT__dut__DOT__x_own = ((0xfffdU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 1U));
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xfffdU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 1U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xffffefffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x0000000cU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xffffdfffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00002000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000dU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xffffbfffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00004000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000eU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xffff7fffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00008000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000fU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfffeffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00010000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000010U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfffdffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00020000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000011U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfffbffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00040000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000012U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfff7ffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00080000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000013U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xffefffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00100000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000014U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xffdfffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00200000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000015U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xffbfffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00400000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000016U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xff7fffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x00800000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000017U)));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 1U)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = 
            (0xff000fffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(2U) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    tb_fe__DOT__dut__DOT__x_own = ((0xfffbU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 2U));
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xfffbU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 2U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfeffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x00000018U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfdffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x02000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000019U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xfbffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x04000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001aU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xf7ffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x08000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001bU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xefffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x10000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001cU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xdfffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x20000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001dU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0xbfffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (0x40000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001eU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = ((0x7fffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     ((7U 
                                                       > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                       ? 
                                                      ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                       >> 7U)
                                                       : 
                                                      (7U 
                                                       == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                      : 
                                                     (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                       >> 7U) 
                                                      & (7U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x0000001fU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfffffffeU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (1U 
                                                    & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                        ? 
                                                       ((8U 
                                                         > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                         ? 
                                                        ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                         >> 8U)
                                                         : 
                                                        (8U 
                                                         == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                        : 
                                                       (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                         >> 8U) 
                                                        & (8U 
                                                           >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))))));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfffffffdU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (2U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 1U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfffffffbU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (4U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 2U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfffffff7U 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (8U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 3U)));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 2U)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U] = 
            (0x00ffffffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[0U]);
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = 
            (0xfffffff0U & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(3U) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    tb_fe__DOT__dut__DOT__x_own = ((0xfff7U & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 3U));
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xfff7U 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 3U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xffffffefU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 4U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xffffffdfU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00000020U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 5U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xffffffbfU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00000040U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 6U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xffffff7fU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00000080U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 7U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfffffeffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00000100U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 8U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfffffdffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00000200U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 9U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfffffbffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00000400U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000aU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfffff7ffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00000800U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000bU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xffffefffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00001000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000cU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xffffdfffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00002000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000dU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xffffbfffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00004000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000eU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xffff7fffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00008000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000fU)));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 3U)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = 
            (0xffff000fU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(4U) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    tb_fe__DOT__dut__DOT__x_own = ((0xffefU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 4U));
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xffefU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 4U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfffeffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x00000010U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfffdffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00020000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000011U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfffbffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00040000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000012U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfff7ffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00080000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000013U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xffefffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00100000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000014U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xffdfffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00200000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000015U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xffbfffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00400000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000016U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xff7fffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x00800000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000017U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfeffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x01000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000018U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfdffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x02000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000019U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xfbffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x04000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001aU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xf7ffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x08000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001bU)));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 4U)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = 
            (0xf000ffffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(5U) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    tb_fe__DOT__dut__DOT__x_own = ((0xffdfU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 5U));
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xffdfU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 5U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xefffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x0000001cU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xdfffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x20000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001dU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0xbfffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (0x40000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001eU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = ((0x7fffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     ((3U 
                                                       > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                       ? 
                                                      ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                       >> 3U)
                                                       : 
                                                      (3U 
                                                       == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                      : 
                                                     (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                       >> 3U) 
                                                      & (3U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x0000001fU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfffffffeU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (1U 
                                                    & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                        ? 
                                                       ((4U 
                                                         > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                         ? 
                                                        ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                         >> 4U)
                                                         : 
                                                        (4U 
                                                         == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                        : 
                                                       (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                         >> 4U) 
                                                        & (4U 
                                                           >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))))));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfffffffdU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (2U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 1U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfffffffbU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (4U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 2U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfffffff7U 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (8U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 3U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xffffffefU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00000010U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 4U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xffffffdfU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00000020U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 5U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xffffffbfU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00000040U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 6U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xffffff7fU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00000080U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 7U)));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 5U)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U] = 
            (0x0fffffffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[1U]);
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = 
            (0xffffff00U & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(6U) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    tb_fe__DOT__dut__DOT__x_own = ((0xffbfU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 6U));
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xffbfU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 6U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfffffeffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 8U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfffffdffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00000200U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 9U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfffffbffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00000400U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000aU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfffff7ffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00000800U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000bU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xffffefffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00001000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000cU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xffffdfffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00002000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000dU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xffffbfffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00004000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000eU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xffff7fffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00008000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000fU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfffeffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00010000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000010U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfffdffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00020000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000011U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfffbffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00040000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000012U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfff7ffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00080000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000013U)));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 6U)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = 
            (0xfff000ffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(7U) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    tb_fe__DOT__dut__DOT__x_own = ((0xff7fU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 7U));
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xff7fU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 7U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xffefffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x00000014U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xffdfffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00200000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000015U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xffbfffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00400000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000016U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xff7fffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x00800000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000017U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfeffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x01000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000018U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfdffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x02000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000019U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xfbffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x04000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001aU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xf7ffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x08000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001bU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xefffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x10000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001cU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xdfffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x20000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001dU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0xbfffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (0x40000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001eU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = ((0x7fffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     ((0x0bU 
                                                       > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                       ? 
                                                      ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                       >> 0x0bU)
                                                       : 
                                                      (0x0bU 
                                                       == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                      : 
                                                     (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                       >> 0x0bU) 
                                                      & (0x0bU 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x0000001fU));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 7U)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U] = 
            (0x000fffffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[2U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(8U) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    tb_fe__DOT__dut__DOT__x_own = ((0xfeffU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 8U));
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xfeffU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 8U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfffffffeU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                     ? 
                                                    (0U 
                                                     == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                     : 
                                                    ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                     & (0U 
                                                        >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfffffffdU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (2U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 1U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfffffffbU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (4U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 2U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfffffff7U 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (8U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 3U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xffffffefU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00000010U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 4U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xffffffdfU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00000020U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 5U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xffffffbfU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00000040U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 6U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xffffff7fU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00000080U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 7U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfffffeffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00000100U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 8U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfffffdffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00000200U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 9U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfffffbffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00000400U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000aU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfffff7ffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00000800U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000bU)));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 8U)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = 
            (0xfffff000U & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(9U) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    tb_fe__DOT__dut__DOT__x_own = ((0xfdffU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 9U));
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xfdffU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 9U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xffffefffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x0000000cU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xffffdfffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00002000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000dU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xffffbfffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00004000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000eU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xffff7fffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00008000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000fU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfffeffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00010000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000010U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfffdffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00020000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000011U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfffbffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00040000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000012U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfff7ffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00080000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000013U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xffefffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00100000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000014U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xffdfffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00200000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000015U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xffbfffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00400000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000016U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xff7fffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x00800000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000017U)));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 9U)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = 
            (0xff000fffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(0x0aU) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    tb_fe__DOT__dut__DOT__x_own = ((0xfbffU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 0x0000000aU));
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xfbffU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 0x0000000aU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfeffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x00000018U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfdffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x02000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000019U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xfbffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x04000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001aU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xf7ffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x08000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001bU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xefffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x10000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001cU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xdfffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x20000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001dU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0xbfffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (0x40000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001eU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = ((0x7fffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     ((7U 
                                                       > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                       ? 
                                                      ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                       >> 7U)
                                                       : 
                                                      (7U 
                                                       == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                      : 
                                                     (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                       >> 7U) 
                                                      & (7U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x0000001fU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfffffffeU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (1U 
                                                    & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                        ? 
                                                       ((8U 
                                                         > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                         ? 
                                                        ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                         >> 8U)
                                                         : 
                                                        (8U 
                                                         == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                        : 
                                                       (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                         >> 8U) 
                                                        & (8U 
                                                           >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))))));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfffffffdU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (2U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 1U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfffffffbU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (4U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 2U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfffffff7U 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (8U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 3U)));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 0x0aU)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U] = 
            (0x00ffffffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[3U]);
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = 
            (0xfffffff0U & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(0x0bU) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    tb_fe__DOT__dut__DOT__x_own = ((0xf7ffU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 0x0000000bU));
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xf7ffU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 0x0000000bU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xffffffefU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 4U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xffffffdfU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00000020U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 5U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xffffffbfU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00000040U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 6U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xffffff7fU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00000080U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 7U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfffffeffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00000100U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 8U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfffffdffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00000200U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 9U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfffffbffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00000400U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000aU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfffff7ffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00000800U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000bU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xffffefffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00001000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000cU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xffffdfffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00002000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000dU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xffffbfffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00004000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000eU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xffff7fffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00008000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000fU)));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 0x0bU)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = 
            (0xffff000fU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(0x0cU) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    tb_fe__DOT__dut__DOT__x_own = ((0xefffU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 0x0000000cU));
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xefffU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 0x0000000cU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfffeffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x00000010U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfffdffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00020000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000011U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfffbffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00040000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000012U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfff7ffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00080000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000013U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xffefffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00100000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000014U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xffdfffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00200000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000015U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xffbfffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00400000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000016U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xff7fffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x00800000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000017U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfeffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x01000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000018U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfdffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x02000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000019U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xfbffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x04000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001aU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xf7ffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x08000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001bU)));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 0x0cU)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = 
            (0xf000ffffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(0x0dU) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    tb_fe__DOT__dut__DOT__x_own = ((0xdfffU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 0x0000000dU));
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xdfffU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 0x0000000dU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xefffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x0000001cU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xdfffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x20000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001dU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0xbfffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (0x40000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001eU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = ((0x7fffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     ((3U 
                                                       > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                       ? 
                                                      ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                       >> 3U)
                                                       : 
                                                      (3U 
                                                       == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                      : 
                                                     (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                       >> 3U) 
                                                      & (3U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x0000001fU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfffffffeU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (1U 
                                                    & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                        ? 
                                                       ((4U 
                                                         > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                         ? 
                                                        ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                         >> 4U)
                                                         : 
                                                        (4U 
                                                         == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                        : 
                                                       (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                         >> 4U) 
                                                        & (4U 
                                                           >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))))));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfffffffdU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (2U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 1U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfffffffbU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (4U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 2U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfffffff7U 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (8U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 3U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xffffffefU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00000010U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 4U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xffffffdfU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00000020U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 5U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xffffffbfU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00000040U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 6U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xffffff7fU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00000080U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 7U)));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 0x0dU)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U] = 
            (0x0fffffffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[4U]);
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = 
            (0xffffff00U & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(0x0eU) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    tb_fe__DOT__dut__DOT__x_own = ((0xbfffU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 0x0000000eU));
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0xbfffU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 0x0000000eU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfffffeffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 8U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfffffdffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00000200U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 9U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfffffbffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00000400U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000aU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfffff7ffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00000800U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000bU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xffffefffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00001000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000cU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xffffdfffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00002000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000dU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xffffbfffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00004000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000eU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xffff7fffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00008000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000000fU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfffeffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00010000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000010U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfffdffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00020000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000011U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfffbffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00040000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000012U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfff7ffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00080000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0bU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU)
                                                          : 
                                                         (0x0bU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0bU) 
                                                         & (0x0bU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000013U)));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 0x0eU)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = 
            (0xfff000ffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]);
    }
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l 
        = (0x0000000fU & ((IData)(0x0fU) - (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_c)));
    tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has = 0U;
    if ((0U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo));
    }
    if ((1U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 1U));
    }
    if ((2U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 2U));
    }
    if ((3U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 3U));
    }
    if ((4U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 4U));
    }
    if ((5U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 5U));
    }
    if ((6U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 6U));
    }
    if ((7U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 7U));
    }
    if ((8U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 8U));
    }
    if ((9U == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 9U));
    }
    if ((0x0aU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0aU));
    }
    if ((0x0bU == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) {
        tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has 
            = (1U & ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                     >> 0x0bU));
    }
    tb_fe__DOT__dut__DOT__x_own = ((0x7fffU & (IData)(tb_fe__DOT__dut__DOT__x_own)) 
                                   | (((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                         & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)) 
                                        & (0U != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                       & ((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                          == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv))) 
                                      << 0x0000000fU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_en = ((0x7fffU 
                                             & (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en)) 
                                            | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                 ? 
                                                ((((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                   & (0U 
                                                      != (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo))) 
                                                  & (0x0cU 
                                                     > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))) 
                                                 & (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                     == (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                    | (((IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l) 
                                                        > (IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lv)) 
                                                       & (~ (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has)))))
                                                 : 
                                                ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tv) 
                                                 & (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__has))) 
                                               << 0x0000000fU));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xffefffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     (0U 
                                                      == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                      : 
                                                     ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                      & (0U 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x00000014U));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xffdfffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00200000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((1U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U)
                                                          : 
                                                         (1U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 1U) 
                                                         & (1U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000015U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xffbfffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00400000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((2U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U)
                                                          : 
                                                         (2U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 2U) 
                                                         & (2U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000016U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xff7fffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x00800000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((3U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U)
                                                          : 
                                                         (3U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 3U) 
                                                         & (3U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000017U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfeffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x01000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((4U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U)
                                                          : 
                                                         (4U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 4U) 
                                                         & (4U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000018U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfdffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x02000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((5U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U)
                                                          : 
                                                         (5U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 5U) 
                                                         & (5U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x00000019U)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xfbffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x04000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((6U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U)
                                                          : 
                                                         (6U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 6U) 
                                                         & (6U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001aU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xf7ffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x08000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((7U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U)
                                                          : 
                                                         (7U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 7U) 
                                                         & (7U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001bU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xefffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x10000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((8U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U)
                                                          : 
                                                         (8U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 8U) 
                                                         & (8U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001cU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xdfffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x20000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((9U 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U)
                                                          : 
                                                         (9U 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 9U) 
                                                         & (9U 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001dU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0xbfffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (0x40000000U 
                                                    & (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                         ? 
                                                        ((0x0aU 
                                                          > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                          ? 
                                                         ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU)
                                                          : 
                                                         (0x0aU 
                                                          == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                         : 
                                                        (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                          >> 0x0aU) 
                                                         & (0x0aU 
                                                            >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                       << 0x0000001eU)));
    vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = ((0x7fffffffU 
                                                  & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]) 
                                                 | (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__tu)
                                                      ? 
                                                     ((0x0bU 
                                                       > (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l))
                                                       ? 
                                                      ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                       >> 0x0bU)
                                                       : 
                                                      (0x0bU 
                                                       == (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))
                                                      : 
                                                     (((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__t_lo) 
                                                       >> 0x0bU) 
                                                      & (0x0bU 
                                                         >= (IData)(tb_fe__DOT__dut__DOT__unnamedblk4__DOT__unnamedblk5__DOT__l)))) 
                                                    << 0x0000001fU));
    if ((1U & (~ ((IData)(vlSelfRef.tb_fe__DOT__dut__DOT__x_en) 
                  >> 0x0fU)))) {
        vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U] = 
            (0x000fffffU & vlSelfRef.tb_fe__DOT__dut__DOT__x_set[5U]);
    }
}

void Vtb_fe___024root___timing_ready(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___timing_ready\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h521be442__0.ready("@(posedge tb_fe.clk)");
    }
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h521be501__0.ready("@(negedge tb_fe.clk)");
    }
}

void Vtb_fe___024root___timing_resume(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___timing_resume\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h521be442__0.moveToResumeQueue(
                                                          "@(posedge tb_fe.clk)");
    vlSelfRef.__VtrigSched_h521be501__0.moveToResumeQueue(
                                                          "@(negedge tb_fe.clk)");
    vlSelfRef.__VtrigSched_h521be442__0.resume("@(posedge tb_fe.clk)");
    vlSelfRef.__VtrigSched_h521be501__0.resume("@(negedge tb_fe.clk)");
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_fe___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vtb_fe___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vtb_fe___024root____VbeforeTrig_h521be442__0(Vtb_fe___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root____VbeforeTrig_h521be442__0\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.tb_fe__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_fe__DOT__clk__0)) 
                                   << 1U) | ((IData)(vlSelfRef.tb_fe__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_fe__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_fe__DOT__clk__0 
        = vlSelfRef.tb_fe__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h521be442__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h521be442__0.ready(__VeventDescription);
    }
    if ((2ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h521be501__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vtb_fe___024root____VbeforeTrig_h521be501__0(Vtb_fe___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root____VbeforeTrig_h521be501__0\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.tb_fe__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_fe__DOT__clk__0)) 
                                   << 1U) | ((IData)(vlSelfRef.tb_fe__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_fe__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_fe__DOT__clk__0 
        = vlSelfRef.tb_fe__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h521be442__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h521be442__0.ready(__VeventDescription);
    }
    if ((2ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h521be501__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtb_fe___024root___eval_debug_assertions(Vtb_fe___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fe___024root___eval_debug_assertions\n"); );
    Vtb_fe__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
