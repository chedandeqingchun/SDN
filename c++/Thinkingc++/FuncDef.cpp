#include <iostream>
using namespace std;

template<class T = int, size_t N = 100> 
class Stack {
  T data[N];
  size_t count;
public:
  void push(const T& t);
};


template<class T, size_t N>
void Stack<T, N>::push(const T& t) {
  cout << "push element" << endl;
}


template<class T>
T sum(T* b, T* e, T init = T()) {
  while (b != e) {
    init += *b++;
    return init;
  }
}

int main(void) {
  //const int s = 6;
  //Stack<> mystack;
  //mystack.push(s);

  int a[] = {1, 2, 3};

  int temp = int();
  temp += 5;
  cout << temp << endl;

  cout << sum(a, a + sizeof(a) / sizeof(a[0])) << endl;

  return 0;
}
