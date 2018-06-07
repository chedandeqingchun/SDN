#include <iostream>
using namespace std;


class A {
public:
  int a;
  int b;
};



int main(void) {

  A m;
  m.a = 1;
  m.b = 2;

  cout << m.a << endl;
  cout << m.*(&A::a) << endl;

  return 0;
}
