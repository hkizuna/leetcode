#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int
divide (int dividend, int divisor)
{
  int max = (unsigned int) ~0 >> 1;
  int min = 1 << 31;
  if (divisor == 0) {
    return max;
  } 
  if (divisor == 1) {
    return dividend;
  }
  if (divisor == -1 && dividend == min) {
    return max;
  }
  long p_dividend = dividend > 0 ? dividend : - (long) dividend;
  long p_divisor = divisor > 0 ? divisor : - (long) divisor;
  int divided = 0;
  while (p_dividend >= p_divisor) {
    int shifts = 0;
    while (p_dividend >= (p_divisor << shifts) && (p_divisor << shifts) > 0) {
      shifts++;
    }
    shifts--;
    divided += 1 << shifts;
    p_dividend -= p_divisor << shifts;
  }

  if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
    return divided;
  }
  else {
    return -divided;
  }
}

int
main (int argc, char **argv)
{
  printf("%d\n", divide(-2147483648, 2));
}
