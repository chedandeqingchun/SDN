#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

int upper(int c, int d) {
  return toupper( 'a' + d - c);
}

int main(void) {
  string str1 = "abcdefg";
  string str2 = "hijklmn";
  string dst;
  dst.resize(str1.size() + str2.size());
  
  //transform(str1.begin(), str1.end(), dst.begin(), upper);

  transform(str1.begin(), str1.end(), str2.begin(), dst.begin(), upper);

  cout << dst << endl;
  return 0;
}
