#include "puzzle.h"
#include "string.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void printPuzzle(int grid[9][9]) {
  printf("-------------------------------\n");
  for (int row = 0; row < 9; row++) {
    printf("|");
    for (int col = 0; col < 9; col++) {
      printf(" %d ", grid[row][col]);
      if ((col + 1) % 3 == 0)
        printf("|");
    }
    printf("\n");

    if ((row + 1) % 3 == 0)
      printf("-------------------------------\n");
  }
}

bool isSafe(int grid[9][9], int row, int col, int candidate) {
  // Check rows first
  for (int _c = 0; _c < 9; _c++)
    if (grid[row][_c] == candidate) {
      return false;
    }

  // Check columns
  for (int _r = 0; _r < 9; _r++)
    if (grid[_r][col] == candidate) {
      return false;
    }

  // Check current box
  int rowMin = row - row % 3;
  int colMin = col - col % 3;

  for (int _r = 0; _r < 3; _r++)
    for (int _c = 0; _c < 3; _c++)
      if (grid[_r + rowMin][_c + colMin] == candidate) {
        return false;
      }

  return true;
}

bool solveSudoku(int grid[9][9], int row, int col) {
  // If we're at the end of the puzzle, break
  if (row == 8 && col == 9)
    return true;

  // If we're at the end of the current row, start at next row
  if (col == 9) {
    row++;
    col = 0;
  }

  // If this number is already set, go to the next col
  if (grid[row][col] > 0) {
    return solveSudoku(grid, row, col + 1);
  }

  // Try each candidate
  for (int candidate = 1; candidate <= 9; candidate++) {
    // If it's not already in the row/col/box
    if (isSafe(grid, row, col, candidate) == true) {
      // Set the row's solution number
      grid[row][col] = candidate;
      // Go to the next column
      if (solveSudoku(grid, row, col + 1) == true)
        return true;
    }
    // Set the col back to zero because it failed if we got here
    grid[row][col] = 0;
  }
  return false;
}