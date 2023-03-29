#pragma once
#include "Calc.h"
#include "polynomRealRoots.h"
// Дубровин

typedef enum TYPE_FUNC {
	POLYNOMIAL,
	POWER,
	EXPONENTIAL,
	LOG,
	SIN,
	COS
} Type;

typedef struct FUNC {
	long n;
	double* koefs;
	Type type;
} func_t;

static double minExp = 1e-5;


func_t* createFunc(const Type&);
void deleteFunc(func_t *);
int functionsCalc();
int calcIntegral(const func_t*);
int drawGraph(const func_t*);
int searchRoots(const func_t*);
int funcRoots(const func_t*, double* roots, int& rootsCount);
int searchExtremum(const func_t*);
int isTypeFunc(int type);