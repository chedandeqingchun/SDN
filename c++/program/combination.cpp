#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

void combination(string& str, int len, int start, vector<char>& res) {
  if (len <= 0) {
    copy(res.begin(), res.end(), ostream_iterator<char>(cout, ""));
    cout << endl;
    return;
  } else {
    if (str.size() - start >= len) {
      res.push_back(str[start]);
      combination(str, len - 1, start + 1, res);
      res.pop_back();
      combination(str, len, start + 1, res);
    }
  }
}

int main(int argc, char* argv[]) {
  
  if (argc < 2) {
    cout << "need arguments" << endl;
    return -1;
  }

  string str(argv[1]);

  sort(str.begin(), str.end());

  string::iterator it;
  it = std::unique(str.begin(), str.end());
  str.resize(distance(str.begin(), it));

  vector<char> res;

  for (int i = 1; i <= str.size(); i++) {
    combination(str, i, 0, res);  
  }

  return 0;
}
