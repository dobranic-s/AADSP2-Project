
#include "IIR_low_pass_filter.h"
/**************************************
 * IIR filtar drugog reda
 *
 * input - ulazni odbirak
 * coefficients - koeficijenti [a0 a1 a2 b0 b2 b2]
 * z_x - memorija za ulazne odbirke (niz duzine 2)
 * z_y - memorija za izlazne odbirke (niz duzine 2)
 *
 * povratna vrednost - izlazni odbirak
 *
 *************************************/

//DSPfract* coef ;
DSPfract* x_h ;
DSPfract* y_h ;


DSPfract second_order_IIR(DSPfract input, DSPfract* coefficients, DSPfract* x_history, DSPfract* y_history) {
    DSPaccum output = FRACT_NUM(0.0);

   
    x_h = x_history;
    y_h = y_history;

    output += (*coefficients * input);        /* A0 * x(n)     */
    coefficients++;
    output += (*coefficients * *x_h); /* A1 * x(n-1) */
    coefficients++;
    x_h++;
    output += (*coefficients * *x_h); /* A2 * x(n-2)   */
    coefficients++;
    coefficients++;
    output -= (*coefficients * *y_h); /* B1 * y(n-1) */
    //output = output << 1;
    coefficients++;
    y_h++;
    output -= (*coefficients * *y_h); /* B2 * y(n-2)   */
 
     output = output << 1;
    *y_h = *y_history;    /* y(n-2) = y(n-1) */
    *y_history = output; /* y(n-1) = y(n)   */
    *x_h = *x_history;  /* x(n-2) = x(n-1) */
    *x_history = input;          /* x(n-1) = x(n)   */
    //output = output >> 1;
    return output;
}
