#include <iostream>
#include <memory>
using namespace std;

class slist {
  struct linkNode {
    linkNode *next, *prev;
    int data;
  };

  auto_ptr<linkNode> *head, *tail;

  linkNode* _createNode(const int& value) {
    linkNode *obj = NULL;
    obj = new linkNode();

    if (NULL != obj) {
      obj->data = value;
    }

    return obj;
  }

  void _splitList(linkNode *prev, linkNode *next) {
    linkNode* slowPtr, fastPtr; 
    slowPtr = fastPtr = head;

    while (NULL != fastPtr) {
      fastPtr = fastPtr->next;

      if (NULL != fastPtr) {
        fastPtr = fastPtr->next;
        slowPtr = slowPtr->next;
      }
    }

    prev = head;
    next = slow->next;
    slow->next = NULL;
    next->prev = NULL;
  }

  linkNode* _sortMerge(linkNode *prev, linkNode *latter) {
    linkNode *res;

    if (NULL == prev) {
      return next; 
    } else if (NULL == latter) {
      return prev;
    }

    if (prev->value > latter->value) {
      res->next = _sortMerge(prev, latter->next);
    } else {
      res->next = _sortMerge(prev->next, latter);
    }

    return res;
  }

  public:
    slist() {
      head = tail = NULL;
    }
    void push_back(const int& value) {
      linkNode *obj;
      obj = _createNode(value);

      if (NULL == head) {
        tail = head = obj;
        obj->prev = obj->next = NULL;
      } else {
        if (NULL != obj) {
          obj->next = tail->next;
          obj->prev = tail;
          tail->next = obj;
          tail = obj;
        }
      }
    }

    linkNode* pop_back() {
      linkNode *obj;
      obj = tail;
      tail = obj->prev;
      tail->next = obj->next; 
      return result;
    }

    void sort(linkNode *node) {
      linkNode *prev, *next, *last, *firstEle;

      if (NULL = node || NULL == Node->next) {
        return;
      }

      _splitList(prev, next);
      sort(prev); 
      sort(next);
      head = _sortMerge(prev, next);

     firstEle = head;
      
      while (NULL != firstEle) {
        last = firstEle;
        firstEle = firstEle->next;
      }

     tail = last;
    }
};

int main(void) {
  slist l;

  l.push_back(12);
  l.push_back(45);
  l.push_back(54);
  l.push_back(63);
  l.push_back(1);
  l.push_back(7);
  l.push_back(2);
  l.push_back(5);

  return 0;
}
