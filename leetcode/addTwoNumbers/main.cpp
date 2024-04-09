
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
    if (l2) {
      l1 = result;
      while (l1->next != NULL)
        l1 = l1->next;
      l1->next = l2;
      l1 = l1->next;
    }

    if (l1) {
      while (l1 != NULL) {
        int sum{l1->val + carryOver};
        carryOver = false;

        if (sum >= 10) {
          carryOver = true;
        }

        l1->val = sum % 10;

        l1 = l1->next;
      }
    }

    // if surpasses number of digits, add another node
    if (carryOver) {
      ListNode *temp = new ListNode(1);

      l1 = result;
      while (l1->next != NULL)
        l1 = l1->next;
      l1->next = temp;
    }

    return result;
  }
};

class OnlineSolution {
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummyHead = new ListNode(0);
    ListNode *dummyTail = dummyHead;
    bool carry{false};

    while (l1 != nullptr || l2 != nullptr || carry) {
      int digit1 = (l1 != nullptr) ? l1->val : 0;
      int digit2 = (l2 != nullptr) ? l2->val : 0;

      int sum{digit1 + digit2 + carry};
      int digit{sum % 10};

      carry = (sum >= 10) ? true : false;

      ListNode *temp = new ListNode(digit);
      dummyTail->next = temp;
      dummyTail = dummyTail->next;

      l1 = (l1 != nullptr) ? l1->next : nullptr;
      l2 = (l2 != nullptr) ? l2->next : nullptr;
    }

    ListNode *result = dummyHead->next;
    delete dummyHead;
    return result;
  }
};

int main() {
  int val1{9999999};
  int val2{9999};
  // expected solution 579

  Util listFcn = Util();

  ListNode *list1{listFcn.list(val1)};
  ListNode *list2{listFcn.list(val2)};
  ListNode list3{0};
  ListNode list4{0};

  Solution ans = Solution();

  ListNode *solution{ans.addTwoNumbers(list2, list1)};
  listFcn.printList(solution);

  return 0;
}
