#include <iostream>
#include <string>
using namespace std;

class Notification {
public:
  string _title;
  string _content;
  string _footer;

public:
  Notification(string title, string content, string footer): _title(title), _content(content), _footer(footer) {

  }
  Notification(const Notification &notifier) {
    _title = notifier._title;
    _content = notifier._content;
    _footer = notifier._footer;
  }
  virtual ~Notification() {

  }
  Notification* clone() {
    return new Notification(*this);
  }
};

class NotifySender {
public:
  void send(Notification &sender) {
    cout << sender._title << '\t' << sender._content << '\t' << sender._footer << endl;
  }
};


int main(void) {
  Notification msg("order information", "order success", "tech company");
  NotifySender sender;
  sender.send(msg);

  return 0;
}
