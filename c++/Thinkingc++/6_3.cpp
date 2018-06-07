#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


template <typename T>
struct Sum {
  void operator() (T i) {
    static T sum = 0;
    sum += i;
    cout << sum << endl;
  }
};

int gen() {
  static int index = 0;
  index++;
  return index;
}


int main(void) {

  vector<int> vec(5);
  generate(vec.begin(), vec.end(), gen);

  Sum<int> sumobject;

  for_each(vec.begin(), vec.end(), sumobject);

  return 0;
}
