#pragma once
// tyurin
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <locale.h>
using namespace std;

struct matrix {
    double** data;
    int rows, cols;
};

void matrixCalc();
void outputMatrix(const matrix&);
matrix createMatrix(int rows, int cols);
matrix deleteMatrix(matrix& m);
void inputMatrix(matrix& m);
void outputMatrix(matrix& m);
matrix addMatrix(matrix& m1, matrix& m2);
matrix subMatrix(matrix& m1, matrix& m2);
matrix multMatrix(matrix& m1, matrix& m2);
matrix mult_ScalarToMatrix(matrix& m, double scalar);
matrix add_ScalarToMatrix(matrix& m1, int f);
matrix sub_ScalarToMatrix(matrix& m1, int f);
matrix traspontMatrix(matrix& m);
matrix inverseMatrix(matrix& m);
double detMatrix(matrix& m);