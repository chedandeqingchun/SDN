#include <cstdlib>
#include <ctime>
#include <iostream>
//#include <functional>
#include <queue>
using namespace std;



int main(void) {

  //priority_queue<int, vector<int>, greater<int> > pqi;//asc
  priority_queue<int, vector<int>, less<int> > pqi;//desc
  srand(time(0));

  for (int i = 0; i < 100; i++) {
    pqi.push(rand() % 25);
  }

  while (!pqi.empty()) {
    cout << pqi.top() << ' ';
    pqi.pop();
  }
  return 0;
}
