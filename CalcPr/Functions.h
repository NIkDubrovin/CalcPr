#pragma once
#include "Init.h"
// Дубровин

typedef enum FUNC {
	POLYNOMIAL,
	POWER,
	EXPONENTIAL,
	LOG,
	SIN,
	COS
} Func;

void functionsCalc();
double calcIntegral(FUNC func, double* Ks, long size, double a, double b);
double drawGraph(FUNC func, double* Ks, long size);
double* searchRoots(FUNC, double* Ks, long size);
double* searchExtremum(FUNC, double* Ks, long size);
