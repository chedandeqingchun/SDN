#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


void merge(vector<int>& bucket, std::vector<int> &buf1, std::vector<int> &buf2) {

  std::vector<int> buf;

  std::vector<int>::iterator itr1 = buf1.begin();
  std::vector<int>::iterator itr2 = buf2.begin();

  while (itr1 != buf1.end() && itr2 != buf2.end()) {

    if (*itr1 <= *itr2) {
      buf.push_back(*itr1);
      itr1++;
    } else {
      buf.push_back(*itr2);
      itr2++;
    }
  }

  if (itr1 == buf1.end()) {
    if(itr2 != buf2.end()) {
      std::copy(itr2, buf2.end(), back_inserter(buf));
    }
  } else {
    std::copy(itr1, buf1.end(), back_inserter(buf));
  }

  bucket.swap(buf);
}

void Sort(std::vector<int> &buf) {

  if (buf.size() >= 2) {
    std::vector<int> buf1;
    std::vector<int> buf2;
    size_t len = buf.size();
    std::vector<int>::iterator itr = buf.begin();

    std::copy(buf.begin(), itr + (len / 2), back_inserter(buf1));  
    std::copy(itr + (len / 2), buf.end(), back_inserter(buf2));  
    Sort(buf1);
    Sort(buf2);
    merge(buf, buf1, buf2);
  }
}


int main(void) {

  std::vector<int> buf; 

  buf.push_back(7);
  buf.push_back(5);
  buf.push_back(1);
  buf.push_back(4);
  buf.push_back(2);
  buf.push_back(9);
  buf.push_back(3);
  buf.push_back(8);
  buf.push_back(5);

  Sort(buf);

  for (std::vector<int>::iterator itr = buf.begin(); itr != buf.end(); itr++) {
    std::cout << *itr << std::endl;
  }

  return 0;
}
