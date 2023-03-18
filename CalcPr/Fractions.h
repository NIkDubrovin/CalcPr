#pragma once
#include "Init.h"
// ��������

typedef struct Fraction {
	long intPart;
	long numerator; // ���������
	long denominator; // �����������
} Fraction;

void fractionsCalc();
void outputFraction(const Fraction&);
Fraction createFraction();
Fraction addFraction(const Fraction&, const Fraction&);
Fraction subFraction(const Fraction&, const Fraction&);
Fraction mulFraction(const Fraction&, const Fraction&);
Fraction divFraction(const Fraction&, const Fraction&);
unsigned char compareFraction(const Fraction&, const Fraction&);
Fraction reductinFraction(const Fraction);
double decimalFraction(const Fraction&);

