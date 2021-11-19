#include <iostream>
using namespace std;

struct rectangle {
  int length;
  int breadth;
};

int init(struct rectangle *p, int l, int b) {
  p->length = l;
  p->breadth = b;
  return 0;
}

int area(struct rectangle p) {
  return p.length * p.breadth;
}

void changeLength(struct rectangle *p, int l) {
  p->length = l;
}

int main() {
  struct rectangle r;
  init(&r, 10, 5);
  cout << "Area is: " << area(r) << endl;
  changeLength(&r, 25);
  cout << "Changed length: " << r.length << endl;
  cout << "Area after changing length: " <<  area(r) << endl;
}
