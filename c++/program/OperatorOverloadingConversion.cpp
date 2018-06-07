#include <iostream>
using namespace std;

class Three {
  int i;

public:
  Three(int ii = 0, int = 0) : i(ii) {
  }


};


class Four {
  int i;

public:
  Four(int ii) : i(ii) {

  }
	
         
  operator Three () const {
    return Three(i);
  }
};

void g(Three) {


}



int main(void) {
  Four four(1);
  g(four);

  return 0;
}
