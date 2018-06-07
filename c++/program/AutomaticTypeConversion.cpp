#include <iostream>
using namespace std;

class Tiger {



};

class Lion {
public:
  explicit Lion(Tiger&) {

  }

  Lion() {

  }

};

void f(const Lion& lion) {


}




int main(void) {

  Tiger tiger;

  f(Lion(tiger));

  return 0;
}
