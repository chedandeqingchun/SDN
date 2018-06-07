#include <iostream>
using namespace std;


class X {
  int i;
public: 
  X(int ii = 0);
  void modify();
};

X::X(int ii):i(ii) {}


void X::modify() {
  i++;
}

X f5() {
  return X();
}

const X f6() {
  return X();

}

void f7(const X &x) {
  //x.modify();
}


int f8() {
  int x = 2;
  return x;
}


const int * const f9() {
  static const int i = 100;
  return &i; 


}



int main(void) {
  f5() = X(1);
  f5().modify();
  f7(f5());

  //f8() = 2;

  return 0;
}
