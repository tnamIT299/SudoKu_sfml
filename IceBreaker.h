#pragma once

#include <vector>
#include<iostream>
#include "BasePageClass.h"

struct Field1{

	int row, col;
};

class IceBreaker 
{

public:
	

	static constexpr int MaxSize = 9;

	int gameMap[MaxSize][MaxSize] = {

	/*{7,8,0,4,0,0,1,2,0},
	{6,0,0,0,7,5,0,0,9},
	{0,0,0,6,0,1,0,7,8},
	{0,0,7,0,4,0,2,6,0},
	{0,0,1,0,5,0,9,3,0},
	{9,0,4,0,6,0,0,0,5},
	{0,7,0,3,0,0,0,1,2},
	{1,2,0,0,0,7,4,0,0},
	{0,4,9,2,0,6,0,0,7}*/

	};

	/*IceBreaker(sf::RenderWindow* window, bool ice) : BasePageClass(window)
	{
		this->_pageID = "Register";
		this->NavTOPage = GamePages::None;
		this->regis = regis;
		this->setUp();

	}*/


	//bool Solve(int grid[MaxSize][MaxSize]);
	bool FindUnassignedLocation(int grid[MaxSize][MaxSize], int&, int&);
	bool isSafe(int grid[MaxSize][MaxSize], int, int, int);
	void printGrid(int grid[MaxSize][MaxSize]);

private:

	bool UsedInRow(int grid[MaxSize][MaxSize], int row, int value, int currentCol);
	bool UsedInCol(int grid[MaxSize][MaxSize], int col, int value, int CurrentRow);
	bool UsedInBox(int grid[MaxSize][MaxSize], int, int, int, Field1 gameField);

};


