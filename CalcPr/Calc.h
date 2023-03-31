#pragma once
#include <iostream>
#include <math.h>
#include <Windows.h>

using namespace std;

typedef enum STATE{
    MENU,
    MATRIX,
    FRACTIONS,
    COMBINATORICS,
    FUNCTIONS,
    STATISTICS,
    POLYNOMIALS,
    EXIT
} STATE;

void init();
unsigned char isCorrectInput();
void clearScreen();