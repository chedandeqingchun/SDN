#include <iostream>
using namespace std;

class Animal {
public:
  void setAge() {
    cout << "set age" << endl;
  }
  void setHeight() {
    cout << "set height" << endl;
  }

  static void setSex() {
    cout << "set sex" << endl;
  }
};

int main(void) {

  Animal animal; 

  void (Animal::*setAge)() = &Animal::setAge;
  void (Animal::*setHeight)() = &Animal::setHeight;
  void (*setSex)() = &Animal::setSex;


  (animal.*setAge)();
  setSex();
  return 0;
}
