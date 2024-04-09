
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
private:
  void addRemaining(ListNode *l1, ListNode *l2, bool &carryOver) {
    l1->val += carryOver;
    carryOver = false;
    if (l1->val >= 10)
      carryOver = true;
  }

public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *result = l1;
    bool carryOver{false};

    while (l1 && l2) {
      int sum{l1->val + l2->val + carryOver};
      carryOver = false;

      if (sum >= 10)
        carryOver = true;

      l1->val = sum % 10;

      l1 = l1->next;
      l2 = l2->next;
    }

    // if not empty yet
    while (l1) {
      addRemaining(l1, l2, carryOver);
    }

    while (l2) {
      l1->next = l2;
      l1 = l1->next;
      addRemaining(l1, l2, carryOver);
    }

    // if surpasses number of digits, add another node
    if (carryOver) {
      ListNode temp{1};
      l1->next = &temp;
    }

    return result;
  }
};

int main() {
  int val1{123};
  int val2{456};
  // expected solution 579

  Util listFcn = Util();

  ListNode *list1{listFcn.list(val1)};
  ListNode *list2{listFcn.list(val2)};

  Solution ans = Solution();

  ListNode *solution{ans.addTwoNumbers(list1, list2)};
  listFcn.printList(solution);

  return 0;
}
