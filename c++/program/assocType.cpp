#include <iostream>
using namespace std;

template<class I, class T>

void func_impl(I iter, T t) {

  T ss = 5;
  cout << ss << endl;
}


template <class I>
inline
void func(I iter) {
  func_impl(iter, *iter);
}




int main(void) {
  int i;
  func(&i);
  return 0;
}
