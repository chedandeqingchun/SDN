#include <stdio.h>
#include "exercise_const.h"

//const int a = 5;
//const int b = 6;
//const int c = a + b;
//char buf[c];


int main(void) {
  int a = 5;
  scanf("%d", &a);
  char temp[a];

  temp[6] = 5;
  printf("%d", temp[6]);

  return 0;
}
