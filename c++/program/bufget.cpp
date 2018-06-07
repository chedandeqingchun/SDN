#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;


int main(void) {

  ifstream in("strbuf");

  if (!in) {
    exit(1);
  }

  //{
  //ostringstream ostr("stroutput");

  //if (!ostr) {
  //  exit(1);
  //}

  //ostr << in.rdbuf();
  //}

  streambuf& sb = *in.rdbuf();

  while(!in.get(sb).eof()) {
    if (in.fail()) {
      in.clear();
    }

    char temp = char(in.get());

    if (temp >= 'a' || temp <= 'z') {
      temp = toupper(temp);
    }

    cout << temp;

  }

  return 0;
}
