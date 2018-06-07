#include <iostream>
using namespace std;

#define Posi(T) ListNode<T>*

template <class T>
class ListNode {
public:
  T data;
  Posi(T) pred;
  Posi(T) succ;
  ListNode() {}
  ~ListNode() {}
  Posi(T) insertAsPred(T const& e);
  Posi(T) insertAsSucc(T const& e);

protected:

};

template <class T>
class List {
private:
  int _size;
  Posi(T) header;
  Posi(T) trailer;

public:
  List() {}
  virtual ~List() {}
  int size() const {return _size;}

protected:

};

int main(void) {

  return 0;
}
