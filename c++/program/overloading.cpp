#include <iostream>
using namespace std;


class Integer {
  int value;

public:
  Integer(int ii) : value(ii) {

  }

  friend Integer& operator+(Integer& num) {
    return num;
  }

  friend Integer operator-(Integer& num) {
    return Integer(-num.value);
  }

};


class Byte {
  unsigned char ch;
public:
  Byte(const char cc) : ch(cc) {

  } 

  Byte& operator=(const Byte& b) {
    return *this;
  }


  friend ostream& operator<<(ostream& os, const Byte& byte) {
    return os << byte.ch << endl;
  }

};


int main(void) {

  Byte a('m'), b('n');
  cout << a << b <<  endl;
  a = b;
  cout << a << endl;
  return 0;
}
