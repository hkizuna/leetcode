#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct list_node
{
  int val;
  struct list_node *next;
};

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

struct list_node *
swap (struct list_node *head)
{
  if (!head || !head->next) {
    return head;
  }
  struct list_node *dummy = malloc(sizeof(struct list_node));
  dummy->next = head;
  struct list_node *prev = dummy, *cur = head;
  while (cur && cur->next) {
    prev->next = cur->next;
    cur->next = prev->next->next;
    prev->next->next = cur;
    prev = cur;
    cur = cur->next;
  }
  return dummy->next;
}

int
main (int argc, char **argv)
{
  int a[] = {1, 2, 3, 4, 5, 6};
  struct list_node *la = construct_list_node(a, sizeof(a)/sizeof(int));
  log_list_node(*la);
  struct list_node *sa = swap(la);
  log_list_node(*sa);
}
