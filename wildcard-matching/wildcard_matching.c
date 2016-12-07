#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// bool
// is_match(const char *s, const char *p)
// {
//   printf("[%s-%s]\n", s, p);
//   if (*p == '\0') {
//     return *s == '\0';
//   }
// 
//   if (*p == '*' && *(p+1) == '*') {
//     return is_match(s, p+1);
//   }
// 
//   if (*p == '*' && *(p+1) == '\0') {
//     return true;
//   }
//   
//   if (*p == '*') {
//     while (*s != '\0') {
//       if (is_match(s, p+1)) {
//         return true;
//       }
//       s++;
//     }
//   }
// 
//   if (*p == *s || (*p == '?' && *s != '\0')) {
//     return is_match(s+1, p+1);
//   }
// 
//   return false;
// }

bool
is_match (const char *s, const char *p)
{
  const char *t = NULL, *r = s;
  while (*s) {
    if (*p == *s || *p == '?') {
      p++;
      s++;
      continue;
    }
    if (*p == '*') {
      t = p++;
      r = s;
      continue;
    }
    if (t) {
      p = t + 1;
      s = ++r;
      continue;
    }
    return false;
  }
  while (*p == '*') {
    p++;
  }
  return !*p;
}

int
main (int argc, char **argv)
{
  printf("%d\n", is_match(*(argv+1), *(argv+2)));
}
