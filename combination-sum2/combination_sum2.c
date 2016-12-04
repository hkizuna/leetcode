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
combination (int *candidates, int size, int start, int target, int *one, int one_size, int **all, int **one_sizes, int *all_size)
{
  if (target == 0) {
    all[*all_size] = malloc(one_size * sizeof(int));
    for (int i = 0; i < one_size; i++) {
      all[*all_size][i] = one[i];
    }
    (*one_sizes)[*all_size] = one_size;
    (*all_size)++;
    return;
  }
  
  for (int i = start; i < size; i++) {
    if (i != start && candidates[i] == candidates[i-1]) {
      continue;
    }
    if (candidates[i] <= target) {
      one[one_size] = candidates[i];
      combination(candidates, size, i + 1, target - candidates[i], one, one_size + 1, all, one_sizes, all_size);
    }
  }
}

int **
combination_sum (int *candidates, int size, int target, int **one_sizes, int *all_size)
{
  if (size == 0) {
    return NULL;
  }
  qsort(candidates, size, sizeof(int), compare_ints);
  int n = 1 << (size - 1);
  int *one = malloc(target * sizeof(int));
  int **all = malloc((n | n - 1) * sizeof(int *));
  combination(candidates, size, 0, target, one, 0, all, one_sizes, all_size);
  free(one);
  return all;
}

int
main (int argc, char **argv)
{
  int nums[] = {30,34,25,24,29,38,36,42,45,44,31,28,26,37,23,20,47,40,49,46,39,43,33,41,27,32,35,48};
  int size = sizeof(nums)/sizeof(int);
  int all_size = 0;
  int n = 1 << (size - 1);
  int *one_sizes = malloc((n | n - 1) * sizeof(int));
  int **all = combination_sum(nums, size, 54, &one_sizes, &all_size);
  for (int i = 0; i < all_size; i++) {
    for (int j = 0; j < one_sizes[i]; j++) {
      printf("%d ", all[i][j]);
    }
    printf("\n");
  }
  free(all);
}
