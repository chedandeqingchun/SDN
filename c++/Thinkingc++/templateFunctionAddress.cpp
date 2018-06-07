#include <iostream>
using namespace std;

template<typename T> void f(T*) {

}

void h(void (*pf)(int*)) {

}

template<typename T>
void g(void (*pf)(T*)) {

}


int main(void) {
  h(&f<int>);
  h(&f);
  g<int>(&f<int>);
  g(&f<int>);
  g<int>(&f);
  return 0;
}
