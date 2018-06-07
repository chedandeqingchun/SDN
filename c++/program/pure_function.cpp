#include <iostream>
using namespace std;

class Animal {
public:
  virtual ~Animal() const =  0;
  virtual void showShape() const = 0; 
public:
  int _age;
};


class People:public Animal {

public:
  virtual ~People() {
    cout << "people destrctor" << endl;
  }

  virtual void showShape() {
    cout << "circle" << endl;
  }
};

inline void Animal::showShape() const {
  cout << "heihei" << endl;
}

inline Animal::~Animal() const {
  cout << "animal destructor" << endl;
}

int main(void) {

  Animal *ptr = new People();
  delete(ptr);

  return 0;
}
