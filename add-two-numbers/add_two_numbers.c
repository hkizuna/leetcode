#include <stdio.h>
#include <stdlib.h>

struct list_node
{
  int val;
  struct list_node *next;
};

struct list_node *
add_two_numbers (struct list_node *n0, struct list_node *n1)
{
  struct list_node *head = malloc(sizeof(struct list_node)), *ref = head;
  int carry = 0;
  while(n0 || n1) {
    if (!n0) {
      head->val = (n1->val + carry) % 10;
      carry = n1->val + carry >= 10 ? 1 : 0;
      head->next = malloc(sizeof(struct list_node));
      n1 = n1->next;
    }
    else if (!n1) {
      head->val = (n0->val + carry) % 10;
      carry = n0->val + carry >= 10 ? 1 : 0;
      head->next = malloc(sizeof(struct list_node));
      n0 = n0->next;
    }
    else {
      head->val = (n0->val + n1->val + carry) % 10;
      carry = n0->val + n1->val + carry >= 10 ? 1 : 0;
      head->next = malloc(sizeof(struct list_node));
      n0 = n0->next;
      n1 = n1->next;
    }
    if (n0 || n1) {
      head = head->next;
    }
    else {
      if (carry) {
        head->next->val = 1;
        head->next->next = NULL;
      }
      else {
        head->next = NULL;
      }
    }
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
  int a0[] = {7, 4, 5};
  int a1[] = {2, 4, 5};
  struct list_node *n0 = construct_list_node(a0, sizeof(a0)/sizeof(int));
  struct list_node *n1 = construct_list_node(a1, sizeof(a1)/sizeof(int));

  log_list_node(*n0);
  log_list_node(*n1);
  
  struct list_node *n2 = add_two_numbers(n0, n1);
  log_list_node(*n2);
}
