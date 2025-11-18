#include "MagicSquare.h"
#include "ConsoleUtils.h"
#include <iostream>
using namespace std;

// رسم خلية واحدة
void drawCell(int row, int col, int number, int startX, int startY, int cellWidth, int cellHeight) {
    int x = startX + col * cellWidth;
    int y = startY + row * cellHeight;

    setColor(31 + (number % 6));

    goToXY(x, y);
    cout << "+----+";
    goToXY(x, y + 1);
    cout << "|";
    cout.width(4);
    cout << number;
    cout << "|";
    goToXY(x, y + 2);
    cout << "+----+";

    delay(200); 
    setColor(37); 
}

void drawMagicSquare(int n) {
    const int cellWidth = 6;
    const int cellHeight = 3;
    const int startX = 5;
    const int startY = 2;

    int row = 0;
    int col = n / 2;

    for (int k = 1; k <= n * n; k++) {
        drawCell(row, col, k, startX, startY, cellWidth, cellHeight);

        int prevRow = row;
        int prevCol = col;

        // Siamese method
        if (k % n != 0) {
            row--;
            col++;
            if (row < 0) row = n - 1;
            if (col >= n) col = 0;
        } else {
            row = prevRow + 1;
            col = prevCol;
            if (row >= n) row = 0;
        }
    }

    goToXY(0, startY + n * cellHeight + 2);
    cout << "Magic square of size " << n << "x" << n << " completed!\n";
}
