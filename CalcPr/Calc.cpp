#include "Calc.h"
#include "Matrix.h"
#include "Functions.h"
#include "Combinatorics.h"
#include "Fractions.h"
#include "Statistics.h"
#include "Polinomials.h"
#include "sdl/include/SDL.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

int main(int argc, char* argv[])
{
    STATE State = MENU;
    int choose = 0;

    if (!init()) 
    {
        cout << "Ошибка при инициализации SDL" << endl;
    }
   
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
            clearScreen();
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

void clearScreen()
{
#if 0
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    HWND hWnd = GetConsoleWindow();
    RECT rect;
    PCONSOLE_FONT_INFO pFont = 0;
    int width = 0, heigth = 0;
    COORD coord;

    GetCurrentConsoleFont(consoleHandle, FALSE, pFont);

    if (GetWindowRect(hWnd, &rect) != 0 && pFont != nullptr)
    {
        if (pFont != nullptr)
        {
            width = pFont->dwFontSize.X;
            heigth = pFont->dwFontSize.Y;
        }

        for (int i = 0; i < rect.bottom; i += heigth)
        {
            coord.Y = i;
            for (int j = 0; j < rect.right; j += width)
            {
                coord.X = j;
                SetConsoleCursorPosition(consoleHandle, coord);
                cout << " ";
            }
        }
       
    }
#else
    system("cls");
#endif
}

int init() 
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    clearScreen();
    srand(time(nullptr));

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        return 0;
    }

    return 1;
}

SDL_Renderer* createWindow(float w, float h) {
    SDL_Window* window = nullptr;
    SDL_Renderer* render = nullptr;

    window = SDL_CreateWindow("CALC",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        (int32_t)w, (int32_t)h,
        /*SDL_WINDOW_BORDERLESS | SDL_WINDOW_FULLSCREEN |*/ SDL_WINDOW_SHOWN);

    if (window == nullptr) {
       
        return nullptr;
    }

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (render == nullptr) {
        return nullptr;
    }

    return render;
}

void clean(SDL_Renderer* render) {
    //Quit SDL subsystems
    if (render != nullptr) 
    {
        SDL_Window* window = SDL_RenderGetWindow(render);
        SDL_DestroyRenderer(render);
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
}

void clearRender(SDL_Renderer* render, SDL_Color color) {
    SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
    SDL_RenderClear(render);
}


