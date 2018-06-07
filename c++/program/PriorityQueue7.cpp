#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iterator>
using namespace std;

template<class T, class Compare>
class PQV {
  vector<T> v;
  Compare cmp;

public:
  PQV(Compare compare = Compare()) : cmp(compare) {
  }

  void push(const T& element) {
    v.push_back(element);
    push_heap(v.begin(), v.end(), cmp);
    
  }
 
  void pop() {
    pop_heap(v.begin(), v.end(), cmp);
    v.pop_back();
  }

  const T& top() const{
    return v.front();
  }

  bool empty() const {
    return v.empty();
  }

  int size() const {
    return v.size();
  }

  typedef vector<T> TVec;

  TVec getVector() {
    TVec r(v.begin(), v.end());
    sort_heap(r.begin(), r.end(), cmp);
    return r; 
  }
};


int main(void) {

  PQV<int, less<int> > pqi;
  srand(time(0));

  for (int i = 0; i < 100; i++) {
    pqi.push(rand() % 25);
  }

  const vector<int>& v = pqi.getVector();

  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

  cout << endl << endl << endl;


  while (!pqi.empty()) {
    cout << pqi.top() << " ";
    pqi.pop();
  }

  return 0;
}
