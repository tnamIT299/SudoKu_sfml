
#pragma once
#include"ISudokuMapGen.h"

bool ISudokuMapGen::Solve(int grid[MaxSize][MaxSize])
{
	int row, col;

	if (!FindUnassignedLocation(grid, row, col))
		return true;

	for (int value = 1; value <= MaxSize; value++)
	{

		if (isSafe(grid, row, col, value))
		{

			grid[row][col] = value;

			if (Solve(grid))
				return true;

			grid[row][col] = 0;
		}
	}
	return false;
}

bool ISudokuMapGen::FindUnassignedLocation(int grid[MaxSize][MaxSize], int& row, int& col)
{
	for (row = 0; row < MaxSize; row++)
		for (col = 0; col < MaxSize; col++)
			if (grid[row][col] == 0)
				return true;
	return false;
}

bool ISudokuMapGen::UsedInRow(int grid[MaxSize][MaxSize], int row, int value, int currentCol)
{

	for (int col = 0; col < MaxSize; col++)
		if (abs(grid[row][col]) == value && currentCol != col)
			return true;
	return false;
}

bool ISudokuMapGen::UsedInCol(int grid[MaxSize][MaxSize], int col, int value, int CurrentRow)
{
	for (int row = 0; row < MaxSize; row++)
		if (abs(grid[row][col]) == value && CurrentRow != row)
			return true;
	return false;
}

bool ISudokuMapGen::UsedInBox(int grid[MaxSize][MaxSize], int boxStartRow, int boxStartCol, int value, Field gameField)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (abs(grid[row + boxStartRow][col + boxStartCol]) == value && gameField.row != row && gameField.col != col)
				return true;
	return false;
}

bool ISudokuMapGen::isSafe(int grid[MaxSize][MaxSize], int row, int col, int value)
{
	auto curRow = row;
	auto curCol = col;
	auto value1 = abs(value);
	Field gField = { row,col };
	auto check1 = UsedInRow(grid, row, value1, curCol);
	auto check2 = UsedInCol(grid, col, value1, curRow);
	auto check3 = UsedInBox(grid, row - row % 3, col - col % 3, value1, gField) && grid[row][col] == 0;

	auto check = !check1 && !check2 && !check3;

	return check;

}

void ISudokuMapGen::printGrid(int grid[MaxSize][MaxSize]) // for debugging
{
	for (int row = 0; row < MaxSize; row++) {
		for (int col = 0; col < MaxSize; col++) {
			if (col == 3 || col == 6)
				std::cout << " | ";
			std::cout << grid[row][col] << " ";
		}
		if (row == 2 || row == 5) {
			std::cout << std::endl;
			for (int i = 0; i < MaxSize; i++)
				std::cout << "---";
		}
		std::cout << std::endl;
	}
}

void ISudokuMapGen::fillValues() {
	fillDiagonal();

	fillRemaining(0, SRN);

	removeKDigits();
}

ISudokuMapGen::ISudokuMapGen() {
}