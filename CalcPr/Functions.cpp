#include "Functions.h"
#include "Polinomials.h"

void functionsCalc()
{
	int type = 0, size = 0;
	double* koefs = nullptr, a = 0, b = 0;
	Func func;
	Polinomial polinom;

	do {
		cout << "0: Выбрать тип функции\n1: Выйти в меню\nВведите:";
		cin >> type;
		if (type != 0)
			break;

		cout << "\nВыберите тип функции:\n0: Полином\n1: Степенная\n2: Показательная\n3: Логарифмическая\n4: Синусоида\n5: Косинусоида\nВведите: ";
		cin >> type;
		switch (type)
		{
		case POLYNOMIAL:
		{
			long exp = 0;
			cout << "\nВведите наибольшую степень: ";
			cin >> exp;
			if (exp < 0)
				cout << "Неверно введеная степень\n";
			else {
				polinom = createPolinomial(exp);
			}
		}
		break;
		case POWER: 
		{
			size = 3;
			koefs = (double*)malloc( size * sizeof(double));
			cout << "a*x^b + c\n";
			cout << "Введите a: ";
			cin >> koefs[0];
			cout << "Введите b: ";
			cin >> koefs[1];
			cout << "Введите c: ";
			cin >> koefs[2];
		}
		break;
		case EXPONENTIAL:
			break;
		case LOG:
			break;
		case SIN:
			break;
		case COS:
			break;
		default:
			break;
		}

		cout << "Введите a: ";
		cin >> a;
		cout << "Введите b: ";
		cin >> b;

		func = (Func)type;
		calcIntegral(func, koefs, size, a, b);
		drawGraph(func, koefs, size);
		searchRoots(func, koefs, size);
		searchExtremum(func, koefs, size);

	} while (1);

	
}

double calcIntegral(FUNC func, double* Ks, long size, double a, double b)
{
	return 10;
}

double drawGraph(FUNC func, double* Ks, long size)
{
	return 0.0;
}

double* searchRoots(FUNC, double* Ks, long size)
{
	return nullptr;
}

double* searchExtremum(FUNC, double* Ks, long size)
{
	return nullptr;
}
