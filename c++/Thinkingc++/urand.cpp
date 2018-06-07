#include <iostream>
#include <bitset>
#include <cstddef>
#include <cstdlib>
#include <ctime>
using namespace std;

template<size_t UpperBound> 
class Urand {
  bitset<UpperBound> used;
public:
  Urand() {
    srand(time(0));
  }

  size_t operator() ();

};

template<size_t UpperBound>
inline size_t Urand<UpperBound>::operator()() {
  if (used.count() == UpperBound) {
    used.reset();
    cout << endl;
  }

  size_t newval;

  while (used[newval = rand() % UpperBound] == true) {

  }

  used[newval] = true;
  return newval;
}


int main(void) {
  Urand<10> u;
  
  for (int i = 0; i < 20; i++) {
    cout << u() << " ";
  }

  cout << endl;

  return 0;
}
