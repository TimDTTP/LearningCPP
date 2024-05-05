
#include "list.h" // listNode + basic operations
#include <iostream>
#include <vector>

struct TestCase {
  ListNode *list;
  ListNode *node;
};

TestCase test1() {
  TestCase obj;
  std::vector<int> vec{4, 5, 1, 9};
  ListOperations cur{};

  obj.list = cur.list(vec);
  ListNode *temp = obj.list;

  while (temp->val != 5) {
    temp = temp->next;
  }

  obj.node = temp;

  return obj;
}

TestCase test2() {
  TestCase obj;
  std::vector<int> vec{4, 5, 1, 9};
  ListOperations cur{};

  obj.list = cur.list(vec);
  ListNode *temp = obj.list;

  while (temp->val != 1) {
    temp = temp->next;
  }

  obj.node = temp;

  return obj;
}

class Solution {
public:
  void deleteNode(ListNode *node) {
    ListNode *track{node->next};

    while (track->next) {
      node->val = node->next->val;
      node = track;
      track = track->next;
    }

    // replace and delete last node
    node->val = node->next->val;
    node->next = NULL;
  }
};

int main() {
  TestCase input{test1()};
  Solution answer{};
  ListOperations listOp{};

  std::cout << "Before: " << '\n';
  listOp.printList(input.list);
  std::cout << '\n';

  answer.deleteNode(input.node);

  std::cout << "After: " << '\n';
  listOp.printList(input.list);
  std::cout << '\n';

  return 0;
}
