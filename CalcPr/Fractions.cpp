#include "Fractions.h"
using namespace std;
void fractionsCalc()
{
	Fraction main1,main2,summa;
	main1 = createFraction();
	main2 = createFraction();
	main1 = reductinFraction(main1); main2 = reductinFraction(main2);
	summa = addFraction(main1, main2);
	cout <<summa.intPart<<endl<< summa.numerator;
	cout << endl << summa.denominator << endl;

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

void outputFraction(const Fraction&)
{
}

Fraction createFraction()
{
	Fraction drob1;
	do{
	cout << "¬ведите целую часть: "; cin >> drob1.intPart;
	} while (isdigit(drob1.intPart));

	do {
		cout << "¬ведите числитель: "; cin >> drob1.numerator;
	} while (isdigit(drob1.numerator));

	do {
		cout << "¬ведите знаменатель: "; cin >> drob1.denominator;
	} while (isdigit(drob1.denominator));
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

Fraction subFraction(const Fraction&, const Fraction&)
{
	return { 0 };
}

Fraction mulFraction(const Fraction&, const Fraction&)
{
	return { 0 };
}

Fraction divFraction(const Fraction&, const Fraction&)
{
	return { 0 };
}

unsigned char compareFraction(const Fraction&, const Fraction&)
{
	return 0;
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

double decimalFraction(const Fraction&)
{
	return 0.0;
}
