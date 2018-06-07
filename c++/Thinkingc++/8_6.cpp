#include <iostream>
using namespace std;


int main(void) {
  enum {buf_size = 5};
  const char buf[buf_size] = {'a', 'a', 'a', 'a', 'a'};
  //buf[0] = 'b';

  return 0;
}
