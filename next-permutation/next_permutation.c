#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

void
swap (int *a, int *b)
{
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

// bool
// permutation (int *nums, int size)
// {
//   bool found = false;
//   for (int i = size - 1; i >= 1; i--) {
//     for (int j = i - 1; j >= 0; j--) {
//       if (nums[i] > nums[j]) {
//         swap(&nums[i], &nums[j]);
//         qsort(nums + j + 1, size - j - 1, sizeof(int), compare_ints);
//         found = true;
//         break;
//       } 
//     }
//     if (found) {
//       break;
//     }
//   }
//   return found;
// }
// 
// void
// next_permutation (int *nums, int size)
// {
//   if (size <= 1) {
//     return;
//   }
//   int i = 2;
//   while (i <= size && !permutation(nums + size - i, i)) {
//     i++;
//   }
//   if (i > size) {
//     int m = 0, n = size - 1;
//     while (m < n) {
//       swap(&nums[m], &nums[n]);
//       m++;
//       n--;
//     }
//   }
// }

void
next_permutation (int *nums, int size)
{
  if (size <= 1) {
    return;
  }
  int v = -1;
  for (int i = size - 1; i >= 1; i--) {
    if (nums[i-1] < nums[i]) {
      v = i - 1;
      break;
    }
  }
  if (v != -1) {
    for (int i = size - 1; i >= 1; i--) {
      if (nums[i] > nums[v]) {
        swap(&nums[i], &nums[v]);
        qsort(nums + v + 1, size - v - 1, sizeof(int), compare_ints);
        return;
      }
    }
  }
  int i = 0, j = size - 1;
  while (i < j) {
    swap(&nums[i], &nums[j]);
    i++;
    j--;
  }
}

int
main (int argc, char **argv)
{
  int nums[] = {4,2,0,2,3,2,0};
  int size = sizeof(nums)/sizeof(int);
  for (int i = 0; i < size; i++) {
    printf("%d", nums[i]);
  }
  printf("\n");
  next_permutation(nums, size);
  for (int i = 0; i < size; i++) {
    printf("%d", nums[i]);
  }
  printf("\n");
}
