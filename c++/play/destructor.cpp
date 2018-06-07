#include <iostream>
using namespace std;

class Animal {
public:
  Animal() {
    cout << "Animal constructed" << endl;
  }

  virtual ~Animal() {
    cout << "Animal destructed" << endl;
  }
};


class People : public Animal {
public:
  People() {
    cout << "People constructed" << endl;
  }

  ~People() {
    cout << "People destructed" << endl;
  }
};


int main(void) {

  Animal *p = new People();
  delete p; 

  return 0;
}
