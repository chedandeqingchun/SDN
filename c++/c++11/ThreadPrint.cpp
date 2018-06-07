#include <iostream>
#include <thread>
using namespace std;


std::mutex m;
condition_variable cv;

void display(char ch) {
  for (int i = 0; i < 10; i++) {
    unique_lock<mutex> lk(m);
    while (id != flag) {
      cond.wait(lk);
    }
    cout << ch;
    flag = (flag + 1) % 3;
    cond.notify_all();
  }
}


int main(void) {

  std::thread A(display, 'A');
  std::thread B(display, 'B');
  std::thread C(display, 'C');

  A.join();
  B.join();
  C.join();
  
  return 0;
}
