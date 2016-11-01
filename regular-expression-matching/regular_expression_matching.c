#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
is_match (const char *s, const char *p)
{
  if (*p == '\0') return *s == '\0';

  if (*(p+1) != '*') {
    return ((*p == *s) || (*p == '.' && *s != '\0')) && is_match(s+1, p+1);
  }
  while((*p == *s) || (*p == '.' && *s != '\0')) {
    if (is_match(s, p+2)) return 1;
    s++;
  }
  return is_match(s, p+2);
}

int
main (int argc, char **argv)
{
  char *s = "aab";
  char *p = "c*a*b";
  printf("%d\n", is_match(s, p));
}
