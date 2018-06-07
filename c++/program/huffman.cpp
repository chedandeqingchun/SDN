#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

typedef struct _node {
  char ch;
  int times;
  Node *left;
  Node *right;
} Node;

struct cmp {
  bool operator () (Node &a, Node &b) {
    return a.times > b.times;
  }
};

/*
 *null, exist one child, exist two child, one node 
 *
 *
 */


void DisplayTree(const Node node, int x) {
  if () {

  } 

}


int main(void) {
  //string str = "The following are a set of methods intended for regression in which the target value is expected to be a linear combination of the input variables.";

  priority_queue<Node, vector<Node>, cmp> que;

  Node head;
  Node ele1, ele2, ele3, ele4, ele5;
  Node *temp = NULL;
  size_t n;

  ele1.ch = 'a';
  ele2.ch = 'd';
  ele3.ch = 'f';
  ele4.ch = 'm';
  ele5.ch = 'k';
  ele1.times = 5;
  ele2.times = 4;
  ele3.times = 1;
  ele4.times = 7;
  ele5.times = 12;

  que.push(ele1);
  que.push(ele2);
  que.push(ele3);
  que.push(ele4);
  que.push(ele5);

  for (n = que.size() - 1; n >= 0; n--) {
    temp = new Node;
    assert(temp != NULL);
    temp.ch = '-1';
    temp.left = que.top(), que.pop();
    temp.right = que.top(), que.pop();
    temp.times = temp.left.times + temp.right.times;
    que.push(temp);
  }

  head = que.top(), que.pop();

  return 0;
}
