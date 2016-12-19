#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

double
power (double x, int n)
{
  if (n == 0) {
    return 1;
  }
  double v = power(x, n/2);
  if (n & 1) {
    return v * v * x;
  }
  else {
    return v * v;
  }
}

double
mypow (double x, int n)
{
  if (n < 0) {
    return 1.0/power(x, -n);
  }
  else {
    return power(x, n);
  }
}

int
main (int argc, char **argv)
{
  double x = 8.88023;
  printf("%f\n", mypow(x, 3));
}
