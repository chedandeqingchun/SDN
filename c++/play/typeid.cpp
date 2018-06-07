#include <iostream>
#include <typeinfo>
using namespace std;

struct PolyBase {virtual ~PolyBase() {}};
struct PolyDer : PolyBase {PolyDer() {}};
struct NonPolyBase {};
struct NonPolyDer : NonPolyBase {NonPolyDer(int) {}};

int main(void) {
  const PolyDer pd;
  const PolyBase* ppb = &pd;
  cout << typeid(ppb).name() << endl;
  cout << typeid(*ppb).name() << endl;
  cout << (typeid(*ppb) == typeid(pd)) << endl;

  const NonPolyDer npd(1);
  const NonPolyBase* nppb = &npd;
  cout << typeid(nppb).name() << endl;
  cout << typeid(*nppb).name() << endl;
  cout << (typeid(*nppb) == typeid(npd)) << endl;

  int i;
  cout << typeid(i).name() << endl;

  return 0;
}
