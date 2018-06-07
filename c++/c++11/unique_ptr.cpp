#include <iostream>
#include <memory>
using namespace std;

class B {
public:
  B() = default;
  ~B() = default;

  virtual void bar() {
    cout << "B::bar\n" << endl;
  }

};

class D : B {
public:
  D() {
    cout << "D constructor\n" << endl;
  }
  ~D() {
    cout << "D deconstructor\n" << endl;
  }
  virtual void bar() override {
    std::cout << "D::bar\n" << endl;
  }
};


int main(void) {
  std::unique_ptr<B> p = std::make_unique<D>();
  p->bar();
  return 0;
}
