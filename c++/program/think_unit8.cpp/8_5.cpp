#include <iostream>
#include <ctime>
using namespace std;


int main(void) {

  //time_t tt;
  //struct tm *tmp;
  //char buf[64];

  //if (-1 == time(&tt)) {
  //  cout << "time fails\n"<< endl;
  //  return -1;
  //}
  //const time_t gg = tt;

  //tmp = localtime(&gg); 


  //if (strftime(buf, 64, "%r, %a %b %d, %Y", tmp) == 0) {
  //  cout << "str fails" << endl;
  //  return -1;
  //}

  //cout << buf << endl;

  //if (-1 == time(&tt)) {
  //  cout << "time fails\n" << endl;
  //  return -1;
  //}
  //gg == tt;
  //tmp = localtime(&gg); 


  //if (strftime(buf, 64, "%r, %a %b %d, %Y", tmp) == 0) {
  //  cout << "str fails" << endl;
  //  return -1;
  //}

  //cout << buf << endl;

  int a = 5;
  const int index = a;
  cout << index << endl;

  a = 6;
  index = a;
  cout << index << endl;

  return -1;
}
