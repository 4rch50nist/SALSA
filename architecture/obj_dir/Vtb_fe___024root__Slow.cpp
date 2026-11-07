// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fe.h for the primary calling header

#include "Vtb_fe__pch.h"

void Vtb_fe___024root___ctor_var_reset(Vtb_fe___024root* vlSelf);

Vtb_fe___024root::Vtb_fe___024root(Vtb_fe__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_fe___024root___ctor_var_reset(this);
}

void Vtb_fe___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_fe___024root::~Vtb_fe___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
