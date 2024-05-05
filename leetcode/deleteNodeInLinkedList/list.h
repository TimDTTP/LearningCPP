#ifndef LIST_H
#define LIST_H

#include <iostream> // for NULL
#include <vector>   // for vector

// GIVEN FROM LEETCODE
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val{x}, next{NULL} {}
};

// Self-defined functions
class ListOperations {
public:
  // create list node
  ListNode *list(std::vector<int> in) {
    ListNode *head = NULL;
    ListNode *tail = NULL;

    for (int val : in) {
      ListNode *temp = new ListNode(val);

      if (head == NULL) {
        head = temp;
        tail = head;
      } else {
        tail->next = temp;
        tail = tail->next;
      }
    }

    return head;
  }

  // print list node
  void printList(ListNode *list) {
    while (list) {
      std::cout << list->val << ' ';
      list = list->next;
    }
    std::cout << '\n';
  }
};

#endif
