#include "Statistics.h"

using namespace std;

void statisticCalc()
{

	int choose = -2;
	do
	{
		do
		{
			cout << "Выберите действие:\n1 - вероятность m/n\n2 - дисперсия для дискретного распределения величин\n3 - мат. ожидание для дискретного распределения величин\n4 - выйти в главное меню\n";
			cin >> choose;
		} while (choose != 1 && choose != 2 && choose != 3 && choose != 4);
		switch (choose)
		{
		case 1:
		{
			long n = -2, m = -2;
			do
			{
				cout << "Введите количество благоприятных исходов: ";
				cin >> m;
			} while (m < 0);
			do
			{
				cout << "Введите количество всех исходов: ";
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
	cout << "Вероятность этого события = " << double(double(m) / double(n)) << endl;
	return 0.0;
}

void findDispersion()
{
	long n = -2;
	double mean = 0, dispersion, x, p, sum;
	do
	{
		cout << "Введите количество значений в дискретном распределении : ";
		cin >> n;
	} while (n < 0);
	double* values = (double*)malloc(sizeof(double) * n); // значения в распределении
	double* probabilities = (double*)malloc(sizeof(double) * n); // вероятности
	for (int i = 0; i < n; i++)
	{
		cout << "Введите значение и вероятность для " << i + 1 << " - го элемента : ";
		cin >> values[i];
		cin >> probabilities[i];
	}

	// математическое ожидание
	findMCalc(n, mean, values, probabilities);

	// дисперсия
	dispersion = 0;
	for (int i = 0; i < n; i++) {
		x = values[i];
		p = probabilities[i];
		sum = (x - mean) * (x - mean) * p;
		dispersion += sum;
	}
	cout << "Дисперсия = " << dispersion << endl;
	free(values);
	free(probabilities);
}

void findM() 
{
	long cn;
	double M = 0;
	cout << "Введите количество значений: "; cin >> cn;
	while (!isCorrectInput() || cn <= 0)
	{
		cout << "Введите количество значений: "; cin >> cn;
	}
	double* values = (double*)malloc(sizeof(double) * cn);
	double* probabilities = (double*)malloc(sizeof(double) * cn);
	for (int i = 0; i < cn; i++)
	{
		cout << "Введите значение и вероятность (от 0 до 1) для " << i + 1 << " элемента: "; cin >> values[i] >> probabilities[i];
		while (!isCorrectInput())
		{
			cout << "Введите значение и вероятность (от 0 до 1) для " << i + 1 << " элемента: "; cin >> values[i] >> probabilities[i];
		}
		while ((probabilities[i] > 1 && probabilities[i] < 0) || !isCorrectInput())
		{
			cout << "Вероятность введена неверно. Введите вероятность от 0 до 1: "; cin >> probabilities[i];
		}
	}
	findMCalc(cn, M, values, probabilities);
	cout << "Математическое ожидание: " << M << endl;
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
