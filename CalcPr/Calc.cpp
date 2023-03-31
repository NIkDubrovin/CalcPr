#include "Calc.h"
#include "Matrix.h"
#include "Functions.h"
#include "Combinatorics.h"
#include "Fractions.h"
#include "Statistics.h"
#include "Polinomials.h"
//#include "sdl/include/SDL.h"

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
            cout.setf(ios_base::fixed);
            functionsCalc();
            cout.unsetf(ios_base::fixed);
            break;
        case STATISTICS:
            statisticCalc();
            break;
        case POLYNOMIALS:
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

//void clearScreen()
//{
//    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
//    HWND hWnd = GetConsoleWindow();
//    RECT rect;
//    PCONSOLE_FONT_INFO pFont = 0;
//    int width = 0, heigth = 0;
//    COORD coord;
//
//    GetCurrentConsoleFont(consoleHandle, FALSE, pFont);
//
//    if (GetWindowRect(hWnd, &rect) != 0 && pFont != nullptr)
//    {
//        if (pFont != nullptr)
//        {
//            width = pFont->dwFontSize.X;
//            heigth = pFont->dwFontSize.Y;
//        }
//
//        for (int i = 0; i < rect.bottom; i += heigth)
//        {
//            coord.Y = i;
//            for (int j = 0; j < rect.right; j += width)
//            {
//                coord.X = j;
//                SetConsoleCursorPosition(consoleHandle, coord);
//            }
//        }
//       
//    }
//}

void init() 
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    srand(time(nullptr));
}

