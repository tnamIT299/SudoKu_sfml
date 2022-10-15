#include "IceBreaker.h"

bool IceBreaker::FindUnassignedLocation(int grid[MaxSize][MaxSize], int&, int&)
{
	int row, col;
	for (row = 0; row < MaxSize; row++)
		for (col = 0; col < MaxSize; col++)
			if (grid[row][col] == 0)
				return true;
	return false;
}

bool IceBreaker::isSafe(int grid[MaxSize][MaxSize], int row, int col, int value)
{
	auto curRow = row;
	auto curCol = col;
	Field1 gField = { row,col };
	auto check1 = UsedInRow(grid, row, value, curCol);
	auto check2 = UsedInCol(grid, col, value, curRow);
	auto check3 = UsedInBox(grid, row - row % 3, col - col % 3, value, gField) && grid[row][col] == 0;

	auto check = !check1 && !check2 && !check3;

	return check;
}

void IceBreaker::printGrid(int grid[MaxSize][MaxSize])
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

bool IceBreaker::UsedInRow(int grid[MaxSize][MaxSize], int row, int value, int currentCol)
{
	for (int col = 0; col < MaxSize; col++)
		if (grid[row][col] == value && currentCol != col)
			return true;
	return false;
}

bool IceBreaker::UsedInCol(int grid[MaxSize][MaxSize], int col, int value, int CurrentRow)
{
	for (int row = 0; row < MaxSize; row++)
		if (grid[row][col] == value && CurrentRow != row)
			return true;
	return false;
}

bool IceBreaker::UsedInBox(int grid[MaxSize][MaxSize], int boxStartRow, int boxStartCol, int value, Field1 gameField)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + boxStartRow][col + boxStartCol] == value && gameField.row != row && gameField.col != col)
				return true;
	return false;
}

