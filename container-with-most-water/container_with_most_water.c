#include <stdio.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int
max_area (int *heights, int size)
{
  int left = 0, right = size-1;
  int max = 0;
  while(left < right) {
    max = MAX(max, (right-left)*MIN(heights[left], heights[right]));
    if (heights[left] < heights[right]) {
      left++;
    }
    else if (heights[left] > heights[right]){
      right--;
    }
    else {
      left++;
      right--;
    } 
  }
  return max;
}

int
main (int argc, char **argv)
{
  int heights[] = {1, 3, 5, 2, 6};
  printf("%d\n", max_area(heights, sizeof(heights)/sizeof(int)));
}
