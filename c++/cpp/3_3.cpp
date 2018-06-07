#include <iostream>
#include <string>
using namespace std;

inline string lowerCase(const string &s) {
  string lower(s);

  for (size_t i = 0; i < s.length(); i++) {
    lower[i] = tolower(lower[i]);
  }

  return lower;
}


inline string upperCase(const string &s) {
  string upper(s);

  for (size_t i = 0; i < s.length(); i++) {
    upper[i] = toupper(upper[i]);
  }

  return upper;
}


inline string strip(const string &s) {
  string str(s);
  size_t i = 0;

  while (i < str.length()) {
    if (str[i] > 'a' && str[i] < 'z' || str[i] > 'A' && str[i] < 'Z') {
      i++;
    } else {
      str.erase(i, 1);
    }
  }
  return str;
}


inline string reverse(const string &s) {
  string str(s);
  char swap;
  size_t start = 0, end = s.length() - 1;

  while (start < end) {
    swap = str[start]; 
    str[start] = str[end];
    str[end] = swap;
    start++;
    end--;
  }
  return str;
}


int main(void) {
  string initialStr("Able was I, ere I saw Elba.");
  string reverseStr;

  initialStr = strip(initialStr); 
  cout << initialStr << endl;

  initialStr = lowerCase(initialStr);
  cout << initialStr << endl;

  reverseStr = reverse(initialStr);
  cout << reverseStr << endl;

  if (initialStr.compare(reverseStr) == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 1;
}
