#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void
search (int *nums, int l, int r, int target, int *range)
{
  if (l > r) {
    return;
  }
  int m = (l + r) / 2;
  if (nums[m] == target) {
    range[0] = range[0] < m ? range[0] : m;
    range[1] = range[1] > m ? range[1] : m;
  }
  search(nums, l, m - 1, target, range);
  search(nums, m + 1, r, target, range);
}

int *
search_range (int *nums, int size, int target, int *rsize)
{
  int *range = malloc(2*sizeof(int));
  range[0] = size;
  range[1] = -1;
  search(nums, 0, size - 1, target, range);
  range[0] = range[0] == size && range[1] == -1 ? -1 : range[0];
  *rsize = 2;
  return range;
}

int
main (int argc, char **argv)
{
  int nums[] = {5, 7, 7, 8, 8, 10, 10};
  int size = 0;
  int *range = search_range(nums, sizeof(nums)/sizeof(int), 5, &size);
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d ", range[i]);
  }
  printf("]\n");
}
