#include <iostream>
#include <string>
using namespace std;

class Dog {
  string nm;
  int refcount;

  Dog(const string& name) : nm(name), refcount(1) {
    cout << "Creating Dog: " << *this << endl;
  }

  Dog& operator = (const Dog& rv);

public:

  static Dog* make(const string& name) {
    return new Dog(name);
  }

  Dog(const Dog& d) : nm(d.nm + " copy"), refcount(1) {
    cout << "Dog copy-constructor" << * this << endl;
  }

  ~Dog() {
    cout << "Deleting dog:" << *this << endl;
  }

 
  void attach() {
    ++refcount;
    cout << "Attached log:" << *this << endl;
  }

  void detach() {
    cout << "Detaching log:" << *this << endl;

    if (--refcount == 0) {
      delete this;
    }
  }


  Dog* unalias() {
    cout << "unaliasing Dog: " << *this << endl;
    
    if (refcount == 1) {
      return this;
    }

    --refcount;

    return new Dog(*this);
  }


 void rename(const string& newName) {
    nm = newName;
    cout << "Dog renamed to: "<< *this << endl;
  }

  friend ostream& operator<<(ostream& os, const Dog& d) {
    return os << "[" << d.nm << "]";
  }
};

class DogHouse {
  Dog *p;
  string houseName;

public:
  DogHouse(Dog* dog, const string& house) : p(dog), houseName(house) {
    cout << "Creating DogHouse: " << *this << endl;
  }

  DogHouse(const DogHouse& dh) : p(new Dog(dh.p, "copy constructed")), houseName(dh.houseName + "copy constructed") {

  }

  DogHouse& operator = (const DogHouse& dh) {
    if (&dh != this) {
      p = new Dog(dh.p, "assigned");
      houseName = dh.houseName + " assigned";

    }
    return *this;
  }

  void renameHouse(const string& newName) {
    houseName = newName;
  }


  Dog* getDog() const {
    return p;
  }


  ~DogHouse() {
    delete p;
  }


  friend ostream& operator << (ostream& os, const DogHouse& dh) {
    return os << "[" << dh.houseName << "] contains" << *dh.p; 
  }

};


int main(void) {
  DogHouse fidos(new Dog("Fido"), "FidoHouse");
  cout << fidos << endl;

  DogHouse  fidos2 = fidos;
  cout << fidos2 << endl;

  fidos2.getDog()->rename("spot");
  fidos2.renameHouse("SpotHouse");
  cout << fidos2 << endl;
  fidos = fidos2;
  cout << fidos << endl;
  fidos.getDog()->rename("max");
  fidos2.renameHouse("MaxHouse");



  return 0;
}
