#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<typename T>
T fromString(const std::string& s) {
  std::istringstream is(s);
  T t;
  is >> t;
  return t;
}

template<typename T>
T toString(const T& t) {
  std::ostringstream s;
  s << t;
  return s.str();
}


template <typename R, typename P>


int main(void) {
  int i = 1234;
  cout << "i == \"" << toString(i)  << "\"" << endl;
  float x = 567.89;
  cout << "x= " << toString(x) << endl;
  complex<float> c(1.0, 2.0);
  cout << "c= " << toString(c) << endl;
  cout << endl;

  return 0;
}
