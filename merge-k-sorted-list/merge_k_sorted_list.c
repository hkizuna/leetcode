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
  if (!l1 && !l2) {
    return NULL;
  }
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

struct list_node *
k_merge (struct list_node **lists, int size)
{
  if (size == 0) {
    return NULL;
  }
  if (size == 1) {
    return *lists;
  }
  if (size == 2) {
    return merge(*lists, *(lists+1));
  }
  int l = size/2, r = size - l;
  struct list_node *ln = k_merge(lists, l);
  struct list_node *rn = k_merge(lists + l, r); 
  return merge(ln, rn);
}

int
main (int argc, char **argv)
{
  int a[] = {1, 4, 7, 10};
  int b[] = {2, 5, 8, 11};
  int c[] = {3, 6, 9, 12};

  struct list_node *la = construct_list_node(a, sizeof(a)/sizeof(int));
  struct list_node *lb = construct_list_node(b, sizeof(b)/sizeof(int));
  struct list_node *lc = construct_list_node(c, sizeof(c)/sizeof(int));

  log_list_node(*la);
  log_list_node(*lb);
  log_list_node(*lc);

  struct list_node **lists = malloc(3*sizeof(struct list_node *));
  lists[0] = la;
  lists[1] = lb;
  lists[2] = lc;
  struct list_node *m = k_merge(lists, 3);
  log_list_node(*m);
}
