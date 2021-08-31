#include <stdio.h>
#include <stdlib.h>

struct Array {
  int *A;
  int size;
  int length;
};

void display(struct Array arr) {
  int i;
  printf("The elements are: ");
  for (i = 0; i < arr.length; i++)
    printf("%d ", arr.A[i]);
  printf("\n");
}

int main() {
  struct Array arr;
  int n, i;
  arr.length = 0;
  arr.A = (int *)malloc(arr.size * sizeof(int));
  printf("Enter the size of the array: ");
  scanf("%d", &arr.size);

  printf("Enter the no. of elements: ");
  scanf("%d", &n);

  printf("Enter all the elements: ");
  for (i = 0; i < n; i++)
    scanf("%d", &arr.A[i]);
  arr.length = n;

  arr.A[arr.length] = 7; //Adding in an array
  arr.length++;

  display(arr);
}