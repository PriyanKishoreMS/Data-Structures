#include <iostream>
using namespace std;

void swap(int &x, int *y) { //x by reference and y by address
  int temp;
  temp = x;
  x = *y;
  *y = temp;
}

int main() {
  int a, b;
  a = 10;
  b = 20;
  swap(a, &b);
  cout << a << ", " << b << endl;
}
