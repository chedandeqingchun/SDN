#include <iostream>
#include <vector>
using namespace std;


int isort(vector<int> &vec, int start, int length) {

  for (int index = start + 1; index < vec.size() && length > 1; index++, length--) {
    int subIndex = index;
    while (subIndex > start) {
      if (vec[subIndex] < vec[subIndex - 1]) {
        vec[subIndex - 1] ^= vec[subIndex];
        vec[subIndex] ^= vec[subIndex - 1];
        vec[subIndex - 1] ^= vec[subIndex];
      } 
      subIndex--;
    }
  }
}


int shellSort(vector<int> &vec) {

  int len = -1, start;

  if (vec.size() < 1) {
    return -1;
  }

  len = vec.size() / 2;


  while (len >= 1) {
    start = 0;

    while (start < len) {
      isort(vec, start, len);
      start = start + len;
    }

    len /= 2;
  }

  return -1;
}


int main(void) {
  vector<int> vec;

  vec.push_back(1);
  vec.push_back(10);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(15);
  vec.push_back(7);
  vec.push_back(2);

  shellSort(vec);

  for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
    cout << *itr << endl;
  }

  return 0;
}
