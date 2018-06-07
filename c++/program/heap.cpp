#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Sheap {
  vector<int> bucket;
  
  void make_sheap() {


  }

public:
  Sheap(const int* valueArray, int length) {
    copy(valueArray, valueArray + length, bucket.begin());
    make_sheap();
  }

  void push_sheap(int ele) {
    int holeIndex;

    bucket.push_back(ele);
    holeIndex = ele.size() - 1;

    while (holeIndex > 0 && vec[holeIndex] > vec[(holeIndex - 1) / 2]) {
      vec[holeIndex] = vec[(holeIndex - 1) / 2];
      holeIndex = (holeIndex - 1) / 2;
    }
    vec[holeIndex] = ele;
  }
 
  void pop_sheap() {


  }

  void sort_sheap() {

  }
};

int main(void) {


  return 0;
}
