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
			findM();
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
	findMCalc(n, mean, values, probabilities);

	// ���������
	dispersion = 0;
	for (int i = 0; i < n; i++) {
		x = values[i];
		p = probabilities[i];
		sum = (x - mean) * (x - mean) * p;
		dispersion += sum;
	}
	cout << "��������� = " << dispersion << endl;
	free(values);
	free(probabilities);
}

void findM() 
{
	long cn;
	double M = 0;
	cout << "������� ���������� ��������: "; cin >> cn;
	while (cn < 0)
	{
		cout << "���������� �������� �� ����� ���� ����� ���� ��� ���� �������������. ������� ���������� ��������: "; cin >> cn;
	}
	double* values = (double*)malloc(sizeof(double) * cn);
	double* probabilities = (double*)malloc(sizeof(double) * cn);
	for (int i = 0; i < cn; i++)
	{
		cout << "������� �������� � ����������� ��� " << i + 1 << " ��������: "; cin >> values[i] >> probabilities[i];
	}
	findMCalc(cn, M, values, probabilities);
	cout << "�������������� ��������: " << M << endl;
	free(values);
	free(probabilities);
}
void findMCalc(long& cn, double& M, double * values, double * probabilities)
{
	double x, p;
	for (int i = 0; i < cn; i++)
	{
		x = values[i];
		p = probabilities[i];
		M += p * x;
	}
}
