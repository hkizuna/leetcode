#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
longest_substring (char *s)
{
  int m = 0, n = 0, longest = 0;
  while(s[n] != '\0') {
    for(int i = m; i < n; i++) {
      if (s[i] == s[n]) {
        m = i + 1;
        break;
      }
    }
    if (n - m + 1 > longest) {
      longest = n - m + 1; 
    }
    n++;
  }
  return longest;
}

int
main (int argc, char **argv)
{
  char *s = "abcabcbb";
  printf("%s: %d\n", s, longest_substring(s)); 

  char *t = "bbbbb";
  printf("%s: %d\n", t, longest_substring(t));

  char *p = "pwwkew";
  printf("%s: %d\n", p, longest_substring(p));

  char *r = "a";
  printf("%s: %d\n", r, longest_substring(r));
}
