#include <stdio.h>

#define MaxCount 3000
#define SHIFT 5
#define MASK 0x1f

int bitmap[1 + MaxCount >> SHIFT];

void setbit(int n) {
  bitmap[n >> SHIFT] |= (1 << (n & 0x1f));
}

int getbit(int n) {
  return bitmap[n >> SHIFT] & (1 << (n & MASK));
}

void clearbit(int n) {
  bitmap[n >> SHIFT] &= ~(1 << (n & 0x1f));
}

int main(void) {
  int n, index;

  for (index = 1; index <= MaxCount; index++) {
    clearbit(index);
  }

  while (scanf("%d", &n), n != -1) {
    setbit(n);
  }

  for (index = 1; index <= MaxCount; index++) {
    if (getbit(index)) {
      printf("%d\n", index);
    }
  }
  return 0;
}
