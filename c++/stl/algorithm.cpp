#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


template<class T>

struct find_spec : binary_function<T, T, bool> {
  bool operator() (const T& x, const T& y) {
    if (1 == abs(x - y)) {
      return true;
    }
    return false;

  }
};


int main(void) {

  int ia[] = {0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8};
  vector<int> iv(ia, ia + (sizeof(ia) / sizeof(int)));

  //cout << *adjacent_find(iv.begin(), iv.end()) << endl; 
  cout << *adjacent_find(iv.begin(), iv.end(), find_spec<int>()) << endl; 
  return 0;
}
