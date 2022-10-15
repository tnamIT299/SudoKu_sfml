#pragma once


#include <vector>
#include <iostream>
#include "ISudokuMapGen.h"
struct Field4 {

	int row, col;
};

class SudokuMapExpert : public ISudokuMapGen
{

public:

	SudokuMapExpert();

};


