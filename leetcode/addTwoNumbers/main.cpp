
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// utility functions for testing
class Util {
public:
  // print list
  void printList(ListNode *list) {
    while (list != NULL) {
      std::cout << list->val << ' ';
      list = list->next;
    }
    std::cout << '\n';
  }

  // int to linked list in reverse order
  ListNode *list(int num) {
    ListNode *head = NULL;

    while (num > 0) {
      int digit{num % 10};
      num /= 10;

      ListNode *temp = new ListNode();
      temp->val = digit;
      temp->next = NULL;

      // add to list node
      if (head == NULL)
        head = temp;
      else {
        ListNode *ptr = head;
        while (ptr->next != NULL)
          ptr = ptr->next;
        ptr->next = temp;
      }
    }

    return head;
  }
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // lorem
    // ipsum

    return l1;
  }
};

int main() {
  int val1{123};
  int val2{456};

  Util listFcn = Util();

  ListNode *list1{listFcn.list(val1)};
  ListNode *list2{listFcn.list(val2)};

  return 0;
}
