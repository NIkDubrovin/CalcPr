#include "Fractions.h"
using namespace std;
void fractionsCalc()
{
	Fraction main1,main2,summa;
	unsigned char test;
	double vyv;
	int choose = -2;
	//main2 = createFraction();
	//main1 = reductinFraction(main1); main2 = reductinFraction(main2);
	do{
	cout << "enter 1 for choose amount\nenter 2 for choose subtraction\nenter 3 for choose multiplication\nenter 4 for choose div\nenter 5 for choose comparison\nenter 6 for choose reduction\nenter 7 for choose converting fractions to decimal\n";
	cin >> choose;
	} while ((choose > 8) || (choose < 1));
	switch (choose)
	{
	case 1:
	{
		cout << "enter elements first fraction: " << endl;
		main1 = createFraction();
		cout << "enter elements second fraction: " << endl;
		main2 = createFraction();
		main1 = reductinFraction(main1); main2 = reductinFraction(main2);
		summa = addFraction(main1, main2);
		outputFraction(summa);
	}break;
	case 2:
	{
		cout << "enter elements first fraction: " << endl;
		main1 = createFraction();
		cout << "enter elements second fraction: " << endl;
		main2 = createFraction();
		main1 = reductinFraction(main1); main2 = reductinFraction(main2);
		summa = subFraction(main1, main2);
		outputFraction(summa);
	}break;
	case 3:
	{
		cout << "enter elements first fraction: " << endl;
		main1 = createFraction();
		cout << "enter elements second fraction: " << endl;
		main2 = createFraction();
		main1 = reductinFraction(main1); main2 = reductinFraction(main2);
		summa = mulFraction(main1, main2);
		outputFraction(summa);
	}break;
	case 4:
	{
		cout << "enter elements first fraction: " << endl;
		main1 = createFraction();
		cout << "enter elements second fraction: " << endl;
		main2 = createFraction();
		main1 = reductinFraction(main1); main2 = reductinFraction(main2);
		summa = divFraction(main1, main2);
		outputFraction(summa);
	}break;
	case 5:
	{
		cout << "enter elements first fraction: " << endl;
		main1 = createFraction();
		cout << "enter elements second fraction: " << endl;
		main2 = createFraction();
		main1 = reductinFraction(main1); main2 = reductinFraction(main2);
		test = compareFraction(main1, main2);
		cout << "1 fraction " << test << " 2 fraction"<<endl;
		
	}break;
	case 6:
	{
		cout << "enter elements fraction: " << endl;
		main1 = createFraction();
		main1 = reductinFraction(main1);
	
		outputFraction(main1);
	}break;
	case 7:
	{
		cout << "enter elements fraction: " << endl;
		main1 = createFraction();
		main1 = reductinFraction(main1);
		vyv = decimalFraction(main1);
		cout << vyv << endl;
	}break;
	}
}

int isSimple(int num)
{
	int k = 0;
	for (int i = 2; i < num;++i)
	{
		if (num % i == 0) k++;
		if (k !=0) return 0;
	}
	return 1;
}

void outputFraction(const Fraction& out)
{
	cout << "   " << out.numerator << endl;
	cout << out.intPart << " --- " << endl;
	cout << "   " << out.denominator<<endl;
}
Fraction createFraction()
{
	Fraction drob1;
	do{
	cout << "¬ведите целую часть: "; cin >> drob1.intPart;
	} while (isdigit(drob1.intPart));

	do {
		cout << "¬ведите числитель: "; cin >> drob1.numerator;
	} while (drob1.numerator==0);

	do {
		cout << "¬ведите знаменатель: "; cin >> drob1.denominator;
	} while (drob1.denominator==0);
	return drob1;
}

Fraction addFraction(const Fraction& main1,const Fraction& main2)
{
	Fraction Summa;
	
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
	Fraction mul;
	mul.intPart = 0;
	mul.numerator = main1.numerator * main2.numerator;
	mul.denominator = main1.denominator * main2.denominator;
	mul = reductinFraction(mul);
	return mul;

}
Fraction divFraction(const Fraction& main1, const Fraction& main2)
{
	Fraction div;
	div.intPart = 0;
	div.numerator = main1.numerator * main2.denominator;
	div.denominator = main1.denominator * main2.numerator;
	div = reductinFraction(div);
	return div;
}

unsigned char compareFraction(Fraction& main1, Fraction& main2)
{
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
{
	int i;
	if (main.intPart != 0)
	{
		
		main.numerator = main.denominator * main.intPart + main.numerator;
		main.intPart = 0;
	}
	if (main.denominator > main.numerator) i = main.numerator;
	else i = main.denominator;
	while((!isSimple(main.denominator)) && (!isSimple(main.numerator)))
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

double decimalFraction(const Fraction& test)
{
	return (double(test.numerator )/ double(test.denominator));
}
