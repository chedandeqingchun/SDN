#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;


int main(void) {


  list<int> li, bli;

  bli.push_back(5);
  bli.push_back(7);


  li.push_back(2);
  li.push_back(7);
  li.push_back(5);
  li.push_back(1);
  li.push_front(7);
  li.push_front(8);
  li.push_front(1);
  li.push_front(4);

  ostream_iterator<int> itr(cout,  " ");
  copy(li.begin(), li.end(), itr);
  cout << endl;

  std::back_insert_iterator<list<int> > back_it(bli);

  copy(li.begin(), li.end(), back_it);
  copy(bli.begin(), bli.end(), itr);
  cout << endl;

  bli.erase(bli.begin());
  copy(bli.begin(), bli.end(), itr);
  cout << endl;
  return 0;
}
