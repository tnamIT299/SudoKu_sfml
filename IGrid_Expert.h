#pragma once
#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
#include <random>
#include <time.h>
#include <vector>
using namespace std;
class board_Expert
{
protected:
    int** matrix;
    int N; // size of matrix
    int SRN;//sqrt of N
    int K; // num of remove cell

public:
    board_Expert();
    ~board_Expert();
    int randomGenerator(int num);
    virtual void fillValues() = 0;
    bool isSafe(int** matrix, int row, int col, int num);
    bool fillRemaining(int i, int j);
    void fillDiagonal();
    void fillBox(int row, int col);
    void removeKDigits();
    void printResult();
};

