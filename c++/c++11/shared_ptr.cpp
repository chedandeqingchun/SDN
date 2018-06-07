#include <iostream>
#include <memory>
using namespace std;

class Base {
public:
  Base() {
    cout << "base constructor\n" << endl;
  }

  virtual void sayHello() {
    cout << "base say hello\n"<< endl;
  }

  ~Base() {
    cout << "base destructor\n" << endl;
  }

};

class Derived : public Base {
public:  
  Derived() {
    cout << "Derived constructor\n" << endl;
  }

  virtual void sayHello() {
    cout << "derived say hello\n"<< endl;
  }
  ~Derived() {
    cout << "Derived destructor\n"<< endl;
  }
};


int main(void) {
  std::shared_ptr<Base> p = std::make_shared<Derived>();
  p->sayHello(); 
  return 0;
}
