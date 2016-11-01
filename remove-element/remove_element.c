#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int
remove_element (int *nums, int size, int val)
{
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (nums[i] != val) {
      nums[count++] = nums[i];
    }
  }
  return count;
}

int
main (int argc, char **argv)
{
  int a[] = {1, 2, 3, 4, 4, 5, 6, 7};
  int n = remove_element(a, sizeof(a)/sizeof(int), 4);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
