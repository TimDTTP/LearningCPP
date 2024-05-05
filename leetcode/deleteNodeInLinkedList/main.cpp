
#include "list.h" // listNode + basic operations
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
  void deleteNode(ListNode *node) {}
};

int main() {
  TestCase input{test1()};
  Solution answer{};
  ListOperations listOp{};

  answer.deleteNode(input.node);
  listOp.printList(input.list);

  return 0;
}
