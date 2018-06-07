#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(int argc, char*argv[]) {

  if (argc < 2) {
    cout << "need argument" << endl;
    return -1;
  } 

  string str(argv[1]);
  sort(str.begin(), str.end());


  do {
    cout << str << endl;
  } while (next_permutation(str.begin(), str.end()));


  return 0;
}

