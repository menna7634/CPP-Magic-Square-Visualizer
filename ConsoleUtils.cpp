#include "ConsoleUtils.h"
#include <iostream>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void goToXY(int x, int y) {
#ifdef _WIN32
    COORD c{(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
#else
    printf("\033[%d;%dH", y + 1, x + 1);
    fflush(stdout);
#endif
}

void delay(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void setColor(int color) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#else
    cout << "\033[" << color << "m";
#endif
}
