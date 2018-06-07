#include <iostream>
#include <cstdio>
using namespace std;

class X {
public:
  X(int i) : val(i) {

  }

  ~X() {
    cout << "X destructor called\n" << endl;
  }
  operator int() {
    cout << "strong convert called\n" << endl;
    return val;
  }
  X foo() {

  }
private:
  int val;
};

class B {
int a;
int b;
void method1() {}
void method2() {}
void method3() {}


};

class pseudo {
public:
  int a;


};

class C {
public:
  int a;
  int b;
  int c;
};



int main(void) {
  X tt(3);
  B m; 

  int c = int(tt);
  cout << c << endl;
  cout << sizeof(m) << endl;
  //printf("%p\n", &C::a);

  C n;
  n.a = 1;
  n.b = 2;
  n.c = 3;
  cout << n.*(&C::a) << endl;

  return 0;
}
