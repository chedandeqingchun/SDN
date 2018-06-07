#include <iostream>
using namespace std;

union Packed {
  char i;
  char m;
  short j;
  int k;
  long l;
  float f;
  double d;
};

int main() {
  cout << "sizeof(Packed) = "
  << sizeof(Packed) << endl;

  Packed x;

  x.i = 'c';
  cout << x.i << endl;
  cout << x.m << endl;
  x.d = 3.14159;
  cout << x.d << endl;
}

