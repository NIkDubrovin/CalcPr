#include "Statistics.h"

using namespace std;

void statisticCalc()
{

	int choose = -2;
	do
	{
		do
		{
			cout << "¬ыберите действие:\n1 - веро€тность m/n\n2 - дисперси€ дл€ дискретного распределени€ величин\n3 - мат. ожидание дл€ дискретного распределени€ величин\n4 - выйти в главное меню\n";
			cin >> choose;
		} while (choose != 1 && choose != 2 && choose != 3 && choose != 4);
		switch (choose)
		{
		case 1:
		{
			long n = -2, m = -2;
			do
			{
				cout << "¬ведите количество благопри€тных исходов: ";
				cin >> m;
			} while (m < 0);
			do
			{
				cout << "¬ведите количество всех исходов: ";
				cin >> n;
			} while (n <= 0);
			findProbability(n, m);

		}break;
		case 2:
		{
			findDispersion();
		}break;
		case 3:
		{
			findM();
		}break;
		}
	} while (choose != 4);
}

double findProbability(long n, long m)
{
	cout << "¬еро€тность этого событи€ = " << double(double(m) / double(n)) << endl;
	return 0.0;
}

void findDispersion()
{
	long n = -2;
	double mean = 0, dispersion, x, p, sum;
	do
	{
		cout << "¬ведите количество значений в дискретном распределении : ";
		cin >> n;
	} while (n < 0);
	double* values = (double*)malloc(sizeof(double) * n); // значени€ в распределении
	double* probabilities = (double*)malloc(sizeof(double) * n); // веро€тности
	for (int i = 0; i < n; i++)
	{
		cout << "¬ведите значение и веро€тность дл€ " << i + 1 << " - го элемента : ";
		cin >> values[i];
		cin >> probabilities[i];
	}

	// математическое ожидание
	findMCalc(n, mean, values, probabilities);

	// дисперси€
	dispersion = 0;
	for (int i = 0; i < n; i++) {
		x = values[i];
		p = probabilities[i];
		sum = (x - mean) * (x - mean) * p;
		dispersion += sum;
	}
	cout << "ƒисперси€ = " << dispersion << endl;
	free(values);
	free(probabilities);
}

void findM() 
{
	long cn;
	double M = 0;
	cout << "¬ведите количество значений: "; cin >> cn;
	while (cn < 0)
	{
		cout << " оличество значений не может быть равно нулю или быть отрицательным. ¬ведите количество значений: "; cin >> cn;
	}
	double* values = (double*)malloc(sizeof(double) * cn);
	double* probabilities = (double*)malloc(sizeof(double) * cn);
	for (int i = 0; i < cn; i++)
	{
		cout << "¬ведите значение и веро€тность дл€ " << i + 1 << " элемента: "; cin >> values[i] >> probabilities[i];
	}
	findMCalc(cn, M, values, probabilities);
	cout << "ћатематическое ожидание: " << M << endl;
	free(values);
	free(probabilities);
}
void findMCalc(long& cn, double& M, double * values, double * probabilities)
{
	double x, p;
	for (int i = 0; i < cn; i++)
	{
		x = values[i];
		p = probabilities[i];
		M += p * x;
	}
}
