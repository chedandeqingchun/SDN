#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <set>

int main(void) {

  std::set<std::string> buf;

  buf.insert("ab");
  buf.insert("cd");
  buf.insert("ef");
  buf.insert("gh");

  std::copy(buf.begin(), buf.end(), std::ostream_iterator<std::string>(std::cout, " "));

  return 0;
}
