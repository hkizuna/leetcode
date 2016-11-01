#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int *
build_next (char *s)
{
  int size = (int) strlen(s);
  int *next = malloc((size + 1) * sizeof(int));
  next[0] = next[1] = 0;
  for (int i = 1; i < size; i++) {
    if (s[i] == s[next[i]]) {
      next[i+1] = next[i] + 1;
    }
    else {
      int index = next[i];
      while (index > 0 && s[i] != s[next[index]]) {
        index = next[index];
      }
      if (index > 0) {
        next[i+1] = next[index] + 1;
      }
      else {
        next[i+1] = 0;
      }
    }
  }
  return next;
}

int
kmp (char *haystack, char *needle)
{
  if (!*needle) {
    return 0;
  }
  int *next = build_next(needle);
  int size = (int) strlen(haystack), i = 0, j = 0;
  while (i + j < size) {
    if (needle[j] == haystack[i + j]) {
      if (!needle[j+1]) {
        return i;
      }
      j++;
    }
    else {
      if (next[j] > 0) {
        i += j - next[j];
        j = next[j];
      }
      else {
        i++;
        j = 0;
      }
    }
  }
  return -1;
}

int
main (int argc, char **argv)
{
  char *s = "bbababbaababaabbaa";
  char *t = "bbabba";
  printf("%s - %s\n", s, t);
  printf("%d\n", kmp(s, t));
}
