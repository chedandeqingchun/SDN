#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>







#define slices 4 

int main(void) {
  FILE* nums[slices];
  char path[10];
  char line[10];
  int numIndex = 0, value;
  std::ifstream in("matrix1");

  if (!in) {
    std::cout << "open matrix fail" << std::endl;
  }

  for (int i = 0; i < slices; i++) {
    memset(path, '\0', 10);
    sprintf(path, "./nums/%d", i);
    nums[i] = fopen(path, "w+");
  }

  while (in >> value) {
    memset(line, '\0', 10);
    sprintf(line, "%d   %d\n", numIndex / slices, value);
    if (!fwrite(line, sizeof(char), strlen(line), nums[numIndex % slices])) {
      std::cout << "wirte file fails" << std::endl;
    }
    numIndex++;
  }




  for (int j = 0; j < slices; j++) {
    fclose(nums[j]);
  }

  return 0;
}
