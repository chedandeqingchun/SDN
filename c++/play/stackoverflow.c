#include <stdio.h>
#include <string.h>


void func() {
  unsigned char buf[10];
  strcpy(buf, "hello world AAAAAAAAAAAAA");
  printf("%s\n", buf);
}


int main(void) {
  func();

  return 0;
}
