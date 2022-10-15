#pragma once

#include <vector>
#include <iostream>
#include "IGrid.h"
#include "IGrid_Medium.h"
//#include "MediumMap.h"
struct Field2 {

	int row, col;
};

class SudokuMapMedium : public board_Medium
{

public:

	static constexpr int MaxSize = 9;

	int gameMap[MaxSize][MaxSize];

	SudokuMapMedium();

	bool Solve(int grid[MaxSize][MaxSize]);
	bool FindUnassignedLocation(int grid[MaxSize][MaxSize], int&, int&);
	bool isSafe(int grid[MaxSize][MaxSize], int, int, int);
	void printGrid(int grid[MaxSize][MaxSize]);
	void fillValues();
private:

	bool UsedInRow(int grid[MaxSize][MaxSize], int row, int value, int currentCol);
	bool UsedInCol(int grid[MaxSize][MaxSize], int col, int value, int CurrentRow);
	bool UsedInBox(int grid[MaxSize][MaxSize], int, int, int, Field2 gameField);

};


