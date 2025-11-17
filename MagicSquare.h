#ifndef MAGIC_SQUARE_H
#define MAGIC_SQUARE_H

class MagicSquare {
private:
    int size;
    int cellWidth;
    int cellHeight;
    int startX;
    int startY;

    void drawCell(int row, int col, int number);
public:
    MagicSquare(int n);
    void draw();
};

#endif
