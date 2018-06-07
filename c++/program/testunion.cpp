#include <iostream>
using namespace std;

union obj{
  union obj* free_list_link;
  char client_data[1];
};

int main(void) {
  cout << sizeof(obj) << endl;;

  return 0;
}
