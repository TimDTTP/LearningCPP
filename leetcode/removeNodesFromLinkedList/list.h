#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>

// definition of linked list (provided by leetcode)
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// suplementary list operations (self defined)
class ListMethods {
public:
  // vector to list
  ListNode *create(std::vector<int> input) {
    ListNode *head = new ListNode();
    ListNode *tail = head;

    // add to list
    for (int num : input) {
      ListNode *temp = new ListNode(num);
      if (!head) {
        head = temp;
        tail = head;
      } else {
        tail->next = temp;
      }
    }

    return head;
  }

  // print list
  void print(ListNode *head) {
    std::cout << "Printing list: " << '\n';
    while (head) {
      std::cout << head->val << ' ';
      head = head->next;
    }
    std::cout << '\n';
  }
};

#endif
