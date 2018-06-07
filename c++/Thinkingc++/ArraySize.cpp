#include <iostream>
using namespace std;

template <size_t R, size_t C, typename T>

void init1(T a[R][C]) {
  for (size_t i = 0; i < R; i++) {
    for (size_t j = 0; j < C; j++) {
      a[i][j] = T();
    }
  }
}

template <size_t R, size_t C, size_t T>

void init2(T (&a)[R][C]) {
  for (size_t i = 0; i < R; i++) {
    for (size_t j = 0; j < C; j++) {
      a[i][j] = T();
    }
  }
}





int main(void) {
  int a[10][20];
  init1<10, 20>(a);
  init2(a);


  return 0;
}
