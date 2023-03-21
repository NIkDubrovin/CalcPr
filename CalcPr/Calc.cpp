#include "Calc.h"
#include "Matrix.h"
#include "Functions.h"
#include "Combinatorics.h"
#include "Fractions.h"
#include "Statistics.h"
#include "Polinomials.h"


int main()
{
    STATE State = MENU;
    int choose = 0;

    init();
   
    while (State != EXIT) {
        cout << "Выберите тип :\n1: Матричный\n2: Дроби\n3: Комбинаторика\n4: Функции\n5: Статистика\n6: Многочлены\n7: Выход\n";
        cin >> choose;

        switch (choose)
        {
        case MATRIX:
            matrixCalc();
            break;
        case FRACTIONS:
            fractionsCalc();
            break;
        case COMBINATORICS:
            combinatoricsCalc();
            break;
        case FUNCTIONS:
            functionsCalc();
            break;
        case STATISTICS:
            statisticCalc();
            break;
        case POLINOMIALS:
            polinomialCalc();
            break;
        case EXIT:
            return 0;
            break;
        default:
            break;
        }
    }
}

unsigned char isCorrectInput() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\nERROR! Некорректный ввод.\n\n";
        return 0;
    }

    std::cin.ignore(1000, '\n');
    if (cin.gcount() > 1) {
        std::cout << "\nERROR! Некорректный ввод.\n\n";
        return 0;
    }

    return 1;
}

void init() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    srand(time(nullptr));
}

