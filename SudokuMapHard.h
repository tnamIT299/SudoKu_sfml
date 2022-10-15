#pragma once
#pragma once

#include <vector>
#include <iostream>
#include "IGrid.h"
#include "IGrid_Hard.h"

struct Field3 {

	int row, col;
};

class SudokuMapHard : public board_Hard
{

public:

	static constexpr int MaxSize = 9;

	int gameMap[MaxSize][MaxSize];

	SudokuMapHard();

	bool Solve(int grid[MaxSize][MaxSize]);
	bool FindUnassignedLocation(int grid[MaxSize][MaxSize], int&, int&);
	bool isSafe(int grid[MaxSize][MaxSize], int, int, int);
	void printGrid(int grid[MaxSize][MaxSize]);
	void fillValues();
private:

	bool UsedInRow(int grid[MaxSize][MaxSize], int row, int value, int currentCol);
	bool UsedInCol(int grid[MaxSize][MaxSize], int col, int value, int CurrentRow);
	bool UsedInBox(int grid[MaxSize][MaxSize], int, int, int, Field3 gameField);

};


