#include <stdexcept>
#include <iostream>
using namespace std;


class MyError: public runtime_error {
public:
  MyError(const string& msg = "") : runtime_error(msg){

  }
};

int main(void) {

  try {
    throw MyError("error message");
  } catch(MyError& e) {
    cout << e.what() << endl;
  }

  return 0;
}
