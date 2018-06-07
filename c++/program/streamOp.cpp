#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

const ifstream& operator+(ifstream& ifs, int num) {
  ifs.seekg(num, ios::beg);
}


int main(void) {
  ifstream in("strin", ios::in);

  if (!in) {
    exit(1);
  }

  cout << in.rdbuf() << endl;
  in.seekg(0, ios::beg);
  cout << (in + 5).rdbuf() << endl;
  return 0;
}
