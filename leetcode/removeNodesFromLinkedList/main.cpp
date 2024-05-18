
#include "list.h"
#include <vector>

// test cases
std::vector<int> test1() {
  std::vector<int> obj{5, 2, 13, 3, 8};
  return obj;
}

std::vector<int> test2() {
  std::vector<int> obj{1, 1, 1, 1};
  return obj;
}

class Solution {
public:
  ListNode *removeNodes(ListNode *head) {}
};

int main() {
  Solution ans = Solution();

  List input{List(test1())};

  // run operation here

  input.print();

  return 0;
}
