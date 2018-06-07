#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int getMax(vector<int>& nums){
  if (nums.size() <= 0) {
    return -1;
  }

  int max = nums[0];

  for (int index = 1; index < nums.size(); index++) {
    if (nums[index] > max) {
        max = nums[index];
    }
  }
  
  return max;
}

void countSort(vector<int>& nums, int exp) {
  if (nums.size() <= 0) {
    return;
  }

  int keys[10] = {0};
  int *output = new int[nums.size()];

  for (int index = nums.size() - 1; index >= 0; index--) {
    keys[(nums[index] / exp) % 10]++;
  }

  for (int count = 1; count < 10; count++) {
    keys[count] += keys[count - 1];
  }

  for (int i = nums.size() - 1; i >= 0; i--) {
    output[keys[(nums[i] / exp) % 10] - 1] = nums[i];
    keys[(nums[i] / exp) % 10]--;
  }

  delete output;
}

void radixSort(vector<int>& nums) {
  int m = getMax(nums);

  if (m <= 0) {
    return;
  }

  for (int exp = 1; (m / exp) > 0; exp *= 10) {
    countSort(nums, exp);
  }
}

int main(void) {
  vector<int> nums;
  nums.push_back(18);
  nums.push_back(8);
  nums.push_back(27);
  nums.push_back(5);
  nums.push_back(3);
  radixSort(nums);
  copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}
