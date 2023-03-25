#pragma once
#include <iostream>
#include <math.h>

using namespace std;

typedef enum STATE{
    MENU,
    MATRIX,
    FRACTIONS,
    COMBINATORICS,
    FUNCTIONS,
    STATISTICS,
    POLINOMIALS,
    EXIT
} STATE;

void init();
unsigned char isCorrectInput();