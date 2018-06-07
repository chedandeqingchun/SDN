#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

inline void assure(const ifstream& in, const char* filename) {
  if (!in) {
    exit(1);
  }
}

inline void assure(const ofstream& out, const char* filename) {
  if (!out) {
    exit(1);
  }
}


int main(void) {

  {
    ifstream in("strfile");
    assure(in, "strfile");
    ofstream out("outfile");
    assure(out, "outfile");

    const int SZ = 100;
    char buf[SZ];

    while (in.get(buf, SZ)) {
      in.get();
      cout << buf << endl;    
    }

  }

  {
    ifstream in("strfile");
    assure(in, "strfile");
    ofstream out("outfile");
    assure(out, "outfile");

    const int SZ = 100;
    char buf[SZ];

    while (in.getline(buf, SZ)) {
      cout << buf << endl;
    }
  }



  return 0;
}
