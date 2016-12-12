#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void
rotate (int **matrix, int row, int col)
{
  int start = 0, end = col - 1;
  while (start < end) {
    for (int i = start; i < end; i++) {
      int offset = i - start;
      int temp = matrix[start][i];
      matrix[start][i] = matrix[end-offset][start];
      matrix[end-offset][start] = matrix[end][end-offset];
      matrix[end][end-offset] = matrix[start+offset][end];
      matrix[start+offset][end] = temp;
    }
    start++;
    end--;
  }
}

int
main (int argc, char **argv)
{

}
