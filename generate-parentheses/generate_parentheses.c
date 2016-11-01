#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char *
append (char *s, char c)
{
  int size = (int) strlen(s);
  char *t = malloc((size+2)*sizeof(char)), *sref = s, *tref = t;
  while(*s != '\0') {
    *t++ = *s++;
  }
  *t++ = c;
  *t = '\0';
  s = sref;
  return tref;
}

void
generate_recursive (int l, int r, int n, int *size, char *one, char **all)
{
  if (l < r) {
    return;
  }
  if (l == n && r == n) {
    all[*size] = malloc((2*n+1)*sizeof(char));
    for (int i = 0; i < 2 * n; i++) {
      all[*size][i] = one[i];
    }
    all[*size][2*n] = '\0';
    (*size)++;
    return;
  }
  
  if (l == n) {
    generate_recursive (l, r + 1, n, size, append(one, ')'), all);
    return;
  }
  generate_recursive(l + 1, r, n, size, append(one, '('), all);
  generate_recursive(l, r + 1, n, size, append(one, ')'), all);
}

char **
generate (int n, int *size)
{
  char *one = malloc(sizeof(char));
  *one = '\0';
  int a = 1;
  int b = 1;
  for(int i = 2; i <= n; i++) {
    a *= i;
    b *= i + n;
  }
  char **all = malloc(b/a*sizeof(char *));
  generate_recursive(0, 0, n, size, one, all);
  return all;
}

int
main (int argc, char **argv)
{
  int size = 0;
  char **all = generate(6, &size);
  for(int i = 0; i < size; i++) {
    printf("%s\n", all[i]);
  }
}
