#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void
letter_combination_recursive (char *digits, int index, int size, char *combination, char **combinations, char **sys, int *rsize)
{
  if (index == size) {
    combinations[*rsize] = malloc((size + 1) * sizeof(char));
    for(int i = 0; i < size; i++) {
      combinations[*rsize][i] = combination[i];
    }
    combinations[*rsize][size] = '\0';
    (*rsize)++;
    return;
  }
  int i = digits[index] - '0';
  int n = (int) strlen(sys[i]);
  for(int j = 0; j < n; j++) {
    combination[index] = sys[i][j];
    letter_combination_recursive(digits, index + 1, size, combination, combinations, sys, rsize);
  }
}

char **
letter_combinations (char *digits, int *rsize)
{
  static char *sys[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  int size = (int) strlen(digits);
  int csize = 1;
  for(int i = 0; i < size; i++) {
    csize *= (int) strlen(sys[digits[i] - '0']);
  }
  char *combination = malloc(size * sizeof(char));
  char **combinations = malloc(csize * sizeof(char *)), **ref = combinations;
  letter_combination_recursive(digits, 0, size, combination, combinations, sys, rsize);
  return ref;
}

int
main (int argc, char **argv)
{
  char *digits = "23";
  int size = 0;
  char **combinations = letter_combinations(digits, &size);
  for(int i = 0; i < size; i++) {
    printf("%s\n", combinations[i]);
  }
}
