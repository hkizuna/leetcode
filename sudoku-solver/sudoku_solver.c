#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool
is_valid (char **board, int row, int col)
{
  char val = board[row][col];
  if (val - '0' < 1 || val - '0' > 9) {
    return false;
  }
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == val && i != col) {
      return false;
    }
    if (board[i][col] == val && i != row) {
      return false;
    }
  }
  int r = row/3*3, c = col/3*3;
  for (int i = r; i < r + 3; i++) {
    for (int j = c; j < c + 3; j++) {
      if (board[i][j] == val && (i != row || j != col)) {
        return false;
      }
    }
  }
  return true;
}

bool
validate_sudoku (char **board, int row, int col)
{
  if (row == 9) {
    return true;
  }

  int next_row = 0, next_col = 0;
  if (col == 8) {
    next_row = row + 1;
    next_col = 0;
  }
  else {
    next_row = row;
    next_col = col + 1;
  }

  if (board[row][col] != '.') {
    if (!is_valid(board, row, col)) {
      return false;
    }
    else {
      return validate_sudoku(board, next_row, next_col);
    }
  }

  for (int i = 1; i <= 9; i++) {
    board[row][col] = '0' + i;
    if (is_valid(board, row, col) && validate_sudoku(board, next_row, next_col)) {
      return true;
    }
  }
  board[row][col] = '.';
  return false;
}

void
solve_sudoku (char **board, int rsize, int csize)
{
  bool valid = validate_sudoku(board, 0, 0);
}

int
main (int argc, char **argv)
{
}
