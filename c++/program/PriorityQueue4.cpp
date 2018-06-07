#include <iostream>
#include <algorithm>
#include <queue>
#include <iterator>
using namespace std;


class PQI : public priority_queue<int> {
public:
  vector<int>& impl() {
    return c;
  }
};

int main(void) {
  PQI pqi;
  srand(time(0));

  for (int i = 0; i < 100; i++) {
    pqi.push(rand() % 25);
  }

  copy(pqi.impl().begin(), pqi.impl().end(), ostream_iterator<int>(cout, " "));

  cout << endl;

  while(!pqi.empty()) {
    cout << pqi.top() << ' ';
    pqi.pop();

  }


  return 0;
}
