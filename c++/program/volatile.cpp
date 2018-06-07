#include<iostream>
using namespace std;

class Comm {
const volatile unsigned char byte;
volatile unsigned char flag;
enum {buffer_size = 100};
unsigned char buf[buffer_size];
int index;
public:
  Comm();
  void isr() volatile;
  char read(int index) volatile;
};


Comm::Comm():index(0), byte(0), flag(0) {

}


void Comm::isr() volatile {
  flag = 0;
  buf[index++] = byte;
  if (index > buffer_size) {
    index = 0;
  }
}

char Comm::read(int index) volatile {
  if (index < 0 || index > buffer_size) {
    return 0;
  }
  
  return buf[index];
}





int main(void) {
  volatile Comm port;
  port.isr();
  port.read(0);

  return 0;
}
