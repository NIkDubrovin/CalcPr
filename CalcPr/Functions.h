#pragma once
#include "Calc.h"
#include "polynomRealRoots.h"
#include "sdl/include/SDL.h"
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
int funcExtremums(const func_t*, double& A, double& B, double* extremums, int& extremumsCount);
int searchExtremum(const func_t*);
int isTypeFunc(int type);
int funcValue(const func_t*, double, double*);
int copyFunc(func_t* dist, const func_t* src);