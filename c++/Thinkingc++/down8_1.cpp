#include <iostream>
#include <vector>
using namespace std;

class  Base {

public:
  ~Base();

};

class Derived : public Base {



};



int main(void) {

  vector<Base*> buf;


  return 0;
}

