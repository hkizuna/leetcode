#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *
longest_common_prefix (char **ss, int size)
{
  if (size < 1) return "";
  int n = (unsigned int) ~0 >> 1;
  char *s = NULL;
  for(int i = 0; i < size; i++) {
    int l = (int) strlen(ss[i]);
    if (l < n) {
      n = l;
      s = ss[i];
    }
  }
  char *prefix = malloc(n+1);
  memset(prefix, 0, n+1);
  int j = 0;
  while(s[j] != '\0') {
    for(int i = 0; i < size; i++) {
      if (ss[i][j] != s[j]) {
        prefix[j] = '\0';
        return prefix;
      }
    }
    prefix[j] = s[j];
    j++;
  }
  prefix[j] = '\0';
  return prefix;
}

int
main (int argc, char **argv)
{
  char *ss[4] = {"b", "c", "d", "a"};
  printf("%s\n", longest_common_prefix(ss, sizeof(ss)/sizeof(char *)));
}
