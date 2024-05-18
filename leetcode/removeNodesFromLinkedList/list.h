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
class List {
private:
  ListNode *m_head{};

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

public:
  // constructor
  List(std::vector<int> vec) : m_head{create(vec)} {}

  // print list
  void print() {
    std::cout << "Printing list: " << '\n';
    while (m_head) {
      std::cout << m_head->val << ' ';
      m_head = m_head->next;
    }
    std::cout << '\n';
  }
};

#endif
