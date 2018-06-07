#include <stdio.h>


int main(void) {

  int a = 3, b = 4;
  int c = 5, d = 6;

  a?a++:++b;
  0?c++:++d;

  printf("%d %d\n", a, b);
  printf("%d %d\n", c, d);

  return 0;
}
