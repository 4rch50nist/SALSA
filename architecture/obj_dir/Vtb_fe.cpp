// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_fe__pch.h"

//============================================================
// Constructors

Vtb_fe::Vtb_fe(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_fe__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_fe::Vtb_fe(const char* _vcname__)
    : Vtb_fe(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_fe::~Vtb_fe() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_fe___024root___eval_debug_assertions(Vtb_fe___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtb_fe___024root___eval_static(Vtb_fe___024root* vlSelf);
void Vtb_fe___024root___eval_initial(Vtb_fe___024root* vlSelf);
VL_ATTR_COLD bool Vtb_fe___024root___eval_stl(Vtb_fe___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vtb_fe___024root___eval_sample(Vtb_fe___024root* vlSelf);
bool Vtb_fe___024root___eval_ico(Vtb_fe___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vtb_fe___024root___eval_act(Vtb_fe___024root* vlSelf);
bool Vtb_fe___024root___eval_inact(Vtb_fe___024root* vlSelf);
bool Vtb_fe___024root___eval_nba(Vtb_fe___024root* vlSelf);
bool Vtb_fe___024root___eval_obs(Vtb_fe___024root* vlSelf);
bool Vtb_fe___024root___eval_react(Vtb_fe___024root* vlSelf);
void Vtb_fe___024root___eval_postponed(Vtb_fe___024root* vlSelf);
VL_ATTR_COLD void Vtb_fe___024root___eval_final(Vtb_fe___024root* vlSelf);
VL_ATTR_COLD void Vtb_fe___024root___eval_dump_triggers__stl(Vtb_fe___024root* vlSelf);
VL_ATTR_COLD void Vtb_fe___024root___eval_dump_triggers__ico(Vtb_fe___024root* vlSelf);
VL_ATTR_COLD void Vtb_fe___024root___eval_dump_triggers__act(Vtb_fe___024root* vlSelf);
VL_ATTR_COLD void Vtb_fe___024root___eval_dump_triggers__nba(Vtb_fe___024root* vlSelf);
VL_ATTR_COLD void Vtb_fe___024root___eval_dump_triggers__obs(Vtb_fe___024root* vlSelf);
VL_ATTR_COLD void Vtb_fe___024root___eval_dump_triggers__react(Vtb_fe___024root* vlSelf);

void Vtb_fe::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_fe::eval_step\n"); );
    m_evalLoop.eval();
}

void Vtb_fe::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_fe___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vtb_fe::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
    vlSymsp->TOP.__VdlySched.cleanupForevered();
}

void Vtb_fe::evalStatic() {
    Vtb_fe___024root___eval_static(&(vlSymsp->TOP));
}

void Vtb_fe::evalInitial() {
    Vtb_fe___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vtb_fe::evalStl(bool firstIteration) {
    return Vtb_fe___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vtb_fe::evalSample() {
    Vtb_fe___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vtb_fe::evalIco(bool firstIteration) {
    return Vtb_fe___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vtb_fe::evalAct() {
    return Vtb_fe___024root___eval_act(&(vlSymsp->TOP));
}

bool Vtb_fe::evalInact() {
    return Vtb_fe___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vtb_fe::evalNba() {
    return Vtb_fe___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vtb_fe::evalObs() {
    return Vtb_fe___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vtb_fe::evalReact() {
    return Vtb_fe___024root___eval_react(&(vlSymsp->TOP));
}

void Vtb_fe::evalPostponed() {
    Vtb_fe___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vtb_fe::evalFinal() {
    Vtb_fe___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_fe::dumpTriggersStl() {
    Vtb_fe___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_fe::dumpTriggersIco() {
    Vtb_fe___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_fe::dumpTriggersAct() {
    Vtb_fe___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_fe::dumpTriggersNba() {
    Vtb_fe___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_fe::dumpTriggersObs() {
    Vtb_fe___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_fe::dumpTriggersReact() {
    Vtb_fe___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

//============================================================
// Events and timing
bool Vtb_fe::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_fe::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_fe::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vtb_fe::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_fe::hierName() const { return vlSymsp->name(); }
const char* Vtb_fe::modelName() const { return "Vtb_fe"; }
unsigned Vtb_fe::threads() const { return 1; }
void Vtb_fe::prepareClone() const { contextp()->prepareClone(); }
void Vtb_fe::atClone() const {
    contextp()->threadPoolpOnClone();
}
