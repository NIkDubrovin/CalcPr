#include "Polinomials.h"

void polinomialCalc()
{
    setlocale(LC_ALL, "Russian");
    while (true)
    {
        cout << "1 - сложение \n2 - вычитание  \n3 - умножение \n4 - умножение на число \n5 - деление \n6 - производная \n7 - выход \nВведите номер операции: ";
        int operation;
        cin >> operation;
        system("cls");
        if (operation == 7)
        {
            break;
        }
        Polinomial p1, p2, result;
        switch (operation)
        {
        case 1:
           
            long degree1;
            do
            {
                cout << "Введите степень первого многочлена: ";
                cin >> degree1;
            } while (!isCorrectInput()||degree1<0);
            p1 = createPolynomial(degree1);
            for (int i = degree1; i >= 0; i--)
            {
                do
                {
                    cout << "Введите коэффициенты первого многочлена: ";
                    cin >> p1.koefs[i];
                } while (!isCorrectInput());
            }
            cout << "Первый многочлен: "; printPolynomial(p1);
            cout << "\n";
            
            long degree2;
            do
            {
                cout << "Введите степень второго многочлена: ";
                cin >> degree2;
            } while (!isCorrectInput() || degree2<0);
           
            p2 = createPolynomial(degree2);
            
            for (int i = degree2; i >= 0; i--)
            {
                do
                {
                    cout << "Введите коэффициенты второго многочлена: ";
                    cin >> p2.koefs[i];
                } while (!isCorrectInput());
            }

            cout << "Второй многочлен: ";
            printPolynomial(p2);
            cout << "\n";
            result = addPolynomials(p1, p2);
            cout << "Результат: ";
            printPolynomial(result);
            cout << endl;

            break;
        case 2:
            
            do
            {
                cout << "Введите степень первого многочлена: ";
                cin >> degree1;
            } while (!isCorrectInput() || degree1 < 0);
            p1 = createPolynomial(degree1);
            
            for (int i = degree1; i >= 0; i--)
            {
                do
                {
                    cout << "Введите коэффициенты первого многочлена: ";
                    cin >> p1.koefs[i];
                } while (!isCorrectInput());
            }
            cout << "Первый многочлен: "; printPolynomial(p1);
            cout << "\n";
            do
            {
                cout << "Введите степень второго многочлена: ";
                cin >> degree2;
            } while (!isCorrectInput() || degree2 < 0);
            p2 = createPolynomial(degree2);
           
            for (int i = degree2; i >= 0; i--)
            {
                do
                {
                    cout << "Введите коэффициенты второго многочлена: ";
                    cin >> p2.koefs[i];
                } while (!isCorrectInput());
            }
            cout << "Второй многочлен: ";
            printPolynomial(p2);
            cout << "\n";
            result = subPolynomials(p1, p2);
            cout << "Результат: ";
            printPolynomial(result);
            cout << endl;
            break;
        case 3:
            do
            {
                cout << "Введите степень первого многочлена: ";
                cin >> degree1;
            } while (!isCorrectInput() || degree1 < 0);
            p1 = createPolynomial(degree1);
            
            for (int i = degree1; i >= 0; i--)
            {
                do
                {
                    cout << "Введите коэффициенты первого многочлена: ";
                    cin >> p1.koefs[i];
                } while (!isCorrectInput());
            }
            cout << "Первый многочлен: "; printPolynomial(p1);
            cout << "\n";
            do
            {
                cout << "Введите степень второго многочлена: ";
                cin >> degree2;
            } while (!isCorrectInput() || degree2 < 0);
            p2 = createPolynomial(degree2);
            
            for (int i = degree2; i >= 0; i--)
            {
                do
                {
                    cout << "Введите коэффициенты второго многочлена: ";
                    cin >> p2.koefs[i];
                } while (!isCorrectInput());
            }
            cout << "Второй многочлен: "; printPolynomial(p2);
            cout << "\n";
            result = mulPolynomials(p1, p2);
            cout << "Результат: ";
            printPolynomial(result);
            cout << endl;
            break;
        case 4:
            do
            {
                cout << "Введите степень  многочлена: ";
                cin >> degree1;
            } while (!isCorrectInput() || degree1 < 0);
            p1 = createPolynomial(degree1);
            
            for (int i = degree1; i >= 0; i--)
            {
                do
                {
                    cout << "Введите коэффициенты многочлена: ";
                    cin >> p1.koefs[i];
                } while (!isCorrectInput());
            }
            cout << "Многочлен: "; printPolynomial(p1);
            cout << "\n";
            double scalar;
            cout << "Введите число на которое нужно умножить: ";
            cin >> scalar;
            result = mulScalarPolynomial(p1, scalar);
            cout << "Результат: ";
            printPolynomial(result);
            cout << endl;
            break;
        case 5:
            do
            {
                cout << "Введите степень первого многочлена: ";
                cin >> degree1;
            } while (!isCorrectInput() || degree1 < 0);
            p1 = createPolynomial(degree1);
           
            for (int i = degree1; i >= 0; i--)
            {
                do
                {
                    cout << "Введите коэффициенты первого многочлена: ";
                    cin >> p1.koefs[i];
                } while (!isCorrectInput());
            }
            cout << "Первый многочлен: "; printPolynomial(p1);
            cout << "\n";
            do
            {
                cout << "Введите степень второго многочлена: ";
                cin >> degree2;
            } while (!isCorrectInput() || degree2 < 0);
            p2 = createPolynomial(degree2);
            
            for (int i = degree2; i >= 0; i--)
            {
                do
                {
                    cout << "Введите коэффициенты второго многочлена: ";
                    cin >> p2.koefs[i];
                } while (!isCorrectInput());
            }
            cout << "Второй многочлен: "; printPolynomial(p2);
            cout << "\n";
            result = divPolynomials(p1, p2);
            break;
        case 6:
            do
            {
                cout << "Введите степень  многочлена: ";
                cin >> degree1;
            } while (!isCorrectInput() || degree1 < 0);
            p1 = createPolynomial(degree1);
            
            for (int i = degree1; i >= 0; i--)
            {
                do
                {
                    cout << "Введите коэффициенты многочлена: ";
                    cin >> p1.koefs[i];
                } while (!isCorrectInput());
            }
            cout << "Многочлен: "; printPolynomial(p1);
            cout << "\n";
            result = derivativePolynomial(p1);
            cout << "Результат: ";
            printPolynomial(result);
            cout << endl;
            break;
        default:
            cout << "Invalid operation" << endl;
            break;
        }

    }
}
void printPolynomial(Polinomial& p)
{
    for (int i = p.n; i >= 0; i--)
    {
        if (i != p.n && p.koefs[i] >= 0)
            cout << "+";
        cout << p.koefs[i] << "x^" << i << " ";
    }
}

Polinomial createPolynomial(long degree)
{
    Polinomial p;
    p.n = degree;
    p.koefs = new double[degree + 1];
    for (int i = 0; i <= degree; i++)
    {
        p.koefs[i] = 0.0;
    }
    return p;
}


Polinomial addPolynomials(Polinomial& p1, Polinomial& p2)
{
    long max_degree = max(p1.n, p2.n);
    Polinomial result = createPolynomial(max_degree);
    for (int i = 0; i <= max_degree; i++)
    {
        if (i <= p1.n && i <= p2.n)
        {
            result.koefs[i] = p1.koefs[i] + p2.koefs[i];
        }
        else if (i <= p1.n)
        {
            result.koefs[i] = p1.koefs[i];
        }
        else if (i <= p2.n)
        {
            result.koefs[i] = p2.koefs[i];
        }
    }
    return result;
}

Polinomial subPolynomials(Polinomial& p1, Polinomial& p2)
{
    long max_degree = max(p1.n, p2.n);
    Polinomial result = createPolynomial(max_degree);
    for (int i = 0; i <= max_degree; i++)
    {
        if (i <= p1.n && i <= p2.n)
        {
            result.koefs[i] = p1.koefs[i] - p2.koefs[i];
        }
        else if (i <= p1.n)
        {
            result.koefs[i] = p1.koefs[i];
        }
        else if (i <= p2.n)
        {
            result.koefs[i] = -p2.koefs[i];
        }
    }
    return result;
}

Polinomial mulPolynomials(Polinomial& p1, Polinomial& p2)
{
    long max_degree = p1.n + p2.n;
    Polinomial result = createPolynomial(max_degree);
    for (int i = 0; i <= p1.n; i++)
    {
        for (int j = 0; j <= p2.n; j++)
        {
            result.koefs[i + j] += p1.koefs[i] * p2.koefs[j];
        }
    }
    return result;
}

Polinomial mulScalarPolynomial(Polinomial& p, double scalar)
{
    Polinomial result = createPolynomial(p.n);
    for (int i = 0; i <= p.n; i++)
    {
        result.koefs[i] = p.koefs[i] * scalar;
    }
    return result;
}

Polinomial divPolynomials(Polinomial& p1, Polinomial& p2)
{
    if (p2.n == 0 && p2.koefs[0] == 0)
    {
        cout << "Ошибка: Деление на 0 " << endl;
    }
    if (p1.n < p2.n)
    {
        cout << "Степени многочленов различны, деление невозможно! " << endl;
    }
    else
    {
        Polinomial result = createPolynomial(p1.n - p2.n);
        Polinomial remainder = p1;
        for (int i = result.n; i >= 0; i--)
        {
            double quotient = remainder.koefs[p2.n + i] / p2.koefs[p2.n];
            result.koefs[i] = quotient;
            for (int j = p2.n + i; j >= i; j--)
            {
                remainder.koefs[j] -= quotient * p2.koefs[j - i];
            }
        }
        cout << "\nРезультат: " << endl;

        cout << "(";
        printPolynomial(result);
        cout << ")";
        cout << "+(";
        printPolynomial(remainder); cout << ")";
        cout << "/(";
        if (p2.n <= remainder.n)
        {
            printPolynomial(p2);
            cout << ")";
        }
        cout << endl;
        return result;
    }
}

Polinomial derivativePolynomial(Polinomial& p)
{
    if (p.n == 0)
    {
        return createPolynomial(0);
    }
    Polinomial result = createPolynomial(p.n - 1);
    for (int i = 1; i <= p.n; i++)
    {
        result.koefs[i - 1] = i * p.koefs[i];
    }
    return result;
}