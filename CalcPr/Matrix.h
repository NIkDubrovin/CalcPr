#pragma once
// Òþðèí
#include "Init.h"

typedef struct Matrix {
	const long rows, cols;
	double** arr;
	double det;
} Matrix;

void matrixCalc();
void outputMatrix(const Matrix&);
Matrix createMatrix(const long, const long);
void deleteMatrix(const long);
Matrix addMatrix(const Matrix&, const Matrix&);
Matrix subMatrix(const Matrix&, const Matrix&);
Matrix mulMatrix(const Matrix&, const Matrix&);
Matrix mulScalarMatrix(const Matrix&, double);
Matrix addScalarMatrix(const Matrix&, double);
Matrix subScalarMatrix(const Matrix&, double);
Matrix traspontMatrix(const Matrix&);
Matrix inverseMatrix(const Matrix&);
double detMatrix(const Matrix&);

