#include <stdio.h>

int
atoi (char *s)
{
  int i = 0;
  while(s[i] == ' ') {
    i++;
  }
  if (s[i] == '\0') {
    return 0;
  }
  long rev = 0;
  int sign = 1;
  if (s[i] == '+') {
    sign = 1;
    i++;
  }
  else if (s[i] == '-') {
    sign = -1;
    i++;
  }
  int max = (unsigned int) ~0 >> 1;
  int min = 1 << 31;
  while(s[i] != '\0') {
    if (s[i] < '0' || s[i] > '9') break;
    int d = s[i] - '0';
    rev = rev*10 + d;
    if (rev > max) break;
    i++;
  }
  rev *= sign;
  if (rev > max) return max;
  if (rev < min) return min;
  return rev;
}

int
main (int argc, char **argv)
{
  char *s = "123";
  printf("%d\n", atoi(s));

  char *t = "-123";
  printf("%d\n", atoi(t));

  char *p = "junk";
  printf("%d\n", atoi(p));

  char *r = "-1junk";
  printf("%d\n", atoi(r));

  char *q = "9223372036854775809";
  printf("%d\n", atoi(q));
}
