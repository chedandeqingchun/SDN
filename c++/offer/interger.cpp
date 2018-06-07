#include <iostream>
#include <cstring>


int main(void) {
  unsigned int num = 65512;
  int num1 = num;
  std::cout << num1 << std::endl;
  std::cout << -num1 << std::endl;

  std::cout << strlen("liu") << std::endl;
  std::cout << sizeof("liu") << std::endl;

  const char * str = "1234";
  str++; 
  std::cout << strlen(str) << std::endl;
  


return -1;

}
