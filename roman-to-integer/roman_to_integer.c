#include <stdio.h>

int
starts_with (char *t, char *r)
{
  char *s = t, *p = r;
  int i = 0;
  while(*s != '\0' && *p != '\0') {
    if (*s++ != *p++) return 0;
    i++;
  }
  if (*s == '\0' && *p != '\0') return 0;
  return i;
}

int
roman_to_int (char *s)
{
  int num = 0;
  char *sy[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  int m[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  int j = 0;
  for(int i = 0; i < 13; i++) {
    while((j = starts_with(s, sy[i])) != 0) {
      num += m[i];
      s += j;
    }
  }
  return num;
}

int
main (int argc, char **argv)
{
  char *s = "MI";
  printf("%d\n", roman_to_int(s));

  char *t = "MCMXCIX";
  printf("%d\n", roman_to_int(t));
}
