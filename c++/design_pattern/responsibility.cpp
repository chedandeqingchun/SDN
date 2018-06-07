#include <iostream>
using namespace std;

class father {
public:
  father() {

  }

  virtual ~father() {
    cout << "delete father memory" << endl; 
  }
  virtual void say() {
    cout << "delete father memory" << endl;
  }
};

class son :public father {
public:
  virtual void say() {
    cout << "i am son" << endl;
  }

  virtual ~son() {
    cout << "delete son memory" << endl;
  }

};


int main(void) {
  father& ptr = *(new son());
  ptr.say();
  delete &ptr;

  return 0;
}
