#include <iostream>
using namespace std;

int main(void) {

  int a = 1;
  static int b = 2;
  a = b + 1;

  return 0;
}
