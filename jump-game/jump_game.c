#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
bool
can_jump (int *nums, int size)
{
  int max = 0;
  for (int i = 0; i < size; i++) {
    if (i > max || max >= size - 1) {
      break;
    }
    max = MAX(max, i + nums[i]);
  }
  return max >= size - 1 ? true : false;
}

int
main (int argc, char **argv)
{
  int nums[] = {2,3,1,1,4};
  printf("%d\n", can_jump(nums, sizeof(nums)/sizeof(int)));
}
