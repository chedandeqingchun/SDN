#include <iostream>

class X {
public:
  void f() {

  }
};


class Y {
public:
  void g() {

  }
};

template<typename T>
class Z {
  T t;
public:
  void a() {
    t.f();
  }

  void b() {
    t.g(); 
  }
};


int main(void) {
  Z<X> zx;
  zx.a();
  Z<Y> Zy;
  Zy.b();
  return 0;
}
