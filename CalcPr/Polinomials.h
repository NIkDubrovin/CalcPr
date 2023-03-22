#pragma once

// Солдатенко
#include<iostream>
#include <cmath>
using namespace std;
typedef struct Polinomial {
	long n;
	double* koefs;
} Polinomial;

void polinomialCalc();
void deletePolinomial(Polinomial& polinomial);
Polinomial createPolinomial(long);
Polinomial addPolinmials(Polinomial&, Polinomial&);
Polinomial subPolinomials(Polinomial&, Polinomial&);
Polinomial mulPolinomials(Polinomial&, Polinomial&);
Polinomial mulScalarPolinomials(Polinomial&, double);
Polinomial divPolinomials(Polinomial&, Polinomial&);
Polinomial derivativePolnomial(Polinomial&);

