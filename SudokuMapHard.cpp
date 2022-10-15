#pragma once
#include"SudokuMapHard.h"

SudokuMapHard::SudokuMapHard() {
	K = 50;
	fillValues();
	for (int i = 0; i < MaxSize; i++)
	{
		for (int j = 0; j < MaxSize; j++)
		{
			gameMap[i][j] = matrix[i][j];
		}
	}
}