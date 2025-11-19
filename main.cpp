#include <iostream>
#include <limits>
#include "ConsoleUtils.h"
#include "MagicSquare.h"

using namespace std;

int getValidInput(int min = 3) {
    string line; 
    int n;
    bool valid;
    do {
        cout << "Enter size (>= " << min << " and odd): ";
        getline(cin, line);
        valid = (line.find_first_not_of("0123456789") == string::npos);
        if (valid) {
            n = stoi(line);
            valid = (n >= min && n % 2 != 0);
        }
        if (!valid) cout << "Invalid input. Enter only a number >=3 \n";
    } while (!valid);
    return n;
}

int main() {
    int size = getValidInput(); 

    clearScreen(); 

    drawMagicSquare(size); 

    return 0;
}
