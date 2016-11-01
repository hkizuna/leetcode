#include <stdio.h>

#define MIN(a, b) (((a)<(b))?(a):(b))

double
find_kth (int *a, int sa, int *b, int sb, int k)
{
  if (k == 1) {
    return MIN(*a, *b);
  }
  if (sa == 0) {
    return b[k-1];
  }
  if (sa > sb) {
    return find_kth(b, sb, a, sa, k);  
  }

  int pa = MIN(k/2, sa), pb = k - pa;
  if (a[pa-1] < b[pb-1]) {
    return find_kth(a+pa, sa-pa, b, sb, k-pa);
  }
  else if (a[pa-1] > b[pb-1]) {
    return find_kth(a, sa, b+pb, sb-pb, k-pb);
  }
  else {
    return a[pa-1];
  }
}

double
find_median (int *a, int sa, int *b, int sb)
{
  int total = sa + sb;
  if (total & 0x1) {
    return find_kth(a, sa, b, sb, total/2+1);
  }
  else {
    return (find_kth(a, sa, b, sb, total/2) + find_kth(a, sa, b, sb, total/2+1))/2;
  }
}

int
main (int argc, char **argv)
{
  int a[] = {1, 3};
  int b[] = {2};
  printf("%f\n", find_median(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int)));
  int c[] = {1, 3};
  int d[] = {2, 4};
  printf("%f\n", find_median(c, sizeof(c)/sizeof(int), d, sizeof(d)/sizeof(int)));
}
