#include "puzzle.h"

Square ***setUpPuzzle(int **puzzle)
{
    Square ***sudoku;

    sudoku = (Square ***)malloc(sizeof(Square **) * 9);

    for (int r = 0; r < 9; r++)
    {
        sudoku[r] = (Square **)malloc(sizeof(Square *) * 9);

        for (int c = 0; c < 9; c++)
        {
            sudoku[r][c] = (Square *)malloc(sizeof(Square) * 9);
            sudoku[r][c]->number = puzzle[r][c];

            sudoku[r][c]->row = r;
            sudoku[r][c]->col = c;

            if (sudoku[r][c]->number != 0)
                sudoku[r][c]
                    ->code = POSSIBLE;
            else
                sudoku[r][c]->code = 0x0;
        }
    }

    return sudoku;
}

int **createPuzzle()
{
    int **puzzle;
    int row, col;
    int array[9][9] = {
        {5, 0, 1, 6, 0, 7, 9, 0, 0},
        {0, 0, 9, 0, 0, 3, 2, 5, 0},
        {8, 2, 7, 0, 9, 0, 0, 0, 0},
        {9, 0, 2, 0, 5, 1, 3, 7, 0},
        {3, 0, 0, 9, 8, 0, 0, 0, 0},
        {0, 0, 5, 7, 0, 6, 0, 0, 0},
        {4, 0, 6, 0, 7, 5, 0, 3, 2},
        {0, 1, 0, 0, 0, 0, 7, 0, 5},
        {0, 0, 3, 0, 0, 0, 1, 9, 6},
    };

    puzzle = (int **)malloc(sizeof(int *) * 9);

    for (row = 0; row < 9; row++)
    {
        puzzle[row] = (int *)malloc(sizeof(int) * 9);

        for (col = 0; col < 9; col++)
        {
            puzzle[row][col] = array[col][row];
        }
    }

    return puzzle;
};

void printPuzzle(int **puzzle)
{
    printf("-------------------------------\n");
    for (int row = 0; row < 9; row++)
    {
        printf("|");
        for (int col = 0; col < 9; col++)
        {
            printf(" %d ", puzzle[row][col]);
            if ((col + 1) % 3 == 0)
                printf("|");
        }
        printf("\n");

        if ((row + 1) % 3 == 0)
            printf("-------------------------------\n");
    }
}