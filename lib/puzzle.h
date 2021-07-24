#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern char POSSIBLE;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef struct Box
{
    struct Box *next;
} Box;

typedef struct Square
{
    int number;
    char code;
    Box *box;
    int row;
    int col;
} Square;

int **createPuzzle();
void printPuzzle();
Square ***setUpPuzzle();

#endif