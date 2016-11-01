#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int *
two_sum (int *nums, int size, int target)
{
  int *ret = malloc(2 * sizeof(int));
  int *sorted = malloc(size * sizeof(int));
  memcpy(sorted, nums, size * sizeof(int));
  qsort(sorted, size, sizeof(int), compare_ints);
  for(int i = 0, j = size - 1;;) {
    if (sorted[i] + sorted[j] < target) {
      i++;
    }
    else if (sorted[i] + sorted[j] > target) {
      j--;
    }
    else {
      int a = 0;
      while(nums[a] != sorted[i]) {
        a++;
      }
      int b = size-1;
      while(nums[b] != sorted[j]) {
        b--;
      }
      if (a < b) {
        ret[0] = a;
        ret[1] = b;
      }
      else {
        ret[0] = b;
        ret[1] = a;
      }
      return ret;
    }
  }
}

int
main (int argc, char **argv)
{
  int nums[] = {2, 7, 9, 3, 10, 4, 6, 5};
  int *found = two_sum(nums, sizeof(nums)/sizeof(int), 9);
  printf("[%d, %d]\n", found[0], found[1]);
}
