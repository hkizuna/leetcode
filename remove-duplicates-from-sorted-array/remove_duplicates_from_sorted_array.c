#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int
remove_duplicates (int *nums, int size)
{
  int count = 0;
  int next = 1;
  for (int i = 1; i < size; i++) {
    if (nums[i] == nums[i-1]) {
      count++;
    }
    else {
      nums[next++] = nums[i];
    }
  }
  return size - count;
}

int
main (int argc, char **argv)
{
  int nums[] = {1, 1, 2, 2, 2, 3, 4, 4, 5, 5, 5, 6};
  int n = remove_duplicates(nums, sizeof(nums)/sizeof(int));
  for(int i = 0; i < n; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}
