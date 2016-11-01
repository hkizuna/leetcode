#include <stdio.h>

int
reverse (int x)
{
  long rev = 0;
  while(x != 0) {
    rev = rev*10 + x%10;
    x /= 10;
  }
  int max = (unsigned int) ~0 >> 1;
  if (rev > max) {
    return 0;
  }
  int min = 1 << 31;
  if (rev < min) {
    return 0;
  }
  return rev;
}

int
main (int argc, char **argv)
{
  int a = 321;
  printf("%d\n", reverse(a));

  int b = -123;
  printf("%d\n", reverse(b));

  int c = 1534236469;
  printf("%d\n", reverse(c));
}
