#include <iostream>
using namespace std;

// struct rectangle {
//   int length;
//   int breadth;
// };

struct test {
  int a[5];
};

//call by value;

// int area(struct rectangle rect) {
//   rect.length++;
//   return rect.length * rect.breadth;
// }
//
// int main() {
//   struct rectangle r = {10, 5};
//   cout << area(r) << endl;
// }

//call by address;

// int area(struct rectangle *p, int l) {
//   p->length = l;
//   return p->length * p->breadth;
// }
//
// int main() {
//   struct rectangle r = {10, 5};
//   cout << area(&r, 12) <<endl;
// }

//call by address with array as datatype in struct;

int fun(struct test *p) {
  p->a[0]=25;
  p->a[1]=16;
  for(int i=0;i<5;i++)
  {
    cout << p->a[i] << endl;
  }
  return 0;
}

int main() {
  struct test t = {{5,4,3,2,1}};
  fun(&t);
}
