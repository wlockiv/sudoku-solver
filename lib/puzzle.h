#ifndef PUZZLE_H
#define PUZZLE_H
#include <stdbool.h>

void printPuzzle(int grid[9][9]);
bool solveSudoku(int grid[9][9], int row, int col);

#endif
