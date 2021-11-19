#include <stdio.h>
#include <stdlib.h>

struct rectangle {
  int length;
  int breadth;
};

int main() {
  int area;
  struct rectangle *p = (struct rectangle*)malloc(sizeof(struct rectangle));
  printf("Enter length: ");
  scanf("%d", &p->length);
  printf("Enter breadth: ");
  scanf("%d", &p->breadth);
  area = p->length * p-> breadth;
  printf("%d is the area of the rectangle\n", area);
}
