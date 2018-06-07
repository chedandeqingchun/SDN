#include <iostream>
#include <ifstream>
using namespace std;



int main(void) {

  ifstream in("stype");

  if (!in) {
    exit(1);
  }

  cout << in.readbuf();

  return 0;
}
