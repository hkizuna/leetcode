#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int
first_missing_positive (int *nums, int size)
{
  int i = 0;
  while (i < size) {
    if (nums[i] > 0 && nums[i] <= size && nums[i] != i + 1 && nums[i] != nums[nums[i]-1]) {
      int a = nums[i];
      nums[i] = nums[a-1];
      nums[a-1] = a;
    }
    else {
      i++;
    }
  }

  for (int j = 0; j < size; j++) {
    if (nums[j] != j + 1) {
      return j + 1;
    }
  }
  return size + 1;
}

int
main (int argc, char **argv)
{
  int nums[] = {3, 4, -1, 1};
  printf("%d\n", first_missing_positive(nums, sizeof(nums)/sizeof(int)));
}
