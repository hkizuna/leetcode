#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int **
init_table (int size)
{
  int **table = malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    table[i] = malloc(9 * sizeof(int));
    for (int j = 0; j < 9; j++) {
      table[i][j] = 0;
    }
  }
  return table;
}

bool
is_valid_sudoku (char **board, int rsize, int csize)
{
  int **row_table = init_table(rsize);
  int **col_table = init_table(csize);
  int **blo_table = init_table(9);

  for (int i = 0; i < rsize; i++) {
    for (int j = 0; j < csize; j++) {
      if (board[i][j] != '.') {
        int n = board[i][j] - '0';
        row_table[i][n] += 1;
        col_table[j][n] += 1;
        int m = i/3 + j/3*3;
        blo_table[m][n] += 1;
        if (row_table[i][n] > 1 || col_table[j][n] > 1 || blo_table[m][n] > 1) {
          return false;
        } 
      }
    }
  }
  return true;
}

int
main (int argc, char **argv)
{
  char *board[] = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
  printf("%d\n", is_valid_sudoku(board, 9, 9));
}
