#pragma once
#include "IGrid.h"
#include "ISudokuMapGen.h"
class IceMapGen :public ISudokuMapGen
{
public:
    void fillValues();
    static constexpr int MaxSize = 9;

    int gameMap[MaxSize][MaxSize];
    IceMapGen();
};


