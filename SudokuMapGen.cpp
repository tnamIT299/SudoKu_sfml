#pragma once
#include"SudokuMapGen.h"
SudokuMapGen::SudokuMapGen() {
	K = 30;
	fillValues();
	for (int i = 0; i < MaxSize; i++)
	{
		for (int j = 0; j < MaxSize; j++)
		{
			gameMap[i][j]=matrix[i][j];
		}
	}
}