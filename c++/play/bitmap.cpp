#include <iostream>
#include <bitset>
using namespace std;


#define EOF -1

int main(void) {
  const int max = 1000;
  int n, i;

  bitset<max + 1>bit;

  while (cin >> n, n != EOF) {
    bit.set(n, 1);
  }


  for (i = 0; i <= max + 1; i++) {
    if (bit[i] == 1) {
      cout << i << endl;
    }
  }

  return 0;
}
