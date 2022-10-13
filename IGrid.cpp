#include "IGrid.h"
board::board() {
    K = 60;
    N = 9;
    SRN = sqrt(N);
    matrix = new int* [N];
    for (int i = 0; i < N; i++)
    {
        matrix[i] = new int[N];
        memset(matrix[i], 0, N * sizeof(int));
    }
}
int board::randomGenerator(int num)
{
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution <int> uni(1, num);
    auto n = uni(rng);
    return n;
}
bool board::isSafe(int** matrix, int row, int col, int num) {
    for (int x = 0; x <= 8; x++)
        if (matrix[row][x] == num)
            return false;

    for (int x = 0; x <= 8; x++)
        if (matrix[x][col] == num)
            return false;

    int startRow = row - row % 3,
        startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (matrix[i + startRow][j +
                startCol] == num)
                return false;

    return true;
}

void board::fillDiagonal()
{
    for (int i = 0; i < N; i = i + SRN)
    {
        fillBox(i, i);
    }
}
void board::fillBox(int row, int col)
{
    int num;
    for (int i = 0; i < SRN; i++) {
        for (int j = 0; j < SRN; j++) {
            do {
                num = randomGenerator(N);
            } while (!isSafe(matrix, row, col, num));
            matrix[row + i][col + j] = num;
        }
    }
}
bool board::fillRemaining(int i, int j) {
    if (j >= N && i < N - 1) {
        i = i + 1;
        j = 0;
    }
    if (i >= N && j >= N) {
        return true;
    }
    if (i < SRN) {
        if (j < SRN) {
            j = SRN;
        }
    }
    else if (i < N - SRN) {
        if (j == (int)(i / SRN) * SRN) {
            j = j + SRN;
        }
    }
    else {
        if (j == N - SRN) {
            i = i + 1;
            j = 0;
            if (i >= N) {
                return true;
            }
        }
    }
    for (int num = 1; num <= N; num++) {
        if (isSafe(matrix, i, j, num)) {
            matrix[i][j] = num;
            if (fillRemaining(i, j + 1)) {
                return true;
            }
            matrix[i][j] = 0;
        }
    }
    return false;
}
void board::removeKDigits() {
    int count = K;
    while (count != 0) {
        int cellId = randomGenerator(N * N) - 1;

        int i = (cellId / N);
        int j = cellId % 10;
        if (j != 0) {
            j = j - 1;
        }
        if (matrix[i][j] != 0) {
            count--;
            matrix[i][j] = 0;
        }
    }
}
board::~board() {
    for (int i = 0; i < N; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void board::printResult() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << "\t" << matrix[i][j];
        cout << endl << endl;
    }
}
