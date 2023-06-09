#pragma once
#include "Calc.h"
// ��������

typedef struct Fraction {
	long intPart;
	long numerator; // ���������
	long denominator; // �����������
} Fraction;
int isSimple(int);
void fractionsCalc();
void outputFraction(const Fraction&);
Fraction createFraction();
Fraction addFraction(const Fraction&, const Fraction&);
Fraction subFraction(const Fraction&, const Fraction&);
Fraction mulFraction(const Fraction&, const Fraction&);
Fraction divFraction(const Fraction&, const Fraction&);
unsigned char compareFraction(Fraction&, Fraction&);
Fraction reductinFraction(Fraction);
double decimalFraction(const Fraction&);

