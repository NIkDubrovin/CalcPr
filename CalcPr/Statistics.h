#pragma once
#include "Calc.h"
#include <malloc.h>
// Гаврилов дисперсия и вероятность
// Cтафеев мат ожидание

typedef struct Odd {
	double x;
	double p;
} Odd;

void statisticCalc();
double findProbability(long n, long m);
void findDispersion();
void findM();
void findMCalc(long& cn, double& M, double* values, double* probabilities);  