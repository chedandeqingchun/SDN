#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main(void) {
  vector<int> vec;
  vector<int> bucket;
  int ele;
  fstream in("input");
  while (in >> ele) {
    vec.push_back(ele);
    cout << ele << endl;
  }

  for (int i = 0; i < 3; i++) {
    bucket.push_back(vec[i]);
  }

  make_heap(bucket.begin(), bucket.end(), less<int>());

  for (int j = 3; j < vec.size(); j++) {
    if (vec[j] > bucket.front()) {
      pop_heap(bucket.begin(), bucket.end(), less<int>()); bucket.pop_back();
      bucket.push_back(vec[j]), push_heap(bucket.begin(), bucket.end(), less<int>());
    }
  }
  copy(bucket.begin(), bucket.end(), ostream_iterator<int>(cout, " "));
  return 0;
}
