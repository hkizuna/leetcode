#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

char *
preprocess (char *s)
{
  int n = (int) strlen(s);
  char *t = malloc((2*n+2) * sizeof(char));
  char *p = t;
  while(*s) {
    *t++ = '#';
    *t++ = *s++;  
  }
  *t++ = '#';
  *t = '\0';
  return p;
}

char *
postprocess (char *t)
{
  int n = (int) strlen(t);
  char *s = malloc(((n-1)/2+1) * sizeof(char));
  char *p = s;
  while(*t) {
    if (*t != '#') {
      *s++ = *t;
    }
    t++;
  }
  *s = '\0';
  return p;
}

char *
manacher (char *s)
{
  char *t = preprocess(s);
  int n = (int) strlen(t);
  int p[n], id = 0, mx = 0;
  memset(p, 0, n);
  for(int i = 0; t[i] != '\0'; i++) {
    p[i] = mx > i ? MIN(p[2*id-i], mx-i) : 1;
    while(i-p[i] >= 0 && i+p[i] < n && t[i-p[i]] == t[i+p[i]]) p[i]++;
    if (i + p[i] > mx) {
      mx = i + p[i];
      id = i;
    }
  }
  int largest = 0, i = 0;
  for(int j = 0; j < n; j++) {
    if (p[j] > largest) {
      largest = p[j];
      i = j;
    }
  }
  char *tp = malloc(2*largest*sizeof(char));
  char *pp = tp;
  for(int j = i - largest + 1; j < i + largest; j++) {
    *tp++ = t[j];
  }
  *tp = '\0';
  return postprocess(pp);
}

int
main (int argc, char **argv)
{
  char *s = "abaacbcaaab";
  char *t = manacher(s);
  printf("%s\n", t);
}
