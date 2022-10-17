#pragma once
#include "IceMapGen.h"

void IceMapGen::fillValues() {

    board::fillDiagonal();

    board::fillRemaining(0, board::SRN);

    board::removeKDigits();
    srand(time(NULL));
    int i = 0, x, y;
    while (i <= 8)
    {
        x = rand() % 9;
        y = rand() % 9;
        if (board::matrix[x][y] == 0) {
            board::matrix[x][y] = rand() % 2 + 10;
            i++;
        }
    }
}

void IceMapGen::iceHandle(int grid[MaxSize][MaxSize], int row, int col) {
    for (int x = 0; x < MaxSize; x++)
        if (grid[row][x] == 10)
            grid[row][x] = 0;
    for (int x = 0; x < MaxSize; x++)
        if (grid[x][col] == 10)
            grid[x][col] = 0;
    for (int x = 0; x < MaxSize; x++)
        if (grid[row][x] == 11)
            grid[row][x] = 10;
    for (int x = 0; x < MaxSize; x++)
        if (grid[x][col] == 11)
            grid[x][col] = 10;
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