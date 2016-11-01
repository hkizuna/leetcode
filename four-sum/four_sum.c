#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
two_sum (int *nums, int start, int end, int target, int *one, int size, int **all, int *rsize)
{
  while(start < end) {
    int sum = nums[start] + nums[end];
    if (sum == target) {
      *one++ = nums[start];
      *one = nums[end];
      all[*rsize] = malloc(size*sizeof(int));
      for(int i = 0; i < size; i++) {
        all[*rsize][i] = one[i-size+1];
      }
      (*rsize)++;
      one--;
      start++;
      end--;
      while(start < end && nums[start] == nums[start-1]) start++;
      while(end > start && nums[end] == nums[end+1]) end--;
    }
    else if (sum < target) {
      start++;
    }
    else {
      end--;
    }
  }
}

void
k_sum (int *nums, int start, int end, int target, int k, int *one, int size, int **all, int *rsize)
{
  if (k == 2) {
    two_sum(nums, start, end, target, one, size, all, rsize);
    return;
  }
  for(int i = start; i < end; i++) {
    if (i != start && nums[i] == nums[i-1]) continue;
    *one++ = nums[i];
    k_sum(nums, i + 1, end, target - nums[i], k - 1, one, size, all, rsize);
    one--;
  }
}

int **
four_sum (int *nums, int size, int target, int* rsize)
{
  int **all = malloc(size*(size-1)*(size-2)*(size-3)/24*sizeof(int *));
  int *one = malloc(size*sizeof(int));
  qsort(nums, size, sizeof(int), compare_ints);
  k_sum(nums, 0, size - 1, target, 4, one, 4, all, rsize);
  return all;
}

int
main (int argc, char **argv)
{
  int a[6] = {1, 0, -1, 0, -2, 2};
  int rsize = 0;
  int **all = four_sum(a, 6, 0, &rsize);
  for(int i = 0; i < rsize; i++) {
    printf("[ ");
    for(int j = 0; j < 4; j++) {
      printf("%d ", all[i][j]);
    }
    printf("]\n");
  }
}
