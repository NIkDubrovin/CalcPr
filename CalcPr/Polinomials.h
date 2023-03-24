#pragma once
#include "Calc.h"

// Солдатенко
#include<iostream>
#include <cmath>
using namespace std;
typedef struct Polinomial {
	long n;
	double* koefs;
} Polinomial;



void printPolynomial(Polinomial&);
void polinomialCalc();
void deletePolynomial(Polinomial& polinomial);
Polinomial createPolynomial(long);
Polinomial addPolynomials(Polinomial&, Polinomial&);
Polinomial subPolynomials(Polinomial&, Polinomial&);
Polinomial mulPolynomials(Polinomial&, Polinomial&);
Polinomial mulScalarPolynomial(Polinomial&, double);
Polinomial divPolynomials(Polinomial&, Polinomial&);
Polinomial derivativePolynomial(Polinomial&);

