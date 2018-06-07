#include <iostream>
#include <memory>
#include <vector>
using namespace std;

template<class T, template<class U, class = allocator<U> > class Seq>
class Container {
private:
  Seq<T> seq;
public:
  void push_back(const T& ele) { 
    seq.push_back(ele);
  }

  typename Seq<T>::iterator begin() {
    return seq.begin();
  }

  typename Seq<T>::iterator end() {
    return seq.end();
  }
};




int main(void) {
  Container<int, vector> container;
  container.push_back(5);
  container.push_back(7);
  container.push_back(1);
  container.push_back(3);
  cout << *container.begin() << '\t' << *(container.end() - 1) << endl;

  return 0;
}
