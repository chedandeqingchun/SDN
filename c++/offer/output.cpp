#include<iostream>
#include <iterator>
#include <vector>


int main(void) {

  std::vector<char> buf;

  buf.push_back('m');
  buf.push_back('d');
  buf.push_back('k');
  buf.push_back('f');
  buf.push_back('s');


  std::copy(buf.begin(), buf.end(), std::ostream_iterator<char>(std::cout, "\t"));


  return 0;
}
