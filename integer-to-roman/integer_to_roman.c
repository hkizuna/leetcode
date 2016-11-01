#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
int_to_roman (int num)
{
  char *s= malloc(100);
  memset(s, 0, 100);
  *s = '\0';
  char *sy[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  int m[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  for(int i = 0; i < 13; i++) {
    if (num >= m[i]) {
      int count = num/m[i];
      num %= m[i];
      for(int j = 0; j < count; j++) {
        s = strcat(s, sy[i]);
      }
    }
  }
  return s;
}

int
main (int argc, char **argv)
{
  int n = 389;
  printf("%s\n", int_to_roman(n));
}
