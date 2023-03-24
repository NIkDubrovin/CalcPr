#include "Functions.h"
#include "Polinomials.h"

void functionsCalc()
{
	int type = -1;
	func_t* func = nullptr;
	
	cout << "Function Calc\n";

	do 
	{
		cout << "0: Выбрать тип функции\n1: Выйти в меню\nВведите:";
		cin >> type;
	} while (!isCorrectInput());
		
	if (type == 0) {
		do
		{
			cout << "\nВыберите тип функции:\n0: Полином\n1: Степенная\n2: Показательная\n3: Логарифмическая\n4: Синусоида\n5: Косинусоида\n6: Меню\nВведите: ";
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

		//calcIntegral(func);
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
			cout << "\nВведите наибольшую степень: ";
			cin >> func->n;
			if (func->n < 1)
				cout << "Неверно введеная степень";
		} while (!isCorrectInput() && func->n < 1);

		func->koefs = (double*)malloc(sizeof(double) * (func->n + 1));
		if (func->koefs == nullptr)
			return nullptr;

		for (int i = 0; i <= func->n; i++)
		{
			while (1) {
				cout << "Введите a" << i << ": ";
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
			cout << "Введите a: ";
			cin >> func->koefs[0];
			cout << "Введите b: ";
			cin >> func->koefs[1];
			cout << "Введите c: ";
			cin >> func->koefs[2];

			if (func->koefs[1] == 0.0 && type == LOG) {
				cout << "Error! При b = 0 функция не определена;\n";
			}
		} while (!isCorrectInput() || (func->koefs[1] == 0.0 && type == LOG));
	}
	else if(type == SIN || type == COS || type == EXPONENTIAL){
		func->n = 4;
		func->koefs = (double*)malloc(func->n * sizeof(double));
		if (func->koefs == nullptr)
			return nullptr;

		do
		{
			cout << "Введите a: ";
			cin >> func->koefs[0];
			cout << "Введите b: ";
			cin >> func->koefs[1];
			cout << "Введите c: ";
			cin >> func->koefs[2];
			cout << "Введите d: ";
			cin >> func->koefs[3];

			if (func->koefs[1] <= 0.0 && type == EXPONENTIAL) {
				cout << "Error! При b <= 0 функция не определена;\n";
			}

		} while (!isCorrectInput() || (func->koefs[1] == 0.0 && type == EXPONENTIAL));
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

	cout << "Вычисление определенного интеграла:\n";
	do {
		cout << "Введите a: ";
		cin >> a;
		cout << "Введите b: ";
		cin >> b;

		if (func->type == POLYNOMIAL || func->type == POWER || func->type == LOG) {
			if (a == 0.0)
				if (b < a)
					a -= minExp;
				else if (b > a)
					a += minExp;

			if(b == 0.0)
				if (b < a)
					b += minExp;
				else if (b > a)
					a -= minExp;

			if (b == 0.0 && a == 0.0)
				cout << "Error! Функция неопределена на данном значении!\n";

		}
			
	} while (!isCorrectInput());
	
	cout << "Integral: " << a << " | " << b << " (";

	switch (func->type)
	{
	case POLYNOMIAL: 
	{
		for (long i = 0; i < (func->n + 1); i++)
		{
			if (i != 0)
				cout << " + ";

			cout << func->koefs[i] << "*x^" << i;
			integralA += func->koefs[i] * pow(a, double(i + 1)) / (double)(i + 1);
			integralB += func->koefs[i] * pow(b, double(i + 1)) / (double)(i + 1);
		}
	}
	break;
	case POWER:
	{
		cout << func->koefs[0] << "*x^" << func->koefs[1] << "+" << func->koefs[2];

		if (func->koefs[1] != -1.0) {
			integralA = func->koefs[0] * pow(a, func->koefs[1] + 1.0) / (func->koefs[1] + 1.0) + func->koefs[2] * a;
			integralB = func->koefs[0] * pow(b, func->koefs[1] + 1.0) / (func->koefs[1] + 1.0) + func->koefs[2] * b;
		}
		else {
			integralA = func->koefs[0] * log(abs(a)) + func->koefs[2] * a;
			integralB = func->koefs[0] * log(abs(b)) + func->koefs[2] * b;
		}
	}
	break;
	case EXPONENTIAL: 
	{
		cout << func->koefs[0] << "*" << func->koefs[1] << "^(" << func->koefs[2] << "*x) + " << func->koefs[3];

		if (func->koefs[1] == 0.0) { // b = 0
			return 0;
		}
		if (func->koefs[2] == 0.0) { // c = 0;
			integralA = func->koefs[0] * a + func->koefs[3] * a;
			integralA = func->koefs[0] * b + func->koefs[3] * b;
		}
		integralA = func->koefs[0] / func->koefs[2] * pow(func->koefs[1], func->koefs[2] * a) / log(func->koefs[1]) + func->koefs[3] * a;
		integralB = func->koefs[0] / func->koefs[2] * pow(func->koefs[1], func->koefs[2] * b) / log(func->koefs[1]) + func->koefs[3] * b;
	}
	break;
	case LOG:
	{
		cout << func->koefs[0] << "* ln(" << func->koefs[1] << "*x) + " << func->koefs[2];

		integralA = func->koefs[0] * log(func->koefs[1] * a) * a - func->koefs[0] * a + func->koefs[2] * a;
		integralB = func->koefs[0] * log(func->koefs[1] * b) * b - func->koefs[0] * b + func->koefs[2] * b;
	}
	break;
	case SIN: 
	{
		cout << func->koefs[0] << "* sin(" << func->koefs[1] << "*x + " << func->koefs[2] << ") + " << func->koefs[3];

		if (func->koefs[1] == 0) {
			integralA = func->koefs[0] * sin(func->koefs[2]) * a + func->koefs[3] * a;
			integralB = func->koefs[0] * sin(func->koefs[2]) * b + func->koefs[3] * b;
		}
		else {
			integralA = -func->koefs[0] / func->koefs[1] * cos(func->koefs[1] * a + func->koefs[2]) + func->koefs[3] * a;
			integralB = -func->koefs[0] / func->koefs[1] * cos(func->koefs[1] * b + func->koefs[2]) + func->koefs[3] * b;
		}
	}
	break;
	case COS: 
	{
		cout << func->koefs[0] << "* cos(" << func->koefs[1] << "*x) + " << func->koefs[2];

		if (func->koefs[1] == 0) {
			integralA = func->koefs[0] * cos(func->koefs[2]) * a + func->koefs[3] * a;
			integralB = func->koefs[0] * cos(func->koefs[2]) * b + func->koefs[3] * b;
		}
		else
		{
			integralA = func->koefs[0] / func->koefs[1] * sin(func->koefs[1] * a + func->koefs[2]) + func->koefs[3] * a;
			integralB = func->koefs[0] / func->koefs[1] * sin(func->koefs[1] * b + func->koefs[2]) + func->koefs[3] * b;
		}
	}
	break;
	default: 
	{
		cout << ") = " << "Error! Неправильный тип функции.\n" << endl;
		return 0;
	}
	}

	cout << ") = " << integralA - integralB << " + C;" << endl << "\n";

	return 1;
}

int drawGraph(const func_t * func)
{
	return 0.0;
}

// return 0 - hasnt roots
// return 1 - R
// return 2 - has roots
// return -1 - error
int funcRoots(const func_t* func, double* roots, int& rootsCount)
{
	double A = 0, B = 0, a = 0, b = 0, c = 0, d = 0, root = 0;

	if (func == nullptr || roots == nullptr)
		return -1;

	if (func->koefs == nullptr || !isTypeFunc(func->type))
		return -1;

	if (func->type != POLYNOMIAL) {
		a = func->koefs[0];
		b = func->koefs[1];
		c = func->koefs[2];

		if (func->n == 4)
			d = func->koefs[3];
	}

	switch (func->type)
	{
	case POLYNOMIAL:
	{
		polynomRealRoots(func->n, func->koefs, roots, rootsCount);
		if (rootsCount == 0)
			return 0;
		else 
			return 2;
	}
	break;
	case POWER:
	{
		if (c == 0.0 || a == 0.0)
		{
			return 0;
		}
		else if (b == 0.0) {
			if (abs(-c / a - 1.0) < minExp)
				return 1;
			else
				return 0;
		}
		else if (-c / a < 0.0)
			return 0;
		else
		{
			root = pow(-c / a, 1.0 / b);
		}
	}
	break;
	case EXPONENTIAL:
	{
		if (d == 0.0 || a == 0.0 || b == 0.0)
			return 0;
		else if (c == 0.0) {
			if (abs(-d / a - 1.0) < minExp)
				return 1;
			else
				return 0;
		}
		else if (-d / a < 0.0)
			return 0;
		else
		{
			root = log(-d / a) / (c * log(b));
		}
	}
	break;
	case LOG:
	{
		if (a == 0.0 || b == 0.0) {
			return 0;
		}
		else if (c == 0.0) {
			root = 1.0 / b;
		}
		else {
			root = exp(-c / a) / b;
		}
	}
	break;
	case SIN:
	{
		if (a == 0.0 || b == 0.0)
			return 0;
		else if (-d / a > 1.0 || -d / a < -1.0)
			return 0;
		else
		{
			root = (asin(-d / a) - c) / b;
		}
	}
	break;
	case COS:
	{
		if (a == 0.0 || b == 0.0)
			return 0;
		else if (-d / a > 1.0 || -d / a < -1.0)
			return 0;
		else
		{
			root = (acos(-d / a) - c) / b;
		}
	}
	break;
	default: return -1;
	}

	roots[0] = root;
	rootsCount = 1;
	return 2;
}

int searchRoots(const func_t* func)
{
	double A = 0, B = 0, a = 0, b = 0, c = 0, d = 0, * roots = nullptr;
	int rootsCount = 0, res = 0;

	if (func == nullptr)
		return 0;

	if (func->koefs == nullptr)
		return 0;

	if (func->n < 1 || !isTypeFunc(func->type))
		return 0;

	cout << "Поиск корней уравнения на отрезке;\n";

	do {
		cout << "Введите A: ";
		cin >> A;
		cout << "Введите B: ";
		cin >> B;

		if (A > B)
			cout << "Error! A > B;\n";
	} while (!isCorrectInput() || A > B);

	if ((roots = (double*)malloc(sizeof(double) * func->n)) == nullptr)
		return 0;
	
	if((res = funcRoots(func, roots, rootsCount)) == -1) 
	{
		free(roots);
		return 0;
	}
		
	if (func->type == POLYNOMIAL) 
	{
		for (long i = 0; i < (func->n + 1); i++)
		{
			if (i != 0)
				cout << " + ";

			cout << func->koefs[i] << "*x^" << i;
		}
		cout << " = 0\nКорни: ";

		if (res == 0)
			cout << "Корней нет;";
		else
			for (long i = 0; i < rootsCount; i++)
			{
				cout << roots[i] << " ";
			}

		cout << endl;
	}
	else 
	{
		switch (func->type)
		{
		case POWER:
			cout << a << " * x^" << b << " + " << c << endl;;
			break;
		case EXPONENTIAL: 
			cout << a << " * " << b << "^(" << c << " * x) + " << d << endl;
			break;
		case LOG: 
			cout << a << " * ln(" << b << " * x) + " << c << endl;;
			break;
		case SIN:
			cout << a << " * sin(" << b << " * x + " << c << ") + " << d << endl;
			break;
		case COS:
			cout << a << " * cos(" << b << " * x + " << c << ") + " << d << endl;
			break;
		default:
			break;
		}

		if (res == 0)
			cout << "Корней нет;" << endl;
		else if (res == 1)
			cout << "R" << endl;
		else
			cout << roots[0] << endl;
	}

	free(roots);
	return 1;
}

int searchExtremum(const func_t* func)
{
	double A = 0, B = 0, a = 0, b = 0, c = 0, d = 0, * roots = nullptr, * nkoefs = nullptr;
	int rootsCount = 0, res = 0;

	if (func == nullptr)
		return 0;

	if (func->koefs == nullptr)
		return 0;

	if (func->n < 1 || !isTypeFunc(func->type))
		return 0;

	cout << "Поиск экстремумов функции на отрезке;\n";

	do {
		cout << "Введите A: ";
		cin >> A;
		cout << "Введите B: ";
		cin >> B;

		if (A > B)
			cout << "Error! A > B;\n";
	} while (!isCorrectInput() || A > B);

	if(func->type == LOG || func->type == EXPONENTIAL)
	{
		cout << "Экстремумов нет;\n";
		return 1;
	}

	if ((roots = (double*)malloc(sizeof(double) * func->n)) == nullptr)
		return 0;

	
	if (func->type == POLYNOMIAL)
	{
		func->koefs[0] = func->koefs[1]; // a0 = a1
		for (int i = 1; i < func->n; i++)
		{
			func->koefs[i - 1] = func->koefs[i] * i;
		}

		func->n = func->n - 1;

		res = funcRoots(func, roots, rootsCount);

		if (res == 0)
			cout << "";
		else
			for (long i = 0; i < rootsCount; i++)
			{
				cout << roots[i] << " ";
			}

		cout << endl;
	}
	else
	{
		switch (func->type)
		{
		case POWER:
			cout << a << " * x^" << b << " + " << c << endl;;
			break;
		case EXPONENTIAL:
			cout << a << " * " << b << "^(" << c << " * x) + " << d << endl;
			break;
		case LOG:
			cout << a << " * ln(" << b << " * x) + " << c << endl;;
			break;
		case SIN:
			cout << a << " * sin(" << b << " * x + " << c << ") + " << d << endl;
			break;
		case COS:
			cout << a << " * cos(" << b << " * x + " << c << ") + " << d << endl;
			break;
		default:
			break;
		}

	}

	return 0;
}

// return (type >= 0 && type <= 5);
int isTypeFunc(int type)
{
	return (type >= 0 && type <= 5);
}
