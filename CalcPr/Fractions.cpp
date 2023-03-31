#include "Fractions.h"
using namespace std;
void fractionsCalc()
{
	Fraction main1,main2,summa;
	unsigned char test;
	double vyv;
	int choose = -2;
	do
	{
		do {
			cout << "Выберите действие:\n1 - сложение дробей\n2 - вычитание дробей\n3 - умножение дробей\n4 - деление дробей\n5 - сравнение дробей\n6 - сокращение дроби\n7 - представление дроби в виде десятичной\n8 - выход в главное меню\n";
			cin >> choose;
		} while ((choose > 9) || (choose < 1));
		switch (choose)
		{
		case 1:// сложение 
		{
			cout << "Введите элементы первой дроби: " << endl;
			main1 = createFraction();
			cout << "Введите элементы второй дроби: " << endl;
			main2 = createFraction();
			main1 = reductinFraction(main1); main2 = reductinFraction(main2);
			summa = addFraction(main1, main2);
			outputFraction(summa);
		}break;
		case 2:// вычитание
		{
			cout << "Введите элементы первой дроби: " << endl;
			main1 = createFraction();
			cout << "Введите элементы второй дроби: " << endl;
			main2 = createFraction();
			main1 = reductinFraction(main1); main2 = reductinFraction(main2);
			summa = subFraction(main1, main2);
			outputFraction(summa);
		}break;
		case 3: // умножение
		{
			cout << "Введите элементы первой дроби: " << endl;
			main1 = createFraction();
			cout << "Введите элементы второй дроби: " << endl;
			main2 = createFraction();
			main1 = reductinFraction(main1); main2 = reductinFraction(main2);
			summa = mulFraction(main1, main2);
			outputFraction(summa);
		}break;
		case 4://деление
		{
			cout << "Введите элементы первой дроби: " << endl;
			main1 = createFraction();
			cout << "Введите элементы второй дроби: " << endl;
			main2 = createFraction();
			main1 = reductinFraction(main1); main2 = reductinFraction(main2);
			summa = divFraction(main1, main2);
			outputFraction(summa);
		}break;
		case 5://сравнение
		{
			cout << "Введите элементы первой дроби: " << endl;
			main1 = createFraction();
			cout << "Введите элементы второй дроби: " << endl;
			main2 = createFraction();
			main1 = reductinFraction(main1); main2 = reductinFraction(main2);
			test = compareFraction(main1, main2);
			cout << "1 fraction " << test << " 2 fraction" << endl;

		}break;
		case 6:// сокращение
		{
			cout << "Введите элементы дроби: " << endl;
			main1 = createFraction();
			main1 = reductinFraction(main1);

			outputFraction(main1);
		}break;
		case 7:// представление в виде десятичной
		{
			cout << "Введите элементы дроби: " << endl;
			main1 = createFraction();
			main1 = reductinFraction(main1);
			vyv = decimalFraction(main1);
			cout << vyv << endl;
		}break;
		}
	} while (choose != 8);
}

int isSimple(int num)// функция проверяет является ли число простым(делится на себя и на 1)
{
	int k = 0;
	for (int i = 2; i < num;++i)
	{
		if (num % i == 0) k++;
		if (k !=0) return 0;
	}
	return 1;
}

void outputFraction(const Fraction& out)// выводит дробь
{
	cout << "   " << out.numerator << endl;
	cout << out.intPart << " --- " << endl;
	cout << "   " << out.denominator<<endl;
}
Fraction createFraction()// создает дробь
{
	Fraction drob1;
	do{
	cout << "Введите целую часть: "; cin >> drob1.intPart;
	} while (isdigit(drob1.intPart));

	do {
		cout << "Введите числитель: "; cin >> drob1.numerator;
	} while (drob1.numerator==0);

	do {
		cout << "Введите знаменатель: "; cin >> drob1.denominator;
	} while (drob1.denominator==0);
	return drob1;
}

Fraction addFraction(const Fraction& main1,const Fraction& main2)
{
	Fraction Summa;
	// логика: если знаменители равно, то складываем числители и ответ готов, если же нет, то приводим к общему знаменателю.
	Summa.intPart = main1.intPart + main2.intPart;
	if (main1.denominator == main2.denominator)
	{
		Summa.denominator = main1.denominator;
		Summa.numerator = main1.numerator + main2.numerator;
		reductinFraction(Summa);
		return Summa;
	}
	else
	{
		Summa.denominator = main1.denominator * main2.denominator;
		Summa.numerator = (main1.numerator * main2.denominator) + (main2.numerator * main1.denominator);
		reductinFraction(Summa);
		return Summa;
	}
	
}

Fraction subFraction(const Fraction& main1, const Fraction& main2)
{
	Fraction Sub;
	// логика: если знаменители равно, то складываем числители и ответ готов, если же нет, то приводим к общему знаменателю.
	Sub.intPart = main1.intPart + main2.intPart;
	if (main1.denominator == main2.denominator)
	{
		Sub.denominator = main1.denominator;
		Sub.numerator = main1.numerator - main2.numerator;
		reductinFraction(Sub);
		return Sub;
	}
	else
	{
		Sub.denominator = main1.denominator * main2.denominator;
		Sub.numerator = (main1.numerator * main2.denominator) - (main2.numerator * main1.denominator);
		reductinFraction(Sub);
		return Sub;
	}
}

Fraction mulFraction(const Fraction& main1, const Fraction& main2)
{
	//логика: умножаем числитель на числитель знам на знам и отправляем на сокращение
	Fraction mul;
	mul.intPart = 0;
	mul.numerator = main1.numerator * main2.numerator;
	mul.denominator = main1.denominator * main2.denominator;
	mul = reductinFraction(mul);
	return mul;

}
Fraction divFraction(const Fraction& main1, const Fraction& main2)
{
	// тоже самое что и умножние но переворачиваем дробь;
	Fraction div;
	div.intPart = 0;
	div.numerator = main1.numerator * main2.denominator;
	div.denominator = main1.denominator * main2.numerator;
	div = reductinFraction(div);
	return div;
}

unsigned char compareFraction(Fraction& main1, Fraction& main2)
{
	// подразумает собой, чтобы подается неправильная дробь без целой части
	//логика: если знаметели равны то сравниваем числители , если нет то приводим к общему и сравниваем
	if (main1.denominator == main2.denominator)
	{
		if (main1.numerator > main2.numerator) return '>';
		if (main1.numerator == main2.numerator) return'=';
		if (main1.numerator < main2.numerator) return'<';
	}
	else
	{
		main1.numerator *= main2.denominator;
		main2.numerator *= main1.denominator;
		int temp = main1.denominator;
		main1.denominator *= main2.denominator;
		main2.denominator *= temp;
		if (main1.numerator > main2.numerator) return '>';
		if (main1.numerator == main2.numerator) return'=';
		if (main1.numerator < main2.numerator) return'<';
	}
}

Fraction reductinFraction(Fraction main)
{// сокращение дробей
	// логика: вначале убираем целую часть, превращаем дробь в неправильную. Потом выбираем большее число из числителя и знаменателя. Из большего числа вычитаем по единице и проверяем делятся ли и числитель и знаменатель
	//Цикл идет до тех пор, пока или числитель или знаменатель не станут простыми числами.
	int i;
	if (main.intPart != 0)
	{
		
		main.numerator = main.denominator * main.intPart + main.numerator;
		main.intPart = 0;
	}

	if (main.denominator > main.numerator) 
		i = main.numerator;
	else 
		i = main.denominator;

	while((!isSimple(main.denominator)) || (!isSimple(main.numerator)))
	{
		
		if ((main.denominator % i == 0) && (main.numerator % i == 0))
		{
			main.denominator /= i;
			main.numerator /= i;
		}
		i--;
	}
	return main;
}

double decimalFraction(const Fraction& test)// дробь -> десятичная
{
	return (double(test.numerator )/ double(test.denominator));
}
