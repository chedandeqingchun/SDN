#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ofstream out("out");


class HowMany {
  static int objectCount;
public:
  HowMany() { objectCount++; }
  static void print(const string& msg = "") {
    if (msg.size() != 0) {
      out << msg << ": ";
      out << "objectCount = " << objectCount << endl;
    }
  }

  ~HowMany() {
    objectCount--;
    print("~HowMany()");
  }
};

class Male {
  int num;

public:
  Male(int value):num(value) {
    cout << "male constructor" << endl;
  }


  Male(Male& t) {
    cout << "male copy constructor" << endl;
  }

  Male& operator=(const Male& t) {
    cout << "operator copy constructor " << endl;
    return *this;
  }


  ~Male() {
    cout << "male deconstructor" << endl;
  }
};



int HowMany::objectCount = 0;

HowMany f(HowMany x) {
  x.print("x argument inside f()");
  return x;
}

int main(void) {
  //HowMany h;
  //HowMany::print("after construction of h");
  //HowMany h2 = f(h);
  //HowMany::print("after call to f()");

  Male tt(2);

  Male qq(5);

  qq = tt;

  return 0;
}
