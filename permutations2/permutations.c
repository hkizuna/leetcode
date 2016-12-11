#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int
compare_ints (const void *a, const void *b)
{
  int arg1 = *(const int *)a;
  int arg2 = *(const int *)b;
  if (arg1 == arg2) {
    return 0;
  }
  return arg1 < arg2 ? -1 : 1;
}

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
    if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
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
  qsort(nums, size, sizeof(int), compare_ints);
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
  int nums[] = {3, 3, 0, 3};
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
