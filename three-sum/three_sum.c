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

int **
three_sum (int *nums, int size, int *rsize)
{
  int **all = malloc(size*(size-1)*(size-2)/6*sizeof(int *));
  qsort(nums, size, sizeof(int), compare_ints);
  int curr = nums[0] + 1, count = 0;
  for(int i = 0; i < size - 2; i++) {
    if (curr != nums[i]) {
      curr = nums[i];
      int left = i + 1;
      int right = size - 1;
      while(left < right) {
        if (nums[left] + nums[right] < -curr) {
          left++;
        }
        else if (nums[left] + nums[right] > -curr) {
          right--;
        }
        else {
          all[count] = malloc(3*sizeof(int));
          all[count][0] = curr;
          all[count][1] = nums[left];
          all[count][2] = nums[right];
          count++;
          left++;
          right--;
          while(left < right && nums[left] == nums[left-1]) left++;
          while(right > left && nums[right] == nums[right+1]) right--;
        }
      }
    }
  }
  *rsize = count;
  return all;
}

int
main (int argc, char **argv)
{
  int nums[] = {-7,-5,5,-6,-2,1,7,3,-4,-2,-2,-4,-8,-1,8,8,-2,-7,3,2,-7,8,-3,-10,5,2,8,7,7};
  int rsize = 0;
  int **all = three_sum(nums, sizeof(nums)/sizeof(int), &rsize);
  for(int i = 0; i < rsize; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d\n", all[i][j]);
    }
  }
}
