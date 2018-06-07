#include <iostream>
#include <memory>
using namespace std;

class TraceHeap {
  int i;
public:
  static void* operator new(size_t size) {
    void* p = ::operator new(size);
    cout << "Allocating TraceHeap object on the heap" << p << endl;
    return p;
  }

  static void operator delete(void* p) {
    cout << "Deleting TraceHeap object at address" << p << endl;
    ::operator delete(p);
  }

  TraceHeap(int i) : i(i) {

  }

  int getVal() const {
    return i;
  }
};

int main(void) {
  auto_ptr<TraceHeap> pMyObject(new TraceHeap(5));
  cout << pMyObject->getVal() << endl;

  unique_ptr<int> up1(new int(11));
  unique_ptr<int> up2 = up1;
  
  return 0;
}
