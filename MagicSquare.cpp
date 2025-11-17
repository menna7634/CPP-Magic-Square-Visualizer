#include "MagicSquare.h"
#include "ConsoleUtils.h"
#include <iostream>
using namespace std;

MagicSquare::MagicSquare(int n)
    : size(n), cellWidth(6), cellHeight(3), startX(5), startY(2) {}

void MagicSquare::drawCell(int row, int col, int number) {
    int x = startX + col * cellWidth;
    int y = startY + row * cellHeight;

        int colorCode = 31 + (number % 6); 
        setColor(colorCode);

    goToXY(x, y);
    cout << "+----+";
    goToXY(x, y + 1);
    cout << "|";
    cout.width(4);
    cout << number;
    cout << "|";
    goToXY(x, y + 2);
    cout << "+----+";

    delay(800);
    setColor(37);
}

void MagicSquare::draw() {
    int row = 0;
    int col = size / 2;

    for (int k = 1; k <= size * size; k++) {
        drawCell(row, col, k);

        int prevRow = row;
        int prevCol = col;

        // Siamese method
        if (k % size != 0) {
            row--;
            col++;
            if (row < 0) row = size - 1;
            if (col >= size) col = 0;
        } else {
            row = prevRow + 1;
            col = prevCol;
            if (row >= size) row = 0;
        }
    }

    goToXY(0, startY + size * cellHeight + 2);
    cout << "Magic square of size " << size << "x" << size << " completed!\n";
}
