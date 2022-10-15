#pragma once

#include <vector>
#include <iostream>
#include "ISudokuMapGen.h"
struct Field2 {

	int row, col;
};

class SudokuMapMedium : public ISudokuMapGen
{

public:
	SudokuMapMedium();
};


