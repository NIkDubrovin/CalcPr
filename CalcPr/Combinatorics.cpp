#include "Combinatorics.h"

void combinatoricsCalc()
{
	int choice;
	cout << "1 - ���������� � �����������\n2 - ���������� ��� ����������\n3 - ������������ � �����������\n4 - ������������ ��� ����������\n5 - ��������� � �����������\n6 - ��������� ��� ����������\n";
	cout << "������� ����� �������� �������: ";
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

		cout << "\n1 - ���������� � �����������\n2 - ���������� ��� ����������\n3 - ������������ � �����������\n4 - ������������ ��� ����������\n5 - ��������� � �����������\n6 - ��������� ��� ����������\n";
		cout << "������� �� �� ���������� ����������?\n���� ��, �������� ����� �������� �������, ���� ���, �� ������� ����� ������ �����: ";
		cin >> choice;
		cout << endl;
	} while (choice >= 1 && choice <= 6);
}

long AwithRepeat()
{
	cout << "�� ������� ������� ���������� � ������������: " << endl;
	cout << "A = n^k" << endl;
	double n, k, n1, k1;
	cout << "������� ��� �����: n � k" << endl;
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
	cout << "�� ������� ������� ���������� ��� ����������: " << endl;
	cout << "    n!    " << endl;
	cout << "----------" << endl;
	cout << " (n - k)! " << endl;
	double n, k, A;
	cout << "������� ��� �����: n � k" << endl;;
	cin >> n >> k;
	while (n < 0)
	{
		cout << "n �� ����� ���� �������������. ������� ����� n: "; cin >> n;
	}
	while (k > n)
	{cout << "k �� ����� ���� ������ n. ������� k: "; cin >> k;}
	A = fact(n) / fact(n - k);
	cout << "            " << n << "! " << endl;
	cout << "A n k = ---------- = " << A << endl;
	cout << "         (" << n << " - " << k << ")!" << endl;
	return 0;
}

long PwithRepeat()
{
	cout << "�� ������� ������� ������������ � ������������: " << endl;
	cout << "   n!   " << endl;
	cout << "---------  "<< endl;
	cout << "n1!...ni!" << endl;
	double n, k, P, prom = 0;
	cout << "������� ��� �����: n � k" << endl;
	cin >> n >> k;
	while (n < 0 && k < 1)
	{
		cout << "������������ ����. ������� ��� �����: n � k" << endl; cin >> n >> k;
	}
	double* ni = (double*)malloc(sizeof(double) * (k + 1));
	for (int i = 1; i < k + 1; i++)
	{
		cout << "������� n" << i << ": "; cin >> ni[i];
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
	cout << "�� ������� ������� ������������ ��� ����������: " << endl;
	cout << "P = n!" << endl;
	int n;
	cout << "������� ����� n: ";
	cin >> n;
	while (n < 0)
	{
		cout << "n �� ����� ���� �������������. ������� ����� n: "; cin >> n;
	}
	cout <<endl << "P = " << n << "! = " << fact(n);
	return 0;
}

long CwithRepeat()
{
	cout << "�� ������� ������� ��������� � ������������: " << endl;
	cout << " (n + k - 1)!    " << endl;
	cout << "--------------" << endl;
	cout << " (k)! * (n-1)! " << endl;
	double n, k;
	double C;

	cout << "������� ��� �����: n � k" << endl;
	cin >> n >> k;
	while (k < 0 || n < 1)
	{
		cout << "���� �����������. ������� ��� �����: n � k" << endl; cin >> n >> k;
	}
	C = static_cast<double>(fact(n + k - 1)) / fact(k) * fact(n - 1);
	cout << "     (" << n << " + " << k << " - 1)!" << endl;
	cout << "C = -------------- = " << C << endl;
	cout << "     (" << k << ")! * (" << n << "-1)!" << endl;
	return 0;
}

long CwithoutRepeat()
{
	cout << "�� ������� ������� ��������� � ������������: " << endl;
	cout << "     (n)!    " << endl;
	cout << "--------------" << endl;
	cout << " (k)! * (n-k)! " << endl;
	double n, k;
	double C;
	cout << "������� ��� �����: n � k" << endl;
	cin >> n >> k;
	while (k > n)
	{cout << "k �� ����� ���� ������ n. ������� k: "; cin >> k;}
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
