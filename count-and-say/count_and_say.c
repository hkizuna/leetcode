#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// int
// count_and_say (int n)
// {
//   int num = 1, next, cur, f0, f1;
//   while (n > 1) {
//     next = 0, cur = 0, f0 = 0, f1 = 0;
//     while (num) {
//       if (num % 10 != cur) {
//         f0 = f0 == 0 ? 1 : f0 * 100;
//         f1 = f0 * 10;
//         cur = num % 10;
//         next += f1 + cur * f0;
//       }
//       else {
//         next += f1;
//       }
//       num /= 10;
//     }
//     num = next;
//     n--;
//   }
//   return num;
// }

char *
count_and_say (int n)
{
  char *num = malloc(2 * sizeof(char)), *next = NULL;
  num[0] = '1';
  num[1] = '\0';
  int size = 1;
  while (n > 1) {
    next = malloc((size * 2 + 1) * sizeof(char));
    char cur = '.';
    int count = 0, j = 0;
    for (int i = 0; i < size; i++) {
      if (cur != num[i]) {
        if (cur != '.') {
          next[j] = '0' + count;
          next[j+1] = cur;
          j += 2;
        }
        cur = num[i];
        count = 1;
      }
      else {
        count++;
      }
    }
    next[j] = '0' + count;
    next[j+1] = cur;
    next[j+2] = '\0';
    size = j + 2;
    free(num);
    num = next;
    n--;
  }
  return num;
}

int
main (int argc, char **argv)
{
  printf("%s\n", count_and_say(atoi(*++argv)));
}
