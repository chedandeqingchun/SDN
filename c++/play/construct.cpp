#include <iostream>
#include <mutex>
using namespace std;

//class father {
//public:
//  father() {
//    cout << "constructor" << endl;
//  }
//
//  ~father() {
//    cout << "deconstructor" << endl;
//  }
//
//};
//
//
//class Sinleton {
//private:
//  Sinleton() {}
//  static Sinleton instance;
//public:
//  static Sinleton& etInstance() {
//    return instance; 
//  }
//
//};
//
//Sinleton Sinleton::instance;

//class Singleton {
//private:
//  Singleton() {}
//  static Singleton* instance;
//public:
//  static Singleton* getInstance() {
//    if (instance == NULL) {
//      instance = new Singleton;
//    }
//  }
//};

std::atomic<T*> instance;
std::mutex m;

T& Singleton() {
  T* tmp = instance.load(std::memory_order_consume);
  if (nullptr == tmp) {
    std::unique_lock lock(m);
    tmp = instance.load(std::memory_order_relaxed);
    if (nullptr == tmp) {
      instance.store(new X(), std::memory_order_release);
    }

  }
  return *instance;
}


int main(void) {
  //Singleton& tt = Singleton::getInstance();
return 0;
}


