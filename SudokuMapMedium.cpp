#pragma once
#include"SudokuMapMedium.h"

SudokuMapMedium::SudokuMapMedium() {
	K = 40;
	fillValues();
	for (int i = 0; i < MaxSize; i++)
	{
		for (int j = 0; j < MaxSize; j++)
		{
			gameMap[i][j] = matrix[i][j];
		}
	}
}