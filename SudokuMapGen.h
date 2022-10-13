#pragma once

#include <vector>
#include<iostream>
#include "IGrid.h"
struct Field {

	int row, col;
};

class SudokuMapGen:public board
{

public:

	static constexpr int MaxSize = 9;

	int gameMap[MaxSize][MaxSize];

	SudokuMapGen();


	bool Solve(int grid[MaxSize][MaxSize]);
	bool FindUnassignedLocation(int grid[MaxSize][MaxSize], int&, int&);
	bool isSafe(int grid[MaxSize][MaxSize], int, int, int);
	void printGrid(int grid[MaxSize][MaxSize]);
	void fillValues();
private:

	bool UsedInRow(int grid[MaxSize][MaxSize], int row, int value, int currentCol);
	bool UsedInCol(int grid[MaxSize][MaxSize], int col, int value, int CurrentRow);
	bool UsedInBox(int grid[MaxSize][MaxSize], int, int, int, Field gameField);

};


