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
merge (struct list_node *l1, struct list_node *l2)
{
  struct list_node *head = malloc(sizeof(struct list_node)), *ref = head;
  while (l1 || l2) {
    if (!l1) {
      head->next = l2;
      l2 = l2->next;
    }
    else if (!l2) {
      head->next = l1;
      l1 = l1->next;
    }
    else {
      if (l1->val < l2->val) {
        head->next = l1;
        l1 = l1->next;
      }
      else {
        head->next = l2;
        l2 = l2->next;
      }
    }
    head = head->next;
  }
  return ref->next;
}

int
main (int argc, char **argv)
{
  int a[] = {1, 3, 5, 7, 9};
  int b[] = {2, 4, 6, 8, 10};
  struct list_node *la = construct_list_node(a, 5);
  struct list_node *lb = construct_list_node(b, 5);
  log_list_node(*la);
  log_list_node(*lb);
  struct list_node *lc = merge(la, lb);
  log_list_node(*lc);
}
