#include "Combinatorics.h"

void combinatoricsCalc()
{
	int choice;
do{
	cout << "1 - Размещение с повторением\n2 - Размещение без повторения\n3 - Перестановка с повторением\n4 - Перестановка без повторения\n5 - Сочетание с повторением\n6 - Сочетание без повторения\n7 - Выход\n";
	cout << "Введите номер желаемой функции: ";
	cin >> choice;
	while (choice < 1 && choice > 7)
	{
		cout << "1 - Размещение с повторением\n2 - Размещение без повторения\n3 - Перестановка с повторением\n4 - Перестановка без повторения\n5 - Сочетание с повторением\n6 - Сочетание без повторения\n7 - Выход\n";
		cout << "Введите номер желаемой функции: ";
		cin >> choice;
	}
		switch (choice)
		{
		case 1:
		{
			AwithRepeat();
		}break;
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
		case 7: 
		{
			system("cls");
			break;
		}
		}

	} while (choice != 7);
}

long AwithRepeat()
{
	system("cls");
	cout << "Вы выбрали формулу размещения с повторениями: " << endl;
	cout << "A = n^k" << endl;
	double n, k, n1, k1;
	cout << "Введите число n: ";
	cin >> n;
	while (n < 0 || !isCorrectInput())
	{
		if (n < 0)
		{
			cout << "n не может быть меньше 0. Введите число n: "; cin >> n;
		}
		else
		{
			cout << "Введите число n: "; cin >> n;
		}
	}
	cout << "Введите число k: ";
	cin >> k;
	while (k < 0 || !isCorrectInput())
	{
		if (k < 0)
		{
			cout << "k не может быть меньше 0. Введите число k: "; cin >> k;
		}
		else
		{
			cout << "Введите число k: "; cin >> k;
		}
	}
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
	system("cls");
	cout << "Вы выбрали формулу размещения без повторений: " << endl;
	cout << "    n!    " << endl;
	cout << "----------" << endl;
	cout << " (n - k)! " << endl;
	double n, k, A;
	cout << "Введите число n: ";
	cin >> n;
	while (n < 0 || !isCorrectInput())
	{
		if (n < 0)
		{
			cout << "n не может быть отрицательным. Введите число n: "; cin >> n;
		}
		else
		{
			cout << "Введите число n : "; cin >> n;
		}
	}
	cout << "Введите число k: "; cin >> k;
	while (k > n || !isCorrectInput())
	{
		if (k > n)
		{
			cout << "k не может быть больше n. Введите k: "; cin >> k;
		}
		else
		{
			cout << "Введите k: "; cin >> k;
		}
	}

	A = fact(n) / fact(n - k);
	cout << "            " << n << "! " << endl;
	cout << "A n k = ---------- = " << A << endl;
	cout << "         (" << n << " - " << k << ")!" << endl;
	return 0;
}

long PwithRepeat()
{
	system("cls");
	cout << "Вы выбрали формулу перестановки с повторениями: " << endl;
	cout << "   n!   " << endl;
	cout << "---------  "<< endl;
	cout << "n1!...ni!" << endl;
	double n, k, P, prom = 0;
	cout << "Введите число n: ";
	cin >> n;
	while (n < 0 || !isCorrectInput())
	{
		if (n < 0)
		{
			cout << "n не может быть меньше 0. Введите число n: "; cin >> n;
		}
		else
		{
			cout << "Введите число n: "; cin >> n;
		}
	}
	cout << "Введите число k: ";
	cin >> k;
	while (k < 1 || !isCorrectInput())
	{
		if (k < 1)
		{
			cout << "k не может быть меньше 1. Введите число k: "; cin >> k;
		}
		else
		{
			cout << "Введите число k: "; cin >> k;
		}
	}
	double* ni = (double*)malloc(sizeof(double) * (k + 1));
	for (int i = 1; i < k + 1; i++)
	{
		cout << "Введите n" << i << ": "; cin >> ni[i];
		while (!isCorrectInput())
		{
			cout << "Введите n" << i << ": "; cin >> ni[i];
		}
	}
	for (int i = 1; i < k + 1; i++)
	{
		prom += fact(ni[i]);
	}
	P = fact(n) / prom;
	cout << "   " << n << "!   " << endl;
	cout << "--------- = " << P << endl;
	cout << "n1!...n" << k << "!" << endl;
	free(ni);
	return 0;
}

long PwithoutRepeat()
{
	system("cls");
	cout << "Вы выбрали формулу перестановки без повторений: " << endl;
	cout << "P = n!" << endl;
	int n;
	cout << "Введите число n: ";
	cin >> n;
	while (n < 0 || !isCorrectInput())
	{	
		if (n < 0)
		{
			cout << "n не может быть отрицательным. Введите число n: "; cin >> n;
		}
		else
		{
			cout << "Введите число n: "; cin >> n;
		}
	}
	cout << endl << "P = " << n << "! = " << fact(n) << endl;
	return 0;
}

long CwithRepeat()
{
	system("cls");
	cout << "Вы выбрали формулу сочетания с повторениями: " << endl;
	cout << " (n + k - 1)!    " << endl;
	cout << "--------------" << endl;
	cout << " (k)! * (n-1)! " << endl;
	double n, k;
	double C;

	cout << "Введите число n: ";
	cin >> n;
	while (n < 1 || !isCorrectInput())
	{
		if (n < 1)
		{
			cout << "n не может быть меньше 1. Введите число n : "; cin >> n;
		}
		else
		{
			cout << "Введите число n : "; cin >> n;
		}

	}
	cout << "Введите число k: ";
	cin >> k;
	while (k < 0 || !isCorrectInput())
	{
		if (k < 0)
		{
			cout << "k не может быть меньше 0. Введите число k : "; cin >> k;
		}
		else
		{
			cout << "Введите число k : "; cin >> k;
		}

	}
	C = static_cast<double>(fact(n + k - 1)) / fact(k) * fact(n - 1);
	cout << "     (" << n << " + " << k << " - 1)!" << endl;
	cout << "C = -------------- = " << C << endl;
	cout << "     (" << k << ")! * (" << n << "-1)!" << endl;
	return 0;
}

long CwithoutRepeat()
{
	system("cls");
	cout << "Вы выбрали формулу сочетания без повторений: " << endl;
	cout << "     (n)!    " << endl;
	cout << "--------------" << endl;
	cout << " (k)! * (n-k)! " << endl;
	double n, k;
	double C;
	cout << "Введите число n: ";
	cin >> n;
	while (n < 0 || !isCorrectInput())
	{
		if (n < 0)
		{
			cout << "n не может быть меньше 0. Введите n: "; cin >> n;
		}
		else
		{
			cout << "Введите n: "; cin >> n;
		}
	}
	cout << "Введите число k: ";
	cin >> k;
	while (k > n || !isCorrectInput())
	{
		if (k > n)
		{
			cout << "k не может быть больше n. Введите k: "; cin >> k;
		}
		else
		{
			cout << "Введите k: "; cin >> k;
		}
	}
	C = static_cast<double>(fact(n)) / (fact(k) * fact(n - k));
	cout << "         (" << n << ")!" << endl;
	cout << "C = -------------- = " << C << endl;
	cout << "     (" << k << ")! * (" << n << "-" << k << ")!" << endl;
	return 0;
}

long fact(const long n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return(n * fact(n - 1));
}
