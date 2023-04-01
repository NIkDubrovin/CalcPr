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
		cout << "0: Выбрать тип функции\n1: Выйти в меню\nВведите:";
		cin >> type;
	} while (!isCorrectInput());
		
	clearScreen();

	if (type == 0) {
		do
		{
			cout << "\nВыберите тип функции:\n0: Полином\n1: Степенная\n2: Показательная\n3: Логарифмическая\n4: Синусоида\n5: Косинусоида\n6: Меню\nВведите: ";
			cin >> type;
		} while (!isCorrectInput());

		clearScreen();

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
		searchRoots(func);
		searchExtremum(func);
		drawGraph(func);

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
		} while (!isCorrectInput() || func->n < 1);

		func->n++; // a0
		func->koefs = (double*)malloc(sizeof(double) * (func->n));
		if (func->koefs == nullptr)
			return nullptr;

		for (int i = 0; i < func->n; i++)
		{
			while (1) {
				cout << "Введите a" << i << ": ";
				cin >> func->koefs[i];
				if (isCorrectInput())
					break;
			}

			if (i == func->n - 1 && func->koefs[i] == 0.0) 
			{
				cout << "an не может быть = 0" << endl;
				i--;
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

		} while (!isCorrectInput() || (func->koefs[1] <= 0.0 && type == EXPONENTIAL));
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
		cout << "Введите A: ";
		cin >> a;
		cout << "Введите B: ";
		cin >> b;

		if (func->type == LOG) {
			if (a < 0.0)
				a = 0.0;

			if (b < 0)
				b = 0;
		}

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
		for (long i = 0; i < (func->n); i++)
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
	SDL_Renderer* render = nullptr;
	float w = 1000, h = 700;
	double A = -10, B = 10, * extremums = nullptr, maxValue = 0, temp = 0;
	int extremumsCount = 0;

	cout << "Построение графика;" << endl;

	if (func == nullptr || func->koefs == nullptr)
		return 0;

	if (func->n < 1 || !isTypeFunc(func->type))
		return 0;

	do {
		cout << "Введите A: ";
		cin >> A;
		cout << "Введите B: ";
		cin >> B;

		if (A > B)
			cout << "Error! A > B;\n";
	} while (!isCorrectInput() || A > B);


	// rootsCount + A,B
	if ((extremums = (double*)malloc(sizeof(double) * (func->n + 2))) == nullptr)
		return 0;

	if (!funcExtremums(func, A, B, extremums, extremumsCount))
	{
		return 0;
	}

	if((render = createWindow(w, h)) == nullptr)
		return 0;

	SDL_Color backGroundColor = { 0, 0, 0, 0 }, color = { 0xff, 0xff, 0xff, 0xff };
	clearRender(render, backGroundColor);
	float cX = 0, cY = 0, ap = w / h, aX = 0.f, aY = 0.f, pX = 1.f, pY = 1.f, pLength = 0.f;

	SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);

	aX = w * 0.5, aY = h * 0.5;
	cX = w * 0.5, cY = h * 0.5;

	pX = w / (abs(A - B)); // x2 > x1

	// find max Value
	for (int i = 0; i < extremumsCount; i++)
	{
		if (funcValue(func, extremums[i], &temp))
			if (abs(temp) > maxValue)
				maxValue = abs(temp);
	}

	if(funcValue(func, A, &temp))
		if (abs(temp) > maxValue)
			maxValue = abs(temp);

	if (funcValue(func, B, &temp))
		if (abs(temp) > maxValue)
			maxValue = abs(temp);

	if (func->type == SIN || func->type == COS) {
		maxValue = func->koefs[0] * 1.0 + func->koefs[3];
		temp = func->koefs[0] * (-1.0) + func->koefs[3];

		if (abs(maxValue) < abs(temp))
			maxValue = temp;
	}

	if (func->type == POLYNOMIAL)
		temp = func->koefs[0];
	else if(func->n == 3)
		temp = func->koefs[2];
	else if(func->n == 4)
		temp = func->koefs[3];

	if (func->type == SIN || func->type == COS) 
	{
		if (abs(maxValue) < 2.0)
			pY = cY / 2.0;
		else
			pY = cY / (abs(maxValue));
	}
		
	else 
	{
		pY = cY / (abs(maxValue + temp));

		if (pY < 1e-3)
			pY = 1e-3;
	}

	aY += temp * pY;

	// ox
	SDL_RenderDrawLineF(render, 0.f, aY, w, aY);
	// oy
	SDL_RenderDrawLineF(render, aX, 0.f, aX, h);

	pLength = w * 0.002f;

	// Axis Points  - OX
	for (float i = 0.f; i < w; i += pX)
	{
		SDL_RenderDrawLineF(render, i, aY + pLength, i, aY - pLength);
	}

	// Axis Points  - OY
	for (float i = 0.f; i < h; i += pY)
	{
		SDL_RenderDrawLineF(render, aX - pLength, i, aX + pLength, i);
	}

	double x = 0, y = 0, step = abs(B - A) / 1e+4;

	for (double i = A; i < B; i += step)
	{
		if (funcValue(func, i, &y))
		{
			y = cY + pY * (-1.f) * y;
			x = cX + i * pX;

			SDL_RenderDrawPointF(render, x, y);
		}

		/*if (funcValue(func, i, &y) && funcValue(func, i + 0.5, &y2)) 
		{
			 y = cY + pY * (-1.f) * y;
			 x = cX + i * pX;

			 y2 = cY + pY * (-1.f) * y2;
			 x2 = cX + (i + 1.f) * pX;

			 SDL_RenderDrawLineF(render, x, y, x2, y2);
		}*/
	}

	SDL_RenderPresent(render);
	SDL_Delay(4000);
	
	free(extremums);
	clean(render);

	return 0;
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
		int n = func->n - 1;
		polynomRealRoots(n, func->koefs, roots, rootsCount);
		if (rootsCount == 0)
			return 0;
		else 
			return 2;
	}
	break;
	case POWER:
	{
		if (a == 0.0)
		{
			if (b > 0.0 && c == 0.0)
			{
				root = 0.0;
			} else
				return 0;
		}
		else if (c == 0.0) 
		{
			if (b > 0.0)
				root = 0.0;
			else
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
			
			if ((b - float((int)b) < minExp) && int(b) % 2 == 0)
			{
				roots[0] = root;
				roots[1] = -root;
				rootsCount = 2;
				return 2;
			}		
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

int funcExtremums(const func_t* func, double& A, double& B, double* extremums, int& extremumsCount)
{
	double * roots = nullptr, * nkoefs = nullptr, y1 = 0, y2 = 0, yA = 0, yB = 0;
	int rootsCount = 0, res = 0, a = 0, b = 1, c = 2, d = 3;
	func_t t_func;

	extremumsCount = 0;

	if (!copyFunc(&t_func, func) || extremums == nullptr)
		return 0;

	if (func->n < 1 || !isTypeFunc(func->type) || A > B)
		return 0;

	// hasnt extremums
	if (t_func.type == LOG || t_func.type == EXPONENTIAL)
	{
		return 1;
	}

	// polynomial: n - 1 + A, B
	// others: n + A,B
	if ((roots = (double*)malloc(sizeof(double) * (t_func.n + 2))) == nullptr)
		return 0;

	if (t_func.type == POLYNOMIAL)
	{
		for (int i = 1; i < t_func.n; i++)
		{
			t_func.koefs[i - 1] = t_func.koefs[i] * double(i);
		}

		t_func.n--;
		res = funcRoots(&t_func, roots, rootsCount);
	}
	else
	{
		switch (t_func.type)
		{
		case POWER:
			t_func.koefs[a] = t_func.koefs[a] * t_func.koefs[b];
			t_func.koefs[b] = t_func.koefs[b] - 1.0;
			t_func.koefs[c] = 0;

			res = funcRoots(&t_func, roots, rootsCount);

			break;
		case SIN:
			t_func.koefs[a] = t_func.koefs[a] * t_func.koefs[b];
			t_func.koefs[d] = 0;
			t_func.type = COS;

			res = funcRoots(&t_func, roots, rootsCount);
			break;
		case COS:
			t_func.koefs[a] = -1.0 * t_func.koefs[a] * t_func.koefs[b];
			t_func.koefs[d] = 0;
			t_func.type = SIN;

			res = funcRoots(&t_func, roots, rootsCount);
			break;
		default:
			deleteFunc(&t_func);
			return 0;
			break;
		}
	}

	if (res == -1)
	{
		free(roots);
		deleteFunc(&t_func);
		return 0;
	} else if (res == 0 || res == -1)// if R || 0; 
	{
		// check -inf < A < B
		if (funcValue(&t_func, A - minExp, &y1) &&
			funcValue(&t_func, B, &y2))
		{
			if (y1 * y2 < 0.0)
			{
				extremums[extremumsCount] = A;
				extremumsCount++;
			}
		}

		// check A < B < +inf
		if (funcValue(&t_func, A, &y1) &&
			funcValue(&t_func, B + minExp, &y2))
		{
			if (y1 * y2 < 0.0)
			{
				extremums[extremumsCount] = B;
				extremumsCount++;
			}
		}
	}
	else // if rootsCount > 0
	{
		// check -inf < A < A + minexp
		if (funcValue(&t_func, A - minExp, &y1) &&
			funcValue(&t_func, A + minExp, &y2))
		{
			if (y1 * y2 < 0.0)
			{
				extremums[extremumsCount] = A;
				extremumsCount++;
			}
		}

		// check B - exp < B < B + exp
		if (funcValue(&t_func, B - minExp, &y1) &&
			funcValue(&t_func, B + minExp, &y2))
		{
			if (y1 * y2 < 0.0)
			{
				extremums[extremumsCount] = B;
				extremumsCount++;
			}
		}

		for (long i = 0; i < rootsCount; i++)
		{
			if (funcValue(&t_func, roots[i] - minExp, &y1) &&
				funcValue(&t_func, roots[i] + minExp, &y2))
			{
				if (y1 * y2 < 0.0)
				{
					extremums[extremumsCount] = roots[i];
					extremumsCount++;
				}
			}
		}
	}

	free(roots);

	//deleteFunc(&t_func); //	isnt dynamic memory
	free(t_func.koefs);

	return 1;
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
		
	if (func->type != POLYNOMIAL) {
		a = func->koefs[0];
		b = func->koefs[1];
		c = func->koefs[2];

		if (func->n == 4)
			d = func->koefs[3];
	}

	if (func->type == POLYNOMIAL) 
	{
		for (long i = 0; i < (func->n); i++)
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
			cout << a << " * x^" << b << " + " << c << " = 0\nКорни: ";
			break;
		case EXPONENTIAL: 
			cout << a << " * " << b << "^(" << c << " * x) + " << d  << " = 0\nКорни: ";
			break;
		case LOG: 
			cout << a << " * ln(" << b << " * x) + " << c  << " = 0\nКорни: ";
			break;
		case SIN:
			cout << a << " * sin(" << b << " * x + " << c << ") + " << d << " = 0\nКорни: ";
			break;
		case COS:
			cout << a << " * cos(" << b << " * x + " << c << ") + " << d << " = 0\nКорни: ";
			break;
		default:
			break;
		}

		if (res == 0)
			cout << "Корней нет;" << endl;
		else if (res == 1)
			cout << "[" << A << ", " << B << "]" << endl;
		else 
		{
			for (long i = 0; i < rootsCount; i++)
			{
				if(roots[i] <= B && roots[i] >= A)
					cout << roots[i] << " ";
			}

			if (func->type == SIN || func->type == COS)
				cout << " +- " << 2.0 / func->koefs[1] << "Pi";

			cout << endl;
		}	
	}

	cout << endl;

	free(roots);
	return 1;
}

// extremums cant be nullptr
int searchExtremum(const func_t* func)
{
	double A = 0, B = 0, * extremums = nullptr;
	int extremumsCounts = 0, res = 0;

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

	// rootsCount + A,B
	if ((extremums = (double*)malloc(sizeof(double) * (func->n + 2))) == nullptr)
		return 0;

	cout << "Экстремумы функции: ";
	
	if (!funcExtremums(func, A, B, extremums, extremumsCounts))
	{
		cout << "Error!\n";
	}
	else
	{
		for (int i = 0; i < extremumsCounts; i++)
		{
			cout << extremums[i] << " ";
		}

		if (func->type == SIN || func->type == COS)
			cout << " +- " << 2.0 / func->koefs[1] << "Pi";

		cout << endl;
	}

	cout << endl;
	free(extremums);
	return 1;
}

// return (type >= 0 && type <= 5);
int isTypeFunc(int type)
{
	return (type >= 0 && type <= 5);
}

// return 0 if y = nan || = inf
// return 1 if y
int funcValue(const func_t* func, double x, double* y)
{
	double a = 0, b = 0, c = 0, d = 0, f = 0;

	if (func == nullptr)
		return 0;

	if (func->koefs == nullptr || !isTypeFunc(func->type))
		return 0;

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
		f += func->koefs[0]; // a0
		for (int i = 1; i < func->n; i++)
		{
			f += func->koefs[i] * pow(x, double(i));
		}
	}
	break;
	case POWER:
	{
		f = a * pow(x, b) + c;
	}
	break;
	case EXPONENTIAL:
	{
		f = a * pow(b, c * x) + d;
		
	}
	break;
	case LOG:
	{
		f = a * log(b * x) + c;
	}
	break;
	case SIN:
	{
		f = a * sin(b * x + c) + d;
	}
	break;
	case COS:
	{
		f = a * cos(b * x + c) + d;
	}
	break;
	default: return 0;
	}

	if (std::isnan(f) || std::isinf(f))
		return 0;
	else
		*y = f;

	return 1;
}

// create new distination func
int copyFunc(func_t* dist, const func_t* src)
{
	if(dist == nullptr && src == nullptr)
		return 0;

	dist->n = src->n;
	dist->type = src->type;

	dist->koefs = (double*)malloc(dist->n * sizeof(double));
	if (dist->koefs == nullptr)
		return 0;

	memcpy(dist->koefs, src->koefs, dist->n * sizeof(double));

	return 1;
}
