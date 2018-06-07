#include <iostream>
using namespace std;


struct component{
  static int num1;
  char num2;
  int num3;

};


int main(void) {

  cout << sizeof(component) << endl;

  return 0;
}
