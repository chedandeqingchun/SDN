#include <iostream>
using namespace std;

class NoVirtual {
  int a;
public:
  void x() const {};
  int i() const {return 1;}
};

class OneVirtual {
  int a;
public:
  virtual void x() const {};
  int i() const {return 1;}
};


class TwoVirtuals {
  int a;
public:
  virtual void x() const {};
  virtual int i() const {return 1;}
};



int main(void) {
  cout << "int: " << sizeof(int) << endl;
  cout << "NOVirtual: " << sizeof(NoVirtual) << endl;
  cout << "void*: " << sizeof(void *) << endl;
  cout << "one Virtual: " << sizeof(OneVirtual) << endl;
  cout << "two Virtuals: " << sizeof(TwoVirtuals) << endl;

  return 0;
}
