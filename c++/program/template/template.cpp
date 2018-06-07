#include <iostream>
using namespace std;
/*
*
* Default parameter
*/

template<class T, size_t N = 100> class uStack {
  T data[N];
  size_t count;
  public:
  void push(const T& t);
};


int main(void) {
  uStack<int, 100> myFixedStack;

  

  return 0;
}
