#include <iostream>
#include <vector>
using namespace std;

void inline quswap(vector<int> &ele, int left, int right) {
  int temp;
  temp = ele[left];
  ele[left] = ele[right];
  ele[right] = temp;
}

void qusort0(vector<int> &ele, int l, int u) {
  int p = l;
  if (l >= u) {/* return */
    return;
  }

  for (int m = l + 1; m <=u; m++) {
    if (ele[m] < ele[l]) {
      quswap(ele, ++p, m);
    }
  }

  quswap(ele, l, p);
  /* partial left and right array */
  qusort0(ele, l, p - 1);
  qusort0(ele, p + 1, u);
}


void qusort1(vector<int> &ele, int l, int r) {
  int p = l;
  int left, right;

  if (l >= r) {/* return */
    return;
  }

  left = l + 1, right = r;

  while (1) {

    while (left <= right && ele[left] < ele[p]) {
      left++;
    }

    while (left <= right && ele[right] > ele[p]) {
      right--;
    }

    if (left > right) {
      break;

    }
    quswap(ele, left, right);
  }

  quswap(ele, right, p);
  
  qusort1(ele, l, right - 1);
  qusort1(ele, right + 1, r);
}


int main(void) {
  vector<int> ele;

  ele.push_back(1);
  ele.push_back(7);
  ele.push_back(2);
  ele.push_back(5);
  ele.push_back(3);
  ele.push_back(4);
  ele.push_back(8);

  qusort1(ele, 0, ele.size() - 1);

  for (vector<int>::iterator itr = ele.begin(); itr != ele.end(); itr++) {
    cout << *itr << endl;
  }

  return 0;
}
