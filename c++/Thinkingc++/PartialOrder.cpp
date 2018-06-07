#include <iostream>
using namespace std;

template<class T, class U> 
class C {
public:
  void f() {
    cout << "primary template" << endl;
  }
};


template<class U> 
class C<int, U> {
public:
  void f() {
    cout << "T == int\n" << endl;
  }
};


template<class T> 
class C<T, double> {
public:
  void f() {
    cout << "U == double\n" << endl;
  }
};

template<class T, class U> 
class C<T*, U> {
public:
  void f() {
    cout << "T* is used" << endl;
  }
};

template<class T, class U> 
class C<T, U*> {
public:
  void f() {
    cout << "U* is used" << endl;
  }
};

template<class T, class U> 
class C<T*, U*> {
public:
  void f() {
    cout << "U* and T* used" << endl;
  }
};

template<class T> 
class C<T, T> {
public:
  void f() {
    cout << "T == T used" << endl;
  }
};

int main(void) {

  C<float, int>().f();
  C<int, float>().f();
  C<float, double>().f();
  C<float, float>().f();
  C<float*, float>().f();
  C<float, float*>().f();
  C<float*, int*>().f();


  return 0;
}
