#pragma once
#pragma once
#pragma once

#include <vector>
#include <iostream>
#include "ISudokuMapGen.h"

struct Field5 {

	int row, col;
};

class SudokuMapEvil : public ISudokuMapGen
{

public:
	SudokuMapEvil();
};


