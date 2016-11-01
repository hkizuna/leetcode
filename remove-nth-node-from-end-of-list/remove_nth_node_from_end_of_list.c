#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list_node {
  int val;
  struct list_node *next;
};

struct list_node *
remove_nth_from_end (struct list_node *head, int n)
{
  if (n == 0) {
    return head;
  }
  struct list_node *ln = head, *ln1 = NULL, *ref = head;
  int i = 0;
  while (head->next) {
    head = head->next;
    i++;
    if (i >= n) {
      ln1 = ln;
      ln = ln->next;
    }
  }
  if (ln1 && ln->next) {
    ln1->next = ln->next;
  }
  else if (ln1) {
    ln1->next = NULL;
  }
  else if (ln->next) {
    ref = ln->next;
  }
  else {
    ref = NULL;
  }
  return ref;
}

struct list_node *
construct_list_node (int *a, int size)
{
  struct list_node *head = malloc(sizeof(struct list_node)), *ref = head;
  for(int i = 0; i < size-1; i++) {
    head->val = a[i];
    head->next = malloc(sizeof(struct list_node));
    head = head->next;
  }
  head->val = a[size-1];
  head->next = NULL;
  return ref;
}

void
log_list_node (struct list_node n)
{
  printf("(");
  while(n.next) {
    printf("%d -> ", n.val);
    n = *(n.next);
  }
  printf("%d)\n", n.val);
}

int
main (int argc, char **argv)
{
  int a[] = {1, 2, 3, 4, 5};
  struct list_node *l = construct_list_node(a, 5);
  log_list_node(*l);
  struct list_node *n = remove_nth_from_end(l, 5);
  log_list_node(*n);
}
