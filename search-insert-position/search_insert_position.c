#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int
search_insert (int *nums, int size, int target)
{
  if (size == 0) {
    return 0;
  }
  int l = 0, r = size - 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (nums[m] == target) {
      return m;
    }
    if (nums[m] > target) {
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  if (nums[l] == target) {
    return l;
  }
  else {
    return nums[l] > target ? l : l + 1;
  }
}

int
main (int argc, char **argv)
{
  int nums[] = {1, 3};
  printf("%d\n", search_insert(nums, sizeof(nums)/sizeof(int), 5));
  printf("%d\n", search_insert(nums, sizeof(nums)/sizeof(int), 2));
  printf("%d\n", search_insert(nums, sizeof(nums)/sizeof(int), 7));
}
