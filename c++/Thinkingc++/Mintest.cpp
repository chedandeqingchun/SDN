#include <iostream>
#include <cstring>

using std::strcmp;
using std::cout;
using std::endl;

template<typename T>const T& min(const T& a, const T& b) {
  cout << "template called" << endl;
  return (a < b) ? a : b;
}

const char* min(const char* a, const char* b) {
  cout << "char called" << endl;
  return (strcmp(a, b) < 0) ? a : b;
}

double min(double x, double y) {
  cout << "double called" << endl;
  return (x < y) ? x : y;
}

int main(void) {
  const char* s2 = "say";
  const char* s1 = "knight who";
  
  cout << min(1, 2) << endl;
  cout << min(1.0, 2.0) << endl;
  cout << min(1, 2.0) << endl;
  cout << min(s1, s2) << endl; 
  cout << min<>(s1, s2) << endl;


  return 0;
}
