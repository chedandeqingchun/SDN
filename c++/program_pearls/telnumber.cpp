#include <iostream>
#include <iterator>
#include <vector>

char *tel[] = {"oper", "", "abc", "def", "ghi", "jkl", "mnq", "prs", "tuv", "wxy"};


void 
combination(const char *cstr, std::vector<char>& buf) {
  char * str = (char*) cstr;

  if (str == NULL || *str == '\0') {
    std::copy(buf.begin(), buf.end(), std::ostream_iterator<char>(std::cout, ""));
    std::cout << std::endl;
    return;
  }

  if (*str == '#' || *str == '*' || *str == '1') {
    buf.push_back(' '); 
    combination(str + 1, buf);
    buf.pop_back();
  } else {
    for (char* code = tel[*str - '0'];
        *code != '\0';
        code++) {
        buf.push_back(*code);
        combination(str + 1, buf);
        buf.pop_back();
    }
 }

}

int main(void) {

  const char *str = "548*33*5464";
  std::vector<char> buf;

  combination(str, buf);
  return 0;
}
