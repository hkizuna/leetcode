#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void
_permute (int *nums, int *used, int size, int *one, int n, int **all, int *rsize)
{
  if (n == size) {
    all[*rsize] = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
      all[*rsize][i] = one[i];
    }
    (*rsize)++;
    return;
  }
  for (int i = 0; i < size; i++) {
    if (used[i]) {
      continue;
    }
    used[i] = 1;
    one[n] = nums[i];
    _permute(nums, used, size, one, n + 1, all, rsize);
    used[i] = 0;
  }
}

int **
permute (int *nums, int size, int *rsize)
{
  int **all = malloc(10000 * sizeof(int *));
  int *one = malloc(size * sizeof(int));
  int *used = malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    used[i] = 0;
  }
  _permute(nums, used, size, one, 0, all, rsize);
  return all;
}

int
main (int argc, char **argv)
{
  int nums[] = {1, 2, 3};
  int size = sizeof(nums)/sizeof(int);
  int rsize = 0;
  int **all = permute(nums, size, &rsize);
  for (int i = 0; i < rsize; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", all[i][j]);
    }
    printf("\n");
  }
}
