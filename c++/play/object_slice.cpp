#include <iostream>
#include <string>
using namespace std;

class ZooAnimal {

public:
  string name;
  ZooAnimal(string na):name(na) {
    cout << "constructure zoo animal" << endl;
  }
  virtual ~ZooAnimal() {
    cout << "deconstruct zoo animal" << endl;
  }

  virtual void animate() {
    cout << "zooanimal animate" << endl;
  }

  virtual void draw() {
    cout << "zooanimal draw " << name << endl;
  }
};


class Bear : protected ZooAnimal {
public:
  Bear(string na) : ZooAnimal(na) {
    cout << "constructure Bear animal" << endl;
  }

  void animate() {
    cout << "Bear animate" << endl;
  }

  void draw() {
    cout << "Bear draw " << ZooAnimal::name << endl;
  }
};



int main(void) {

  ZooAnimal zoo("zoo");
  Bear bear("bear");

  zoo.draw();
  bear.draw();
  zoo = bear;
  zoo.draw();

  return 0;
}
