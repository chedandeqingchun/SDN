#include <iostream>
using namespace std;


int main(void) {
  long * const ptr0 = new long[5];
  long ptr1[5];
  ptr0 = ptr1;
  ptr0[0] = 'a';
  ptr0[1] = 'b';
  ptr0[2] = 'c';
  ptr0[3] = 'e';
  ptr0[4] = 'e';
  cout << *ptr0 << '\t' << *(ptr0 + 1) << '\t' << *(ptr0 + 2) << endl;

  return 0;
}
