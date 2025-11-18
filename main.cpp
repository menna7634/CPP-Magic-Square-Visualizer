#include <iostream>
#include <limits>
#include "ConsoleUtils.h"
#include "MagicSquare.h"

using namespace std;

int getValidInput(int min = 3) {
    int n;
    bool valid;

    do {
        cout << "Enter the size of the magic square (>= " << min << "): ";
        if (cin >> n && n >= min) {
            valid = true; 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cout << "Invalid input. Please enter a number >= " << min << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valid = false;
        }
    } while (!valid);

    return n;
}

int main() {
    int size = getValidInput(); 

    clearScreen(); 

    drawMagicSquare(size); 

    return 0;
}
