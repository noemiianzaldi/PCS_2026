#include <iostream>
#include <concepts>
#include "rational.hpp"

int main() {
    rational<int> r0(5,4);
    rational<int> r1(3,-6);
    rational<int> r2(1,2);
    rational<int> inf(5,0);
    rational<int> _inf(-5,0);
    rational<int> my_nan(0,0);

    std::cout << "semplificazione di 3/(-6) con gestione del segno: " << r1 << "\n";
    std::cout << "Not a number: 0/0 = " << my_nan << "\n";
    std::cout << "Infinito: 5/0 = " << inf << "\n";
    std::cout << "-Infinito: -5/0 = " << _inf << "\n";
    std::cout << "\n";

    // test di comportamento per Inf e NaN 
    std::cout << "test di comportamento per inf e NaN: \n";

    // Inf + rational = Inf
    rational<int> r3 = inf + r1;
    std::cout <<  "Inf + (" << r1 << ") = " << r3 << " (Previsto: +Inf) \n";
    rational<int> r4 = r2 + inf ;
    std::cout << r2 << " + Inf" << " = " << r4 << " (Previsto: +Inf) \n";

    // -Inf + rational = -Inf
    rational<int> r5 = _inf + r1;
    std::cout <<  "-Inf + (" << r1 << ") = " << r5 << " (Previsto: -Inf) \n";
    rational<int> r6 = _inf + r0;
    std::cout <<  "-Inf + " << r0 << " = " << r6 << " (Previsto: -Inf) \n";

    // Inf * razionale = +-Inf
    rational<int> r7 = inf * r1;
    std::cout <<  "Inf * (" << r1 << ") = " << r7 << " (Previsto: -Inf) \n";
    rational<int> r8 = inf * r0;
    std::cout <<  "Inf * " << r0 << " = " << r8 << " (Previsto: +Inf) \n";

    // -Inf * razionale = +-Inf
    rational<int> r9 = _inf * r1;
    std::cout <<  "-Inf * (" << r1 << ") = " << r9 << " (Previsto: +Inf) \n";
    rational<int> r10 = _inf * r2;
    std::cout <<  "-Inf * " << r2 << " = " << r10 << " (Previsto: -Inf) \n";

    // NaN + qualcosa = NaN
    rational<int> r11 = my_nan + r1;
    std::cout <<  "NaN + " << r0 << " = " << r11 << " (Previsto: NaN) \n";
    rational<int> r12 = my_nan + inf;
    std::cout <<  "NaN + Inf" << " = " << r12 << " (Previsto: NaN) \n";

    // Inf + (+-Inf) = NaN
    rational<int> r13 = inf + _inf;
    std::cout <<  "Inf + (-Inf) = " << r13 << " (Previsto: NaN) \n";

    // Inf * 0 = NanN
    rational<int> r14 = inf * 0;
    std::cout <<  "Inf * 0 = " << r14 << " (Previsto: NaN) \n";
    std::cout << "\n";


    // test sottrazione
    std::cout << "test sottrazione: \n";
    rational<int> r15 = r0-r1;
    std::cout << r0 << " - (" << r1 << ") = " << r15 << " (Previsto: 7/4) \n";
    rational<int> r16 = inf - r1;
    std::cout << "Inf - (" << r1 << ") = " << r16 << " (Previsto: +Inf) \n";
    rational<int> r17 = r2 - inf;
    std::cout << r2 << " - (" << inf << ") = " << r17 << " (Previsto: -Inf) \n";
    rational<int> r18 = r1 - _inf;
    std::cout << r1 << " - (" << _inf << ") = " << r18 << " (Previsto: +Inf) \n";
    rational<int> r19 = r1 + _inf;
    std::cout << r1 << " + (" << _inf << ") = " << r19 << " (Previsto: -Inf) \n";
    std::cout << "\n";

    // test divisione
    std::cout << "test divisione: \n";
    rational<int> r20 = r1/r0;
    std::cout << "(" << r1 << ") / (" << r0 << ") = " << r20 << " (Previsto: -2/5) \n";
    std::cout << "\n";

    // divisione per zero
    std::cout << "test divisione per zero: \n";
    rational<int> zero(0,1);
    rational<int> r21 = r0/zero;
    std::cout << "(" << r0 << ") / 0" << " = " << r21 << " (Previsto: +Inf) \n";
    rational<int> r22 = r1/zero;
    std::cout << "(" << r1 << ") / 0" << " = " << r22 << " (Previsto: -Inf) \n";
    std::cout << "\n";

    // divisione per Inf 
    std::cout << "test divisione per infinito: \n";
    rational<int> r23 = r2/inf;
    std::cout << "(" << r2 << ") / inf" << " = " << r23 << " (Previsto: 0) \n";
    std::cout << "\n";

    // Inf/Inf = NaN
    std::cout << "infinito/infinito: \n";
    rational<int> r24_1 = inf/inf;
    std::cout <<  "Inf/Inf  = " << r24_1 << " (Previsto: NaN) \n";
    rational<int> r24_2 = _inf/_inf;
    std::cout <<  "(-Inf)/(-Inf)  = " << r24_2 << " (Previsto: NaN) \n";
    rational<int> r24_3 = inf/inf;
    std::cout <<  "Inf/(-Inf)  = " << r24_3 << " (Previsto: NaN) \n";
    std::cout << "\n";

    //addizione tra razionali
    std::cout << "addizione tra razionali: \n";
    rational<int> r25 = r0+r2;
    std::cout <<  r0 << " + " << r2 << " = " << r25 << " (Previsto: 7/4) \n";
    r25 += r0;
    std::cout <<  "(7/4 += " << r0 << ") = " << r25 << " (Previsto: 3) \n";
    rational<int> r25_2(7,4);
    r25_2 += 0;
    std::cout << "(7/4 += 0) = " << r25_2 << " (Previsto: 7/4) \n";
    std::cout << "\n";

    //sottrazione tra razionali
    std::cout << "sottrazione tra razionali: \n";
    rational<int> r26 = r1-7;
    std::cout <<  r1 << " - 7 = " << r26 << " (Previsto: -15/2) \n";
    r26 -= r0;
    std::cout <<  "(-15/2 -= " << r0 << ") = " << r26 << " (Previsto: -35/4) \n";
    r26 -= 0;
    std::cout <<  "(-35/4 -= 0) = " << r26 << " (Previsto: -35/4) \n";
    std::cout << "\n";

    //moltiplicazione tra razionali
    std::cout << "moltiplicazione tra razionali: \n";
    rational<int> r27 = r2*r0;
    std::cout <<  r2 << " * " << r0 << " = " << r27 << " (Previsto: 5/8) \n";
    r27 *= 4;
    std::cout <<  "(5/8 *= 4) = " << r27 << " (Previsto: 5/2) \n";
    r27 *= 0;
    std::cout <<  "(-5/16 *= 0) = " << r27 << " (Previsto: 0) \n";
    std::cout << "\n";

    //divisione tra razionali
    std::cout << "divisione tra razionali: \n";
    rational<int> r28 = r1/r0;
    std::cout << "(" << r1 << ") / (" << r0 << ") = " << r28 << " (Previsto: -2/5) \n";
    r28 /= r2;
    std::cout <<  "((-2/5) /= " << r2 << ") = " << r28 << " (Previsto: -4/5) \n";
    r28 /= 0;
    std::cout <<  "((-4/5) /= 0) = " << r28 << " (Previsto: -Inf) \n";
    std::cout << "\n";
    
    return 0;
}