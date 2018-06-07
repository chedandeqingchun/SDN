#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

template<class T, class Compare>
class PQV : public vector<T> {
  Compare comp;
  bool sorted;

  void assureHeap() {
    if (sorted) {
      make_heap(this->begin(), this->end(), comp);
      sorted = false;
    }
  }

public:
  PQV(Compare compare = Compare()) : comp(compare) {
    make_heap(this->begin(), this->end(), comp);
    sorted = false;
  }

  const T& top() {
    assureHeap();
    return this->front(); 
  }

  void push(const T& ele) {
    assureHeap();
    this->push_back(ele); 
    push_heap(this->begin(), this->end(), comp);
  }

  void pop() {
    assureHeap();
    pop_heap(this->begin(), this->end(), comp);
    this->pop_back();
  }

  void sort() {
    if (!sorted) {
      sort_heap(this->begin(), this->end(), comp);
      reverse(this->begin(), this->end());
      sorted = false;
    }
  }
};


int main(void) {
  PQV< int, less<int> > pqv;
  srand(time(0));

  for (int i = 0; i < 100; i++) {
    pqv.push(rand() % 25);
  }

  copy(pqv.begin(), pqv.end(), ostream_iterator<int>(cout, " "));

  cout << endl;
  cout << endl;
  cout << endl;
  pqv.sort();

  while(!pqv.empty()) {
    cout << pqv.top() << ' ';
    pqv.pop();
  }

  return 0;
}
