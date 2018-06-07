#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;



int main(void) {

  set<int> st1, st2;

  st1.insert(10);
  st1.insert(3);
  st1.insert(2);
  st1.insert(4);

  st2.insert(7);
  st2.insert(5);
  st2.insert(2);
  st2.insert(3);

  set_union(st1.begin(), st1.end(), st2.begin(), st2.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  set_intersection(st1.begin(), st1.end(), st2.begin(), st2.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  set_difference(st1.begin(), st1.end(), st2.begin(), st2.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  set_symmetric_difference(st1.begin(), st1.end(), st2.begin(), st2.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}
