#include <iostream>
#include <vector>
using namespace std;

void swapEle(vector<int> &vec, int prev, int next) {

  if (prev >= 0 &&
      prev < next &&
      next < vec.size()) {

    vec[prev] ^= vec[next];
    vec[next] ^= vec[prev];
    vec[prev] ^= vec[next];
   }
}


int insertSort(vector<int> &vec) {
  int subIndex = -1;

  if (vec.size() < 1) {
    return -1; 
  }

  for (int index = 1; index < vec.size(); index++) {
    for (subIndex = index; subIndex >=1; subIndex--) {
      if (vec[subIndex] < vec[subIndex - 1]) {
        swapEle(vec, subIndex - 1, subIndex);
      } else {
        break;
      }
    }  
  } 
}

int main(void) {
  
  vector<int> ele;

  ele.push_back(5);
  ele.push_back(3);
  ele.push_back(1);
  ele.push_back(4);
  ele.push_back(2);
  ele.push_back(6);
  ele.push_back(8);

  insertSort(ele);

  for (vector<int>::iterator itr = ele.begin(); itr != ele.end(); itr++) {
    cout << *itr << endl;
  }

  return 0;
}
