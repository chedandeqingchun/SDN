#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <vector>
using namespace std;

template<class T>
class PQV : public priority_queue<T> {

public:
  typedef vector<T> TVec;
  TVec getVector() {
    TVec r(this->c.begin(), this->c.end());
    sort_heap(r.begin(), r.end(), this->comp);
    return r;
  }
};


int main(void) {
  PQV<int> pqi;
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
