#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX(a, b) (((a)>(b))?(a):(b))

int
jump (int *nums, int size)
{
  int max = 0, jumps = 0, i = 0;
  while (max < size - 1) {
    int max0 = max;
    while (i <= max0) {
      max = MAX(max, i + nums[i]);
      i++;
    }
    if (max == max0) {
      return -1;
    }
    jumps++;
  }
  return jumps;
}

int
main (int argc, char **argv)
{
  int nums[] = {2, 3, 1, 1, 4};
  printf("%d\n", jump(nums, sizeof(nums)/sizeof(int)));
}
