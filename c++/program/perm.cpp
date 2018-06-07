#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum = 0;

void inline swap(int &src, int &dst) {
  int m;

  m = src;
  src = dst;
  dst = m;
}

void perm(vector<int> &list, int left, int right) {
  int i = 0;

  if (left >= right) {
    for (i = 0; i < right; i++) {
      cout << list[i];
    }
    cout << endl;
    sum++;
  } else {
    for (i = left; i < right; i++) {
      swap(list[left], list[i]);
      perm(list, left + 1, right);
      swap(list[left], list[i]);
   }
  }
}

void display(vector<int> list) {
  int index;

  for (index = 0; index < list.size(); index++) {
      cout << list[index];
  }
  
  sum++;
  cout << endl;
}

void reverse(vector<int> &list, int start, int end)  {

  while (start <= end) {
      swap(list[start], list[end]);
      start++;
      end--;
  }
}

void permNotRecursive(vector<int> &list) {
  int left, right, position, minele;

  sort(list.begin(), list.end());

  do {

    display(list);

    left = right = list.size() - 1; 

    while (left > 0 && list[left - 1] > list[left]) {
      left--;
    }

    right = left;
    position = left - 1;

    if (left == 0) {
      break;
    }

    while (right < list.size() &&  list[right] > list[position]) {
      right++;
    }

    swap(list[right - 1], list[position]);

    //minele = list[left];

   // while (right < list.size()) {
   //   if (list[right] > list[position] && list[right] < minele) {
   //     minele = list[right];
   //     left = right;
   //   }
   //   right++;
   // }

    //swap(list[left], list[position]);
    reverse(list, position + 1, list.size() - 1);

 } while(true);
}


int main(void) {
  vector<int> list; 
  
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);

  //perm(list, 0, list.size());
  permNotRecursive(list);
  cout << sum << endl;

  return 0;
}
