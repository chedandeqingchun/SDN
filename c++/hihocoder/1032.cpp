#include <iostream>
#include <cstring>
#include <string>
using namespace std;


int main(void) {

  string orign = "abaaba";
  string dest = "";
  vector<int> p;
  int max = 0, id = 0;


  for(string::iterator it = orign.begin(); it != orign.end(); it++) {
    dest += "#";
    dest += *it;
  }

  for (i = 0; i < dest.size(); i++) {
    int loc = max > i ? min(p[2 * id - i], max - i) : 1; 
    p.push_back(loc);

    while (dest[i + p[i]] == dest[i - p[i]]) {
      p[i]++;
    }

    if (i + p[i] > max) {
      max = i + p[i];
      id = i;
    }
  }

  return 0;
}
