#include <iostream>
using namespace std;

template <typename T>
void numSwap(T& lhs, T& rhs) {
  T temp;
  temp = lhs;
  lhs = rhs;
  rhs = temp;
}

template <class T>
class Calculator {
public:
  T op1, op2;
public:
  Calculator(T a, T b) {
    op1 = a;
    op2 = b;
  }

  T add() {
    return op1 + op2;
  }
};



int main(void) {

  int a = 5;
  int b = 6;
  char ch1 = 'a';
  char ch2 = 'b';
  numSwap(a, b);
  cout << a << endl;
  cout << b << endl;
  numSwap(ch1, ch2);
  cout << ch1 << endl;
  cout << ch2 << endl;

  Calculator<int> cal(4, 5);
  cout << cal.add() << endl;


  return 0;
}
