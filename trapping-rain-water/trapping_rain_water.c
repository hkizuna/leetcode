#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int
trap (int *heights, int size)
{
  int *left_heights = malloc(size * sizeof(int));
  int *right_heights = malloc(size * sizeof(int));
  left_heights[0] = right_heights[size-1] = 0;
  int water = 0;
  for (int i = 1; i < size; i++) {
    left_heights[i] = MAX(left_heights[i-1], heights[i-1]);
  }
  for (int i = size - 2; i >= 0; i--) {
    right_heights[i] = MAX(right_heights[i+1], heights[i+1]);
    int min = MIN(left_heights[i], right_heights[i]);
    if (min > heights[i]) {
      water += min - heights[i];
    }
  }
  return water;
}

int
main (int argc, char **argv)
{
  int heights[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  printf("%d\n", trap(heights, sizeof(heights)/sizeof(int)));
}
