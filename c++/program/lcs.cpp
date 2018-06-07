#include <iostream>
using namespace std;

int lcs(const char *str1, int len1,  const char *str2, int len2) {
  int maxlen = 0;

  if (len1 == 0 || len2 == 0) {
    return maxlen;
  }

  if (str1[len1 - 1] == str2[len2 - 1]) {
    len1--, len2--, maxlen++;
    maxlen += lcs(str1, len1, str2, len2);
  } else {
    maxlen += max(lcs(str1, len1 - 1, str2, len2), lcs(str1, len1, str2, len2 - 1));
  } 
  return maxlen;
}

int main(void) {
  char str1[] = "acccce";
  char str2[] = "bccccd";

  cout << lcs(str1, 6, str2, 6) << endl;
  return 0;
}
