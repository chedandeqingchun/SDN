#include <iostream>
using namespace std;


class Msg {
public:
    Msg();
    virtual ~Msg();
    virtual void showMsg() = 0;
};


class MorningMsg:public Msg {
public:
    MorningMsg();
    ~MorningMsg();
    void showMsg();
}


class EveningMsg:public Msg {
public:
    EveningMsg();
    ~EveningMsg();
    void showMsg();
}


class NightMsg:public Msg {
public:
    NightMsg();
    ~NightMsg();
    void showMsg();
}


class Factory {
public:
    Factory();
    virtual ~Factory();
    virtual void Creator(int type) = 0;
}


class MorningFactory:public Factory {
public:
    MorningFactory();
    ~MorningFactory();
    void Creator();
}


class EveningFactory:public Factory {
public:
    EveningFactory();
    ~EveningFactory();
    void Creator();
}


class NightFactory:public Factory {
public:
    NightFactory();
    ~NightFactory();
    void Creator();
}


int main(void) {

  Factory period = new EveningFactory();
  EveningMsg msg = period.creator(); 
  msg.showMsg();


  return 0;
}
