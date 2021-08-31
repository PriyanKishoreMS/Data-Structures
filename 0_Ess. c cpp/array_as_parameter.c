#include <stdio.h>
#include <stdlib.h>

// void fun(int a[], int n) {
//   int i;
//   for(i=0;i<n;i++) {
//     printf("%d\n", a[i]);
//   }
// }
//
// int main() {
//   int a[5] = {9, 8, 7, 6, 5};
//   fun(a, 5);
// }

int * fun(int n) {
  int *p = (int *)malloc(sizeof(n));
  for(int i=0;i<n;i++)
  p[i] = i + 1;
  return p;
}

int main() {
  int *a, size = 6;
  a = fun(size);
  for(int i=0;i<size;i++)
  printf("%d ", a[i]);
  return 0;
}
