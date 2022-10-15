#pragma once
#include"SudokuMapExpert.h"

SudokuMapExpert::SudokuMapExpert() {
	K = 60;
	fillValues();

	for (int i = 0; i < MaxSize; i++)
	{
		for (int j = 0; j < MaxSize; j++)
		{
			gameMap[i][j] = matrix[i][j];
		}
	}
}