#include <iostream>
using namespace std;


class Number {
  int i;
public:
  Number(int ii = 0) : i(ii) {
    cout << "constructed was called" << endl;
  }

  const Number&
  operator+(const Number& num) {
    this->i += num.i;
    return *this;
  }

  friend const Number
  operator-(const Number& n1, const Number& n2) {
    return Number(n1.i - n2.i);
  }
};

int main(void) {
  Number n1(45), n2(3);
  n1 + n2;
  n1 + 1;
  //1 + n1;
  n1 - n2;
  n1 -1;
  1 - n1;



  return 0;
}
