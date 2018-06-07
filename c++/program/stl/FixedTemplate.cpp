#include <iostream>
using namespace std;

template <class T, size_t N>

class SStack {
  T data[N];
};


int main(void) {

  SStack<int, 10> container;


  return 0;
}
