#include <iostream>
#include <cstddef>
using namespace std;

template<class T>
class Array {
  enum {INIT = 10};
  T* data;
  size_t capacity;
  size_t count;
public:
  Array() {
    count = 0;
    data = new T[capacity = INIT];
  }

  ~Array() {
    delete []data;
  }

  void push_back(const T& t) {
    if (count == capacity) {
      size_t newCap = 2 * capacity;
      T* newData = new T[capacity = newCap];
      for (size_t i = 0; i < capacity; i++) {
        newData[i] = data[i];
      }

      delete []data;
      data = newData;
      capacity = newCap;
    }

    data[count++] = t;
  }


  void pop_back() {
    if (count > 0) {
      --count;

    }
  }


  T* begin() {
    return data;
  }

  T* end() {
    return data + count;
  }
};


template<class T, template<class> class seq>




template<class T, template<class> class Seq>

class Container {
  Seq<T> seq;
public:
  void append(const T& t) {
    seq.push_back(t);
  }

  T* begin() {
    return seq.begin();
  }

  T* end() {
    return seq.end();
  }
};


template<template<class> class Seq>

class Container {



}





int main(void) {
  Container<int, Array> container;
  container.append(1);
  container.append(3);
  container.append(5);
  container.append(7);

  int* p = container.begin();
  while (p != container.end()) {
    cout << *p++ << endl;
  }

  return 0;
}

