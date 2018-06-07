#include <iostream>
using namespace std;

//template<class T, class Container = std::deque<T> >
//class queue {
//  explicit queue(const Container&);
//  explicit queue(Container&& = Container());
//  template<class Alloc> queue(const Alloc&); 
//  template<class Alloc> queue(const Container&, const Alloc&);
//  template<class Alloc> queue(Container&&, const Alloc&);
//  template<class Alloc> queue(queue&&, const Alloc&);
//
//  vois swap(queue& q);
//
//  bool empty() const;
//  size_type size() const;
//
//  T& front();
//  const T& front() const;
//  T& back();
//  const T& back() const;
//
//  void push(const T& x);
//  void push(T&& x);
//  template<class... Args> void emplace(Args&&.. args);
//};


class threadsafe_queue {
public:
  threadsafe_queue();
  threadsafe_queue(const threadsafe_queue&);
  threadsafe_queue& operator=(const threadsafe_queue&) = delete;

  void push();
  bool try_pop();
  std::shared_ptr<T> try_pop();

  void wait_and_pop(T& value);
  std::shared_ptr<T> wait_and_pop();

  bool empty() const;
};

int main(void) {


  return 0;
}
