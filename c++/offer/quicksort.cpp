#include <vector>
#include <iterator>

void bucketSwap(std::vector<int> &bucket, int left, int right) {

  int temp;

  temp = bucket[left];
  bucket[left] = bucket[right];
  bucket[right] = temp;

}


void quicksort(std::vector<int> &bucket, int l, int r) {

  int left, right, privot;

  privot = l;
  left = l + 1;
  right = r;

  if (l >= r) {
    return;
  }

  while (1) {

    while (left <= right && bucket[left] < bucket[privot]) {
      left++;      
    }

    while (left <= right && bucket[right] > bucket[privot]) {
      right--;
    }

    if (left > right) {
      break;
    }

    bucketSwap(bucket, left, right);

  }

  bucketSwap(bucket, privot, right);

  quicksort(bucket, l, right - 1);
  quicksort(bucket, right + 1, r);
}

int main(void) {

  std::vector<int> bucket;

  bucket.push_back(7);
  bucket.push_back(5);
  bucket.push_back(1);
  bucket.push_back(4);
  bucket.push_back(2);
  bucket.push_back(6);
  bucket.push_back(3);

  quicksort(bucket, 0, bucket.size() - 1);


  for (std::vector<int>::iterator itr = bucket.begin(); itr != bucket.end(); itr++) {
    std::cout << *itr << std::endl;
  }

  return 0;
}
