#pragma once
// Дубровин

typedef struct Odd {
	double x;
	double p;
} Odd;

void statisticCalc();
double findProbability(long n, long m);
double findDispersion(Odd* odds, long size, double M);
double findM(Odd* odds, long size);