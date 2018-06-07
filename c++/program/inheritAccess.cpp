#include <iostream>
using namespace std;

class Animal {
public:
  int skin;

};

class People : public Animal {
public:
  int age;
  People(int s) {
    this->skin = s;
  }
   
  int getSkin() {
    return this->skin;
  }
};

int main(void) {

  People ele(5);
  cout << ele.getSkin() << endl;;
  return 0;
}
