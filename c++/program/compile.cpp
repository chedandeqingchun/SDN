#include <iostream>
#include <string>
using namespace std;

class Animal {
  string animalName;
public:
  Animal(const string name) : animalName(name) {
  
  }

  virtual ~Animal() {

  }

  string& getName() {
    return this->animalName;
  }
};



int main(void) {
  char a = 'm', b = 'c';

  double h = 2.0, s = 3.0;
  cout << sizeof(a + b) << endl;
  cout << sizeof(h + s) << endl;

  Animal zebra("heihei");

  string& name = zebra.getName();
  cout << name << endl;

  name += "haha";

  string& lastName = zebra.getName();
  cout << lastName << endl;

  return 0;
}
