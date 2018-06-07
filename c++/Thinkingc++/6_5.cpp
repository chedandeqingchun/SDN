#include <iostream>
using namespace std;

void swap(char *argv[], int start, int end) {
 char * temp = argv[start]; 
 argv[start] = argv[end];
 argv[end] = temp;
}

void display(char* argv[], int start, int end) {
  for (int index = start; index <= end; index++) {
    cout << argv[index] <<  " "; 
  }
  cout << endl;
}

void permutation(char *argv[], int start, int end) {
  if (start >= end) {
    display(argv, 1, end);
    return;
  }

  for (int i = start; i <= end; i++) {
    swap(argv, start, i); 
    permutation(argv, start + 1, end);    
    swap(argv, start, i);
  }
}

int main(int argc, char* argv[]) {

  if (argc < 2) {
    cout << "need arguments" << endl;
    return -1;
  }

  permutation(argv, 1, argc - 1);

  return 0;
}
