#include <iostream>
using namespace std;

class rectangle {
private:
  int length;
  int breadth;

public:
  rectangle(int l, int b);
  int area();
  int perimeter();
  int getLength() {
    return length;
  }
  void setLength(int l) {
    length = l;
  }
};

rectangle::rectangle(int l, int b) {
  length = l;
  breadth = b;
}

int rectangle::area() {
  return length * breadth;
}

int rectangle::perimeter() {
  return 2*(length+breadth);
}

int main() {
  rectangle r(10, 5);
  cout << "Area is: " << r.area() << endl;
  cout << "Perimeter is: " << r.perimeter() << endl;
  cout << "Length is: " << r.getLength() << endl;
  r.setLength(20);
  cout << "Length after change is: " << r.getLength() << endl;
}
