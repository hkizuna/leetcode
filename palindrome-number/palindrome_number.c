#include <stdio.h>

int
is_palindrome (int x)
{
  if (x < 0) return 0;
  int div = 1;
  while(x/div >= 10) {
    div *= 10;
  }
  while(x != 0){
    int left = x/div;
    int right = x%10;
    if (left != right) return 0;
    x = x%div/10;
    div /= 100;
  }
  return 1;
}

int
main (int argc, char **argv)
{
  int a = 1221;
  printf("%d\n", is_palindrome(a));
}
