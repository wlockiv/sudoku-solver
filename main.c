#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/puzzle.h"

char POSSIBLE = 0x1FF;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main()
{
    int **puzzle;
    Square ***sudoku;
    puzzle = createPuzzle();

    printPuzzle(puzzle);

    setUpPuzzle(puzzle);

    return 0;
}