
double IIR_low_pass_1000Hz_2nd_order[6] = { 0.00392209866199085940, 0.00784419732398171890, 0.00392209866199085940,
                                                     1.00000000000000000000, -1.81534108270456800000, 0.83100558934675750000 };


double IIR_high_pass_500Hz_2nd_order[6] = { 0.95466161616884615000, -1.90932323233769230000, 0.95466161616884615000,
                                                     1.00000000000000000000, -1.90750162605361280000, 0.91159449660707459000 };


double IIR_low_passB_1000Hz_2nd_order[6] = { 0.01442431635585372400,
        0.02884863271170744900,
        0.01442431635585372400,
                            1.00000000000000000000,
        -1.63299316185545160000,
        0.69059892324149674000 };

double second_order_IIR(double input, double* coefficients, double* x_history, double* y_history);