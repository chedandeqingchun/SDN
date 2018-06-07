#include <iostream>
using namespace std;

class Animal {
public:
  virtual void run();  
};

void Animal::run() {

  cout << "Animal run" << endl;
}

class People:public Animal {
public:
  virtual void run();
  void say();
};


void People::run() {
  cout << "people run" << endl;
}

void People::say() {
  cout << "people say" << endl;
}


int main(void) {
  Animal *tt = new People(); 
  return 0;
}
