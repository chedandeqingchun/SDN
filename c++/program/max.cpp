#include <iostream>
using namespace std;

int max(int a, int b) {
  int value[2] = {a, b};

  return value[int(b > a)];
}


int main(void) {
  int a = 9, b = 5;

  cout << max(a, b);

  return 0;
}
