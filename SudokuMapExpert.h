#pragma once
#pragma once
#pragma once

#include <vector>
#include <iostream>
#include "IGrid.h"
#include "IGrid_Expert.h"

struct Field4 {

	int row, col;
};

class SudokuMapExpert : public board_Expert
{

public:

	static constexpr int MaxSize = 9;

	int gameMap[MaxSize][MaxSize];

	SudokuMapExpert();

	bool Solve(int grid[MaxSize][MaxSize]);
	bool FindUnassignedLocation(int grid[MaxSize][MaxSize], int&, int&);
	bool isSafe(int grid[MaxSize][MaxSize], int, int, int);
	void printGrid(int grid[MaxSize][MaxSize]);
	void fillValues();
private:

	bool UsedInRow(int grid[MaxSize][MaxSize], int row, int value, int currentCol);
	bool UsedInCol(int grid[MaxSize][MaxSize], int col, int value, int CurrentRow);
	bool UsedInBox(int grid[MaxSize][MaxSize], int, int, int, Field4 gameField);

};


