#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


int main(void) {

  vector<int> vec = {1, -2, 3, 10, -4, 7, 2, -5};

  int max = 0, sum = 0; 


  for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
    sum += *itr;
    if (sum >= max) {
      max = sum;
    } else if (sum <= 0) {
      sum = 0;
    }
  } 

  cout << "maxValue: " << max << endl;

  return 0;
}
