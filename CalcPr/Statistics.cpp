#include "Statistics.h"

using namespace std;

void statisticCalc()
{

	int choose = -2;
	do
	{
		do
		{
			cout << "�������� ��������:\n1 - ����������� m/n\n2 - ��������� ��� ����������� ������������� �������\n3 - ���. �������� ��� ����������� ������������� �������\n4 - ����� � ������� ����\n";
			cin >> choose;
		} while (choose != 1 && choose != 2 && choose != 3 && choose != 4);
		switch (choose)
		{
		case 1:
		{
			long n = -2, m = -2;
			do
			{
				cout << "������� ���������� ������������� �������: ";
				cin >> m;
			} while (m < 0);
			do
			{
				cout << "������� ���������� ���� �������: ";
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
	cout << "����������� ����� ������� = " << double(double(m) / double(n)) << endl;
	return 0.0;
}

void findDispersion()
{
	long n = -2;
	double mean = 0, dispersion, x, p, sum;
	do
	{
		cout << "������� ���������� �������� � ���������� ������������� : ";
		cin >> n;
	} while (n < 0);
	double* values = (double*)malloc(sizeof(double) * n); // �������� � �������������
	double* probabilities = (double*)malloc(sizeof(double) * n); // �����������
	for (int i = 0; i < n; i++)
	{
		cout << "������� �������� � ����������� ��� " << i + 1 << " - �� �������� : ";
		cin >> values[i];
		cin >> probabilities[i];
	}

	// �������������� ��������
	for (int i = 0; i < n; i++) {
		x = values[i];
		p = probabilities[i];
		mean += x * p;
	}

	// ���������
	dispersion = 0;
	for (int i = 0; i < n; i++) {
		x = values[i];
		p = probabilities[i];
		sum = (x - mean) * (x - mean) * p;
		dispersion += sum;
	}
	cout << "��������� = " << dispersion << endl;
}

double findM(Odd* odds, long size)
{
	return 0.0;
}
