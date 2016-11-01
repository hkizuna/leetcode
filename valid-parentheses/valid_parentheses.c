#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool
is_valid (char *s) {
  int len = (int) strlen(s);
  char *stack = malloc(len * sizeof(char));
  int size = 0;
  while (*s != '\0') {
    if (*s == '(' || *s == '[' || *s == '{') {
      *stack++ = *s++;
      size++;
      continue;
    }
    char top = *(stack - 1);
    if (*s == ')' && top == '(') {
      s++;
      stack--;
      size--;
      continue;
    }
    else if (*s == ']' && top == '[') {
      s++;
      stack--;
      size--;
      continue;
    }
    else if (*s == '}' && top == '{') {
      s++;
      stack--;
      size--;
      continue;
    }
    return false;
  }
  return size == 0 ? true : false;
}

int
main (int argc, char **argv)
{
  char *s = "[[[[]]]]";
  printf("%d\n", is_valid(s));
}
