#include <iostream>
using namespace std;

template<class T>

struct MyIter {
  typedef T value_type;
  T *ptr;
  MyIter(T* p = 0) : ptr(p) {

  }

  T& operator*() const {
    return *ptr;
  }
};


template<class I>
typename I::value_type
func(I ite) {
  return *ite;
}



int main(void) {
  MyIter<int> ite(new int(8));
  cout << func(ite);

  return 0;
}
