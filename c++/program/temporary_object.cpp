#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class print {
public:
  void operator() (const T& ele) {
    cout << ele << ' ';
  }
};

int main(void) {
  int ia[6] = {0, 1, 2, 3, 4, 5};
  vector<int> iv(ia, ia + 6);

  for_each(iv.begin(), iv.end(), print<int>());
  return 0;
}
