#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
void eleswap(int &fir, int& sec) {
  int temp = fir;
  fir = sec;
  sec = temp;
}


template<typename T>
class convert {
  string operator()(T& ele) {
    return to_string(ele);
  }
};


void arrange(vector<int>& vec, int start) {

  if (start >= vec.size()) {
    vector<string> vecStr;
    transform(vec.begin(), vec.end(), back_inserter(vecStr.begin()), convert<int>());
    copy(vecStr.begin(), vecStr.end(), ostream_iterator<string>(cout, " "));
   
    cout << endl;
  }

  for (int i = start; i < vec.size(); i++) {
    eleswap(vec[start], vec[i]);
    arrange(vec, start + 1);
    eleswap(vec[start], vec[i]);
  }
}

int main(void) {
  
  vector<int> vec = {3, 32, 321};  
  arrange(vec, 0);
  return 0;
}
