#include <iostream>
using namespace std;

class Singleton {
public:
  static Singleton *getInstance();
  static void destroyInstance();
  Singleton(const Singleton &instance);
  Singleton& operator=(const Singleton &instance);
  virtual ~Singleton();
private:
  Singleton();
private:
  static Singleton *instance;
};

Singleton* Singleton::instance = nullptr;

Singleton* Singleton::getInstance() {

  if (instance == nullptr) {
    instance = new Singleton();
  }

  return instance;
}

void Singleton::destroyInstance() {
  delete instance;
  instance = nullptr;
}

Singleton::Singleton() {
  cout << "constructor was called" << endl;
}

Singleton::~Singleton() {
  cout << "desconstructor was called" << endl;
}

Singleton::Singleton(const Singleton &instance) {
  cout << "copy constructor was called" << endl;
}

Singleton& Singleton::operator=(const Singleton &instance) {
  cout << "assign was called" << endl;
}


int main(void) {
  Singleton *instance1 = Singleton::getInstance();
  Singleton *instance2 = Singleton::getInstance();

  Singleton tt(*instance1);

  if (instance1 == instance2) {
    cout << "equal" << endl;
  } else {
    cout << "not equal" << endl;
  }

  Singleton::destroyInstance();

  return 0;
}
