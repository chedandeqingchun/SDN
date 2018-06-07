#include <iostream>

void g() {
  std::cout << "global g" << endl;
}

template <class T>
class Y {
public:
   void g() {
     std::cout << "Y<" << typeid(T).name() << ">::g()" << endl;
   }

   void h() {
     std::cout << "Y<" << typeid(T).name() << ">::h()" << endl;
   }

   typedef int E;
};

typedef double E;


template<class T>
void swap(T& t1, T& t2) {
  std::cout << "global swap" << endl;
  T temp = t1;
  t1 = t2;
  t2 = t1;
}


template <class T>

class X : public Y<T> {
public:
  E f() {
    g();
    this->h();
    T t1 = T(), t2 = T(1);
    cout << t1 << endl;
    swap(t1, t2);
    std::swap(t1, t2);
    cout << typeid(E).name() << endl;
    return E(t2);
  }
};


int main(void) {
  X<int> x;
  cout << x.f() << endl;
  return 0;
}
