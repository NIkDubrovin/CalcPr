#include "Functions.h"
#include "Polinomials.h"
#include "Calc.h"

void functionsCalc()
{
	int type = -1, size = 0;
	double* koefs = nullptr, a = 0, b = 0;
	Func func;
	Polinomial polinom;

	cout << "Function Calc\n";

	do 
	{
		cout << "0: Выбрать тип функции\n1: Выйти в меню\nВведите:";
		cin >> type;
	} while (!isCorrectInput());
		
	if (type == 0) {
		do
		{
			cout << "\nВыберите тип функции:\n0: Полином\n1: Степенная\n2: Показательная\n3: Логарифмическая\n4: Синусоида\n5: Косинусоида\nВведите: ";
			cin >> type;
		} while (!isCorrectInput());
		
		switch (type)
		{
		case POLYNOMIAL: cout << "a0 + a1*x + a2*x^2 + ... + an*x^n\n";	break;
		case POWER:		 cout << "a*x^b + c\n"; break;
		case EXPONENTIAL:cout << "a*b^(c*x) + d\n"; break;
		case LOG:		 cout << "a*ln(b*x) + c\n";  break;
		case SIN:		 cout << "a*sin(b*x + c) + d\n"; break;
		case COS:        cout << "a*cos(b*x + c) + d\n"; break; 
		default:
			break;
		}

		if (type == POLYNOMIAL) {
			long exp = 0;
			cout << "\nВведите наибольшую степень: ";
			do {
				cin >> exp;
			} while (!isCorrectInput());

			if (exp < 0)
				cout << "Неверно введеная степень\n";
			else {
				polinom = createPolinomial(exp);
			}
		}
		else if (type == POWER || type == LOG) {
			size = 3;
			koefs = (double*)malloc(size * sizeof(double));
			
			do
			{
				cout << "Введите a: ";
				cin >> koefs[0];
				cout << "Введите b: ";
				cin >> koefs[1];
				cout << "Введите c: ";
				cin >> koefs[2];
			} while (!isCorrectInput());
		}
		else {
			size = 4;
			koefs = (double*)malloc(size * sizeof(double));
			cout << "a*x^b + c\n";
			do
			{
				cout << "Введите a: ";
				cin >> koefs[0];
				cout << "Введите b: ";
				cin >> koefs[1];
				cout << "Введите c: ";
				cin >> koefs[2];
				cout << "Введите d: ";
				cin >> koefs[3];
			} while (!isCorrectInput());
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

		free(koefs);
	}
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
