#include <iostream>
using namespace std;

template <int N>
class Factorial {
public:
  enum {value = N * Factorial<N-1>::value};
};

class Factorial<1> {
public:
  enum {value = 1};
};

int main(void) {



  return 0;
}
