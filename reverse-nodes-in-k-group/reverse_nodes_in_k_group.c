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
reverse (struct list_node *head, int k)
{
  struct list_node *dummy = malloc(sizeof(struct list_node)), *next = NULL;
  dummy->next = NULL;
  while (k) {
    next = head;
    head = head->next;
    next->next = dummy->next;
    dummy->next = next;
    k--;
  }
  return dummy->next;
}

struct list_node *
k_reverse (struct list_node *head, int k)
{
  if (!head || !head->next) {
    return head;
  }
  struct list_node *dummy = malloc(sizeof(struct list_node));
  dummy->next = head;
  struct list_node *prev = dummy, *cur = head, *next = NULL;
  int count = 0;
  while (cur) {
    count++;
    cur = cur->next;
    if (count == k) {
      count = 0;
      next = prev->next;
      prev->next = reverse(next, k);
      next->next = cur;
      prev = next;
    }
  }
  return dummy->next;
}

int
main (int argc, char **argv)
{
  int a[] = {1, 2, 3, 4, 5, 6};
  struct list_node *la = construct_list_node(a, sizeof(a)/sizeof(int));
  log_list_node(*la);
  struct list_node *rla = k_reverse(la, 6);
  log_list_node(*rla);
}
