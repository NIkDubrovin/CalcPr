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
	} while (choice >= 1 && choice <= 6);
}

long AwithRepeat()
{
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
	double n, k, A;
	cout << "������� ��� �����: n � k" << endl;;
	cin >> n >> k;
	A = fact(n) / fact(n - k);
	while (k > n)
	{cout << "k �� ����� ���� ������ n. ������� k: "; cin >> k;}
	cout << "A n k = " << A;
	//�������� �����
	return 0;
}

long PwithRepeat()
{
	double n, k, A;
	cout << "������� ��� �����: n � k" << endl;
	cin >> n >> k;
	//�������� �����
	return 0;
}

long PwithoutRepeat()
{
	int n;
	cout << "������� ����� n: ";
	cin >> n;
	cout << fact(n);
	//�������� �����
	return 0;
}

long CwithRepeat()
{
	double n, k;
	double C;

	cout << "������� ��� �����: n � k" << endl;
	cin >> n >> k;
	C = static_cast<double>(fact(n + k - 1)) / fact(k) * fact(n - 1);
	cout << "C = " << C; //�������� �����
	return 0;
}

long CwithoutRepeat()
{
	double n, k;
	double C;
	cout << "������� ��� �����: n � k" << endl;
	cin >> n >> k;
	while (k > n)
	{cout << "k �� ����� ���� ������ n. ������� k: "; cin >> k;}
	C = static_cast<double>(fact(n)) / (fact(k) * fact(n - k));
	cout << "C = " << C;
	//�������� �����
	return 0;
}

long fact(const long n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return(n * fact(n - 1));
}
