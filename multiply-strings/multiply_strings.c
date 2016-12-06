#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void
reverse (char *s)
{
  int l = 0, r = ((int) strlen(s)) - 1;
  while (l < r) {
    char c = s[l];
    s[l] = s[r];
    s[r] = c;
    l++;
    r--;
  }
}

char *
multiply(char *num0, char *num1)
{
  int n0 = (int) strlen(num0), n1 = (int) strlen(num1);
  int n = n0 + n1;
  reverse(num0);
  reverse(num1);
  char *product = malloc((n + 1) * sizeof(char));
  memset(product, '0', n);
  product[n] = '\0';

  for (int i = 0; i < n1; i++) {
    int carry = 0;
    int val = num1[i] - '0';
    for (int j = 0; j < n0; j++) {
      carry += (num0[j] - '0') * val + (product[i+j] - '0');
      product[i+j] = carry%10 + '0';
      carry /= 10;
    }
    if (carry) {
      product[n0+i] = carry + '0';
    }
  }
  reverse(product);
  while (*product == '0' && *(product+1) != '\0') {
    product++;
  }
  return product;
}

int
main (int argc, char **argv)
{
  char s[] = "10";
  char t[] = "1";
  printf("%s\n", multiply(s, t));
}
