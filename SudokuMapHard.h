#pragma once
#pragma once

#include <vector>
#include <iostream>
#include "ISudokuMapGen.h"

struct Field3 {

	int row, col;
};

class SudokuMapHard : public ISudokuMapGen
{

public:
	SudokuMapHard();
};


