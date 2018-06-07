#include <iostream>
using namespace std;

class Dummpy {
public:
  int a, b;
public:
  Dummpy(int x, int y) {
    a = x;
    b = y;
  }
};

class Addition {
public:
  int a, b;
  Addition(int x, int y) {
    a = x;
    b = y; 
  }

  void print(void) {
    cout << "addition print\n" << endl;
    cout << a << '\t' << b << endl;
  }

};


int main(void) {

  double x = 10.3;
  int y;

  y = int(x);
  cout << y << endl;
  y = (int)x;
  cout << y << endl;

  Dummpy *num = new Dummpy(3, 4);
  Addition * ad = reinterpret_cast<Addition*>(num); 
  ad->print();

  return 0;
}
