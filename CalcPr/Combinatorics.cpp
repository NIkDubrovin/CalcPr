#include "Combinatorics.h"

void combinatoricsCalc()
{
	int choice;
	cout << "1 - Размещение с повторением\n2 - Размещение без повторения\n3 - Перестановка с повторением\n4 - Перестановка без повторения\n5 - Сочетание с повторением\n6 - Сочетание без повторения\n";
	cout << "Введите номер желаемой функции: ";
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:
		{
			AwithRepeat();
			break;
		}
		case 2:
		{
			AwithoutRepeat();
			break;
		}
		case 3:
		{
			PwithRepeat();
			break;
		}
		case 4:
		{
			PwithoutRepeat();
			break;
		}
		case 5:
		{
			CwithRepeat();
			break;
		}
		case 6:
		{
			CwithoutRepeat();
			break;
		}
		default:
			break;
		}

		cout << "\n1 - Размещение с повторением\n2 - Размещение без повторения\n3 - Перестановка с повторением\n4 - Перестановка без повторения\n5 - Сочетание с повторением\n6 - Сочетание без повторения\n";
		cout << "Желаете ли вы продолжить вычисления?\nЕсли да, выберите номер желаемой функции, если нет, то введите любую другую цифру: ";
		cin >> choice;
	} while (choice >= 1 && choice <= 6);
}

long AwithRepeat()
{
	double n, k, n1, k1;
	cout << "Введите два числа: n и k" << endl;
	cin >> n >> k;
	n1 = n; k1 = k;
	if (k == 0)
		n = 1;
	if (k == 1)
		n;
	if (k != 0)
	{
		while (k != 1)
		{
			n *= n1;
			k--;
		}
	}
	cout << "_\nA n k = " << n1 << "^" << k1 << " = " << n << endl;
	return 0;
}

long AwithoutRepeat()
{
	double n, k, A;
	cout << "Введите два числа: n и k" << endl;;
	cin >> n >> k;
	A = fact(n) / fact(n - k);
	while (k > n)
	{cout << "k не может быть больше n. Введите k: "; cin >> k;}
	cout << "A n k = " << A;
	//Доделать вывод
	return 0;
}

long PwithRepeat()
{
	double n, k, A;
	cout << "Введите два числа: n и k" << endl;
	cin >> n >> k;
	//Доделать вывод
	return 0;
}

long PwithoutRepeat()
{
	int n;
	cout << "Введите число n: ";
	cin >> n;
	cout << fact(n);
	//Доделать вывод
	return 0;
}

long CwithRepeat()
{
	double n, k;
	double C;

	cout << "Введите два числа: n и k" << endl;
	cin >> n >> k;
	C = static_cast<double>(fact(n + k - 1)) / fact(k) * fact(n - 1);
	cout << "C = " << C; //Доделать вывод
	return 0;
}

long CwithoutRepeat()
{
	double n, k;
	double C;
	cout << "Введите два числа: n и k" << endl;
	cin >> n >> k;
	while (k > n)
	{cout << "k не может быть больше n. Введите k: "; cin >> k;}
	C = static_cast<double>(fact(n)) / (fact(k) * fact(n - k));
	cout << "C = " << C;
	//Доделать вывод
	return 0;
}

long fact(const long n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return(n * fact(n - 1));
}
