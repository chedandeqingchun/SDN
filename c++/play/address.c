#include <stdio.h>

int main(void) {
  int a = 1;
  int b = 2;
  a = a + b;
  a++;
  b++;
  int c =5;

  printf("%p\n", &a);
  printf("%p\n", &b);
  printf("%p\n", &c);

  return 0;
}
