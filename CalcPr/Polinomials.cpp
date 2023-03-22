#include "Polinomials.h"

void polynomialCalc()
{
    setlocale(LC_ALL, "Russian");
    while (true)
    {
        cout << "¬ведите номер операции \n(1 - сложение, 2 - вычитание , 3 - умножение , 4 - умножение на число, 5- деление , 6 - производна€ ,7-выход): ";
        int operation;
        cin >> operation;
        if (operation == 7)
        {
            break;
        }
        Polinomial p1, p2, result;
        switch (operation)
        {
        case 1:
            cout << "¬ведите степень первого многочлена: ";
            long degree1;
            cin >> degree1;
            p1 = createPolynomial(degree1);
            cout << "¬ведите коэффициенты первого многочлена: ";
            for (int i = degree1; i >= 0; i--)
            {
                cin >> p1.koefs[i];
            }
            cout << "ѕервый многочлен: "; printPolynomial(p1);

            cout << "¬ведите степень второго многочлена: ";
            long degree2;
            cin >> degree2;
            p2 = createPolynomial(degree2);
            cout << "¬ведите коэффициенты второго многочлена: ";
            for (int i = degree2; i >= 0; i--)
            {
                cin >> p2.koefs[i];
            }

            cout << "¬торой многочлен: ";
            printPolynomial(p2);

            result = addPolynomials(p1, p2);
            cout << "–езультат: ";
            printPolynomial(result);
            deletePolynomial(p1);
            deletePolynomial(p2);
            deletePolynomial(result);
            break;
        case 2:
            cout << "¬ведите первую степень многочлена: ";
            cin >> degree1;
            p1 = createPolynomial(degree1);
            cout << "¬ведите коэффициенты первого многочлена: ";
            for (int i = degree1; i >= 0; i--)
            {
                cin >> p1.koefs[i];
            }
            cout << "ѕервый многочлен: "; printPolynomial(p1);
            cout << "¬ведите степень второго многочлена: ";
            cin >> degree2;
            p2 = createPolynomial(degree2);
            cout << "¬ведите коэффициенты второго многочлена: ";
            for (int i = degree2; i >= 0; i--)
            {
                cin >> p2.koefs[i];
            }
            cout << "¬торой многочлен: ";
            printPolynomial(p2);
            result = subPolynomials(p1, p2);
            cout << "–езультат: ";
            printPolynomial(result);
            deletePolynomial(p1);
            deletePolynomial(p2);
            deletePolynomial(result);
            break;
        case 3:
            cout << "¬ведите степень первого многочлена: ";
            cin >> degree1;
            p1 = createPolynomial(degree1);
            cout << "¬ведите коэффициенты первого многочлена: ";
            for (int i = degree1; i >= 0; i--)
            {
                cin >> p1.koefs[i];
            }
            cout << "ѕервый многочлен: "; printPolynomial(p1);
            cout << "¬ведите первую степень многочлена: ";
            cin >> degree2;
            p2 = createPolynomial(degree2);
            cout << "¬ведите коэффициенты второго многочлена: ";
            for (int i = degree2; i >= 0; i--)
            {
                cin >> p2.koefs[i];
            }
            cout << "¬торой многочлен: "; printPolynomial(p2);
            result = mulPolynomials(p1, p2);
            cout << "–езультат: ";
            printPolynomial(result);
            deletePolynomial(p1);
            deletePolynomial(p2);
            deletePolynomial(result);
            break;
        case 4:
            cout << "¬ведите степень многочлена: ";
            cin >> degree1;
            p1 = createPolynomial(degree1);
            cout << "¬ведите коэффициенты многочлена: ";
            for (int i = degree1; i >= 0; i--)
            {
                cin >> p1.koefs[i];
            }
            cout << "ћногочлен: "; printPolynomial(p1);
            double scalar;
            cout << "¬ведите число на которое нужно умножить: ";
            cin >> scalar;
            result = mulScalarPolynomial(p1, scalar);
            cout << "–езультат: ";
            printPolynomial(result);
            deletePolynomial(p1);
            deletePolynomial(result);
            break;
        case 5:
            cout << "¬ведите первую степень многочлена: ";
            cin >> degree1;
            p1 = createPolynomial(degree1);
            cout << "¬ведите коэффициенты первого многочлена: ";
            for (int i = degree1; i >= 0; i--)
            {
                cin >> p1.koefs[i];
            }
            cout << "ѕервый многочлен: "; printPolynomial(p1);
            cout << "¬ведите степень второго многочлена: ";
            cin >> degree2;
            p2 = createPolynomial(degree2);
            cout << "¬ведите коэффициенты второго многочлена: ";
            for (int i = degree2; i >= 0; i--)
            {
                cin >> p2.koefs[i];
            }
            cout << "¬торой многочлен: "; printPolynomial(p2);
            result = divPolynomials(p1, p2);
            cout << "–езультат: ";
            printPolynomial(result);
            deletePolynomial(p1);
            deletePolynomial(p2);
            deletePolynomial(result);
            break;
        case 6:
            cout << "¬ведите степень многочлена: ";
            cin >> degree1;
            p1 = createPolynomial(degree1);
            cout << "¬ведите коэффициенты многочлена: ";
            for (int i = degree1; i >= 0; i--)
            {
                cin >> p1.koefs[i];
            }
            cout << "ћногочлен: "; printPolynomial(p1);
            result = derivativePolynomial(p1);
            cout << "–езультат: ";
            printPolynomial(result);
            deletePolynomial(p1);
            deletePolynomial(result);
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
    cout << endl;
}
void deletePolynomial(Polinomial& p)
{
    delete[] p.koefs;
    p.n = 0;
    p.koefs = nullptr;
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
        cout << "Error: Division by zero" << endl;
        return createPolynomial(0);
    }
    if (p1.n < p2.n) {
        return createPolynomial(0);
    }
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
    return result;
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