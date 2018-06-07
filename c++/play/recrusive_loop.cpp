#include <iostream>
#include <vector>
using namespace std;

void traverse(vector<int> vec, int start) {
  size_t len = vec.size();

  if (start >= len) {
    return;
  }

  cout << vec[start] << endl;
  traverse(vec, start + 1);
}


int main(void) {


  vector<int> vt;

  vt.push_back(1);
  vt.push_back(4);
  vt.push_back(5);
  vt.push_back(7);
  vt.push_back(6);
  vt.push_back(2);

  traverse(vt, 0);

  return 0;
} 
