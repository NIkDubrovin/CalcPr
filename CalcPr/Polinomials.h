#pragma once
#include "Calc.h"

// Солдатенко

typedef struct Polinomial {
	long n;
	double* koefs;
} Polinomial;

void polinomialCalc();
void deletePolinomial(Polinomial& polinomial);
Polinomial createPolinomial();
Polinomial addPolinmials(Polinomial&, Polinomial&);
Polinomial subPolinomials(Polinomial&, Polinomial&);
Polinomial mulPolinomials(Polinomial&, Polinomial&);
Polinomial mulScalarPolinomials(Polinomial&, double);
Polinomial divPolinomials(Polinomial&, Polinomial&);
Polinomial derivativePolnomial(Polinomial&);

