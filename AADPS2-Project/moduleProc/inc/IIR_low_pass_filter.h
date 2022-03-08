#include "common.h"
DSPfract second_order_IIR( DSPfract input,__memX DSPfract* coefficients, __memY DSPfract* x_history, __memY DSPfract* y_history);
//DSPfract second_order_IIR_high(DSPfract input, DSPfract* coefficients, DSPfract* x_history, DSPfract* y_history);
extern DSPfract second_order_IIR_asm( DSPfract input,__memX DSPfract* coefficients, __memY DSPfract* x_history, __memY DSPfract* y_history);
