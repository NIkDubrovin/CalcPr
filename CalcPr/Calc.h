#pragma once
#include <iostream>
#include <math.h>
#include <Windows.h>
#include "sdl/include/SDL.h"

using namespace std;

typedef enum STATE{
    MENU,
    MATRIX,
    FRACTIONS,
    COMBINATORICS,
    FUNCTIONS,
    STATISTICS,
    POLYNOMIALS,
    EXIT
} STATE;

int init();
SDL_Renderer* createWindow(float w, float h);
void clean(SDL_Renderer* render);
void clearRender(SDL_Renderer* render, SDL_Color color);
unsigned char isCorrectInput();
void clearScreen();