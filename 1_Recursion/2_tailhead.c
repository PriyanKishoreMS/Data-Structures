#include <stdio.h>

void fun(int a) {
  if(a>0) {
    fun(a-1);
    printf(" %d\n", a);
  }
}

int main() {
  int x = 5;
  fun(x);
}
