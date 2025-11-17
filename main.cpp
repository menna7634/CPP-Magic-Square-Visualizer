#include <iostream>
#include <limits>
#include "ConsoleUtils.h"
#include "MagicSquare.h"

using namespace std;

int getValidInput() {
    int n = 0;
    bool valid = false;

    while (!valid) {
        cout << "Enter the size of the magic square (>=3): ";
        if (cin >> n && n >= 3) {
            valid = true;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cout << "Invalid input. Please enter a number >= 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return n;
}

int main() {
    int size = getValidInput();
    clearScreen();

    MagicSquare magicSquare(size);
    magicSquare.draw();

    return 0;
}
