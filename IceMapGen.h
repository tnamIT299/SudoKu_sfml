#pragma once
#include "IGrid.h"
#include "ISudokuMapGen.h"
class IceMapGen :public ISudokuMapGen
{
public:
    void fillValues();
    static constexpr int MaxSize = 9;
    void iceHandle(int grid[MaxSize][MaxSize], int row, int col);
    int gameMap[MaxSize][MaxSize];
    IceMapGen();
};


