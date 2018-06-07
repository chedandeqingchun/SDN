#include <iostream>
#include <ctime>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

int getClock() {
  //return time(0);
  return 1;
}

int main(void) {

  //list<clock_t> clo(5);

  //generate_n(clo.begin(), 5, getClock);

  list<clock_t> clo(5);
  generate(clo.begin(), clo.end(), getClock);


  clo.erase(clo.begin());


  copy(clo.begin(), clo.end(), ostream_iterator<clock_t>(cout, " "));
  return 0;
}
