#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *
zigzag (char *s, int rows)
{
  int n = (int) strlen(s);
  if (n <= rows || rows == 1) {
    return s;
  }
  char *t = malloc((n+1)*sizeof(char)), *ref = t;
  for(int i = 0; i < rows; i++) {
    if (i == 0 || i == rows-1) {
      int p = i;
      while(p < n) {
        *t++ = s[p];
        p += 2*rows-2;
      }
    }
    else {
      int p = i, zig = 0;
      while(p < n) {
        *t++ = s[p];
        if (zig) {
          p += 2*i;
          zig = 0;
        }
        else {
          p += 2*rows-2*i-2;
          zig = 1;
        }
      }
    }
  }
  *t = '\0';
  return ref;
}

int
main (int argc, char **argv)
{
  char *s = "PAYPALISHIRING";
  printf("%s-%d\n", s, 3);
  printf("%s\n", zigzag(s, 3));
  printf("%s-%d\n", s, 4);
  printf("%s\n", zigzag(s, 4));
}
