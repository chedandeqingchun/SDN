#include <iostream>
#include <vector>
#include <map>
using namespace std;

class CSort {
  public:
  CSort();
  ~CSort();
  void  RadixSort();
  void PushEle(int num);
  int PopEle();
  void Display();


  private:
    vector<int> ele;
    void _PushEle(int num);
    int _PopEle();
    int _MaxBit();
};


CSort::CSort() {

}


CSort::~CSort() {

}

void CSort::Display() {
  for (vector<int>::iterator iter = this->ele.begin(); iter != this->ele.end(); ++iter) {
    cout << " "  << *iter << " ";
  }
}


void CSort::PushEle(int num) {
  this->_PushEle(num);
}

int CSort::PopEle() {
  return this->_PopEle();
}


void CSort::_PushEle(int num) {
    this->ele.push_back(num);
}

int CSort::_PopEle() {
    int eleValue;
    eleValue = this->ele.front();
    this->ele.pop_back();
    return eleValue;
}

int CSort::_MaxBit() {
  int max = 1;
  int base = 10;

  for (int index = 0; index < this->ele.size(); index++) {
    while (this->ele[index] >= base) {
        base*= 10;
        max++;
    }
  }
  return max;
}

void CSort::RadixSort() {
  int length, radix = 1;
  int count[10];
  int *store = new int[this->ele.size()];

  length = _MaxBit();

  for (int index = 0; index < length; index++) {/* total sort number */
    for (int c_index = 0; c_index < 10; c_index++) {/* initial the bucket array */
      count[c_index] = 0;
    }

    for (int e_index = 0; e_index < this->ele.size(); e_index++) { /* assigned the element */
      count[(this->ele[e_index] / radix) % 10] += 1;
    }

    for (int p_index = 1; p_index < 10; p_index++) {/* receive position */
      count[p_index] = count[p_index] + count[p_index - 1];
    }

    for (int r_index = this->ele.size() - 1; r_index >= 0; r_index--) {/* receive element */
      store[count[(this->ele[r_index] / radix) % 10] - 1] = this->ele[r_index];
      cout << count[(this->ele[r_index] / radix) % 10] - 1 << endl;
      count[(this->ele[r_index] / radix) % 10] -= 1;
    }

    cout << endl;

    for (int s_index = 0; s_index < this->ele.size(); s_index++) {
      this->ele[s_index] = store[s_index];
    }

    radix *= 10;
  }

  delete store;
}

int main(void) {
  CSort bucket;
   
  bucket.PushEle(5);
  bucket.PushEle(7);
  bucket.PushEle(13);
  bucket.PushEle(2);
  bucket.PushEle(115);
  bucket.PushEle(3);
  bucket.PushEle(8);
  bucket.PushEle(25);
  bucket.PushEle(7);
  bucket.PushEle(0);
  bucket.RadixSort();
  bucket.Display();
  return 0;
}
