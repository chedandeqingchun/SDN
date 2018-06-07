#include <iostream>
#include <queue>
using namespace std;


class ToDoItem {
  char primary;
  int secondary;
  string item;
public:
  ToDoItem(string td, char pri = 'a', int sec = 1) : item(td), primary(pri), secondary(sec) {

  }

  friend bool operator < (const ToDoItem& x, const ToDoItem& y) {
    if (x.primary > y.primary) {
      return true;
    }

    if (x.primary == y.primary) {
      if (x.secondary > y.secondary) {
        return true;
      }
    }
    return false;
  }

  friend ostream& operator << (ostream& os, const ToDoItem& td) {
    return os << td.primary << ' ' << td.secondary << ' ' << td.item; 
  }

};

int main(void) {


  priority_queue<ToDoItem> toDoList;


  toDoList.push(ToDoItem("Empty trash", 'C', 4));
  toDoList.push(ToDoItem("Feed dog", 'A', 2));
  toDoList.push(ToDoItem("Feed bird", 'B', 7));
  toDoList.push(ToDoItem("Mow lawn", 'C', 3));
  toDoList.push(ToDoItem("Water lawn", 'A', 1));
  toDoList.push(ToDoItem("Feed cat", 'B', 1));


  while (!toDoList.empty()) {
    cout << toDoList.top() << endl;
    toDoList.pop();
  }

  return 0;
}
