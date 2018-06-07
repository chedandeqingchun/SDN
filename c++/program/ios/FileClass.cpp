#include "FileClass.h"
#include <cstdlib>
#include <cstdio>
using namespace std;


FileClass::FileClass(const char* fname, const char* mode) {
  if (f = fopen(fname, mode) == 0) {
    throw FileClassError("Error opening file");
  }
}

Fileclass::~FileClass() {
  fclose(f);
}

File* FileClass::fp() {
  return f;
}
