#include <iostream>
using namespace std;

int y;
int& r = y;
const int& q = 12;
int x = 0;
int& a = x;


void f(int&) {

}

void g(const int&) {

}

void increment(int * &i) {
  i++;
}



int main(void) {
  cout << "x = " << x << ", a = " << a << endl;
  a++;
  cout << "x = " << x << ", a = " << a << endl;
  cout << "q = " << q << endl;

  g(1);

  int *i = 0;
  cout << i << endl;
  increment(i);
  cout << i << endl;

  return 0;
}
