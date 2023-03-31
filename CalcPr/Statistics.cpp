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
	for (int i = 0; i < n; i++) {
		x = values[i];
		p = probabilities[i];
		mean += x * p;
	}

	// дисперсия
	dispersion = 0;
	for (int i = 0; i < n; i++) {
		x = values[i];
		p = probabilities[i];
		sum = (x - mean) * (x - mean) * p;
		dispersion += sum;
	}
	cout << "Дисперсия = " << dispersion << endl;
}

double findM(Odd* odds, long size)
{
	return 0.0;
}
