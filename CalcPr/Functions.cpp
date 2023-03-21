#include "Functions.h"
#include "Polinomials.h"
#include "Calc.h"

int functionsCalc()
{
	int type = -1;
	func_t* func = nullptr;
	
	cout << "Function Calc\n";

	do 
	{
		cout << "0: ������� ��� �������\n1: ����� � ����\n�������:";
		cin >> type;
	} while (!isCorrectInput());
		
	if (type == 0) {
		do
		{
			cout << "\n�������� ��� �������:\n0: �������\n1: ���������\n2: �������������\n3: ���������������\n4: ���������\n5: �����������\n6: ����\n�������: ";
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
			return 1;
		}

		if ((func = createFunc((Type)type)) == nullptr)
			return 0;

		calcIntegral(func);
		drawGraph(func);
		searchRoots(func);
		searchExtremum(func);

		deleteFunc(func);
		return 1;
	}
	return 1;
}

func_t* createFunc(const Type& type) {
	
	func_t* func = (func_t*)malloc(sizeof(func_t));
	if (func == nullptr)
		return nullptr;
		 
	if (type == POLYNOMIAL) {
		do {
			cout << "\n������� ���������� �������: ";
			cin >> func->n;
			if (func->n < 0)
				cout << "������� �������� �������";
		} while (!isCorrectInput() && func->n < 0);

		func->koefs = (double*)malloc(sizeof(double) * (func->n + 1));
		if (func->koefs == nullptr)
			return nullptr;

		for (int i = 0; i <= func->n; i++)
		{
			while (1) {
				cout << "������� a" << i << ": ";
				cin >> func->koefs[i];
				if (isCorrectInput())
					break;
			}
		}
	}
	else if (type == POWER || type == LOG) {
		func->n = 3;
		func->koefs = (double*)malloc(func->n * sizeof(double));
		if (func->koefs == nullptr)
			return nullptr;

		do
		{
			cout << "������� a: ";
			cin >> func->koefs[0];
			cout << "\n������� b: ";
			cin >> func->koefs[1];
			cout << "\n������� c: ";
			cin >> func->koefs[2];
		} while (!isCorrectInput());
	}
	else if(type == SIN || type == COS || type == EXPONENTIAL){
		func->n = 4;
		func->koefs = (double*)malloc(func->n * sizeof(double));
		if (func->koefs == nullptr)
			return nullptr;

		do
		{
			cout << "������� a: ";
			cin >> func->koefs[0];
			cout << "\n������� b: ";
			cin >> func->koefs[1];
			cout << "\n������� c: ";
			cin >> func->koefs[2];
			cout << "\n������� d: ";
			cin >> func->koefs[3];
		} while (!isCorrectInput());
	}
	else
		return nullptr;

	func->type = type;

	return func;
}

void deleteFunc(func_t * func)
{
	if (func != nullptr) {
		free(func->koefs);
		free(func);
	}
}

int calcIntegral(const func_t * func)
{
	double integralA = 0, integralB = 0, a = 0, b = 0;
	if (func == nullptr)
		return 0;

	if (func->koefs == nullptr)
		return 0;

	cout << "���������� ������������� ���������:\n";
	do {
		cout << "������� a: ";
		cin >> a;
		cout << "������� b: ";
		cin >> b;
	} while (!isCorrectInput());
	
	switch (func->type)
	{
	case POLYNOMIAL: 
	{
		cout << "Integral: " << a << " | " << b << " (";
		for (long i = 0; i < (func->n + 1); i++)
		{
			if (i != 0)
				cout << " + ";

			cout << func->koefs[i] << "*x^" << i;;
			integralA += func->koefs[i] * pow(a, double(i + 1)) / (double)(i + 1);
			integralB += func->koefs[i] * pow(b, double(i + 1)) / (double)(i + 1);
		}

		cout << ") = " << integralA - integralB << endl << "\n";
	}
	break;
	case POWER:
	{

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


	return 10;
}

int drawGraph(const func_t * func)
{
	return 0.0;
}

int searchRoots(const func_t* func)
{
	return 0;
}

int searchExtremum(const func_t* func)
{
	return 0;
}
