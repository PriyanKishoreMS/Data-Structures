#include <iostream>

using namespace std;

int main() {
  int A[5] = {5, 2, 3, 4, 4};

  int i, n;
  for(i=0;i<5;i++) {
    n += A[i];
  }
  cout << n << endl;
}

