#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int
search (int *nums, int size, int target)
{
  int l = 0, r = size - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (nums[m] == target) {
      return m;
    }
    if (nums[m] >= nums[l]) {
      if (nums[l] <= target && target < nums[m]) {
        r = m - 1;
      }
      else {
        l = m + 1;
      }
    }
    else {
      if (nums[m] < target && target <= nums[r]) {
        l = m + 1;
      }
      else {
        r = m - 1;
      }
    }
  }
  return -1;
}

int
main (int argc, char **argv)
{
  int nums[] = {4, 5, 6, 7, 0, 1, 2, 3};
  printf("%d\n", search(nums, sizeof(nums)/sizeof(int), 2));
  printf("%d\n", search(nums, sizeof(nums)/sizeof(int), 4));
  printf("%d\n", search(nums, sizeof(nums)/sizeof(int), 10));
}
