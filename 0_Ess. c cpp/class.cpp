#include <iostream>
using namespace std;

class rectangle {
private:
  int length;
  int breadth;

public:
  rectangle(int l, int b) {
    length = l;
    breadth = b;
  }

  int area() {
    return length * breadth;
  }

  void changeLength(int l) {
    length = l;
  }

  int showLength() {
    return length;
  }
};

int main() {
  rectangle r(10, 5);
  cout << "Area is: " << r.area() << endl;
  r.changeLength(25);
  cout << "Changed length: " << r.showLength() << endl;
  cout << "Area after changing length: " <<  r.area() << endl;
}
