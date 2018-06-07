#include <iostream>
#include <string>
#include <list>
using namespace std;

class Observer {
public:
  virtual void update() {

  }
};

class Product {
protected:
  const char*  product_name;
  int price;
  list<Observer*> observersCollect;

public:
 void addObserver(Observer *obj) {
   observersCollect.push_back(obj);
 }

 void setPrice(const int price) {
   this->price = price; 
   this->notifyObserver();
 }

 int getPrice() const {
   return this->price;
 }


 void notifyObserver() {
   for (list<Observer *>::iterator itr = observersCollect.begin(); itr != observersCollect.end(); itr++) {
     (*itr)->update();
   } 
 }
};

class Hat:public Product {
public:
  Hat(const char* name, int price) {
    this->product_name = name;
    this->price = price;
  }
};

class CorcrectA:public Observer {
public:
  virtual void update() {
    cout << "Observer A observered value changed\n" << endl;
  }
};

class CorcrectB:public Observer {
public:
  virtual void update() {
    cout << "Observer B observered value changed\n" << endl;
  }
};


int main(void) {

  Product *hat = new Hat("PlayBoyHat", 115);

  Observer *watch1 = new CorcrectA();
  Observer *watch2 = new CorcrectB();

  hat->addObserver(watch1); 
  hat->addObserver(watch2); 

  hat->setPrice(118);
  hat->setPrice(220);

  return 0;
}
