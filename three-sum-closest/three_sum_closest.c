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

int
is_closest (int old, int target, int sum)
{
  int current = old - target;
  int a = current > 0 ? current : -current;
  int next = target - sum;
  int b = next > 0 ? next : -next;
  return a > b ? sum : old;
}

int
three_sum_closest (int *nums, int size, int target)
{
  qsort(nums, size, sizeof(int), compare_ints);
  int closest = nums[0] + nums[1] + nums[2];
  for(int i = 0; i < size-2; i++) {
    int left = i+1, right = size-1;
    while(left < right) {
      int sum = nums[i] + nums[left] + nums[right];
      printf("sum: %d, target: %d, closest: %d\n", sum, target, closest);
      closest = is_closest(closest, target, sum);
      printf("closest: %d\n", closest);
      if (sum < target) {
        left++;
      }
      else if (sum > target) {
        right--;
      }
      else {
        return target;
      }
    }
  }
  return closest;
}

int
main (int argc, char **argv)
{
  int b[5] = {-3, -2, -5, 3, -4};
  printf("%d\n", three_sum_closest(b, sizeof(b)/sizeof(int), -1));
}
