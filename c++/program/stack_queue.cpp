#include <iostream>
#include <stack>
using namespace std;

class StQueue {
  private:
  stack<int> st1;
  stack<int> st2;
  int size;

  public:
  StQueue();
  ~StQueue();

  void Enqueue(int value);
  int Departqueue();
  bool IsEmpty();


  private:
  void _PushEle(int value);
  int _PopEle();
};


StQueue::StQueue() {
  this->size = 0; 
}

StQueue::~StQueue() {

}

bool StQueue::IsEmpty() {
  if (this->size == 0) {
    return true;
  }
  return false;
}


void StQueue::Enqueue(int value) {
  _PushEle(value);
}

int StQueue::Departqueue() {
  return _PopEle();
}

void StQueue::_PushEle(int value) {
  this->st1.push(value);
  this->size += 1;
}

int StQueue::_PopEle() {
  int value;  
  
  if (this->st2.empty()) {
    while (!this->st1.empty()) {
      this->st2.push(st1.top());
      this->st1.pop();
    }
  }

  value = st2.top();
  st2.pop();
  this->size -= 1;
  return value;
}


int main(void) {
  int value;

  StQueue queue;
  queue.Enqueue(5);
  queue.Enqueue(7);
  queue.Enqueue(3);
  queue.Enqueue(2);
  queue.Enqueue(4);
  queue.Enqueue(6);
  queue.Enqueue(1);


  while (!queue.IsEmpty()) {
    value = queue.Departqueue(); 
    cout << value << endl;
  }

  return 0;
}
