#include <iostream>
#include <vector>
using namespace std;

class Security {
  protected:
    enum {BASEID = 0};
  public:
    virtual ~Security() {} 
    virtual bool isA(int id) {
      return (id == BASEID);
    }
};

class Stock : public Security {
  typedef Security Super;
  protected:
  enum {OFFSET = 1, TYPEID = BASEID + OFFSET};
  public:
  bool isA(int id) {
    return id == TYPEID || Super::isA(id);
  }

  static Stock* dynacast(Security* s) {
    return (s->isA(TYPEID)) ? static_cast<Stock*>(s) : 0 ;
  }
};

int 
main(void) {
  vector<Security*> portfolio;
  portfolio.push_back(new Stock);
}

