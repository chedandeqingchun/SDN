#include <iostream>
#include "FileClass.h"
using namespace std;

int main(void) {
  try {
    FileClass f("FileClassTest");
    const int BSIZE = 100;
    char buf[BSIZE];
    while (fgets(buf, BSIZE, f.fp())) {
      fputs(buf, stdout);
    }
  } catch (FileClass::FileClassError& e) {
    cout << e.what() << endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
