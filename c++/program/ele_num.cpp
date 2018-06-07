#include <iostream>

struct T{
  int a;
};


int main(void) {
  int a[5];

  std::cout << sizeof(a) << std::endl;
  std::cout << sizeof(a) / sizeof(a[0]) << std::endl;
  std::cout << (sizeof(a) | sizeof(a[0])) << std::endl;

  T t;
  int T::*p = &T::a;
  t.*p = 10;

  return 0;
}
