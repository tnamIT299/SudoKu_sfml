#pragma once
#include "IceMapGen.h"

void IceMapGen::fillValues() {

    board::fillDiagonal();

    board::fillRemaining(0, board::SRN);

    board::removeKDigits();
    srand(time(NULL));
    int i = 0, x, y;
    while (i <= 20)
    {
        x = rand() % 9;
        y = rand() % 9;
        if (board::matrix[x][y] == 0) {
            board::matrix[x][y] = rand() % 2 - 2;
            i++;
        }
    }
}
IceMapGen::IceMapGen() {
    board::K = 40;
    fillValues();
    for (int i = 0; i < MaxSize; i++)
    {
        for (int j = 0; j < MaxSize; j++)
        {
            gameMap[i][j] = board::matrix[i][j];
        }
    }
}