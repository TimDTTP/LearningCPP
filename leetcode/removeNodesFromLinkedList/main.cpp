
#include "list.h"
#include <algorithm>
#include <map>
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
  // sorting map in descending order based on value
  bool mapCmp(std::pair<int, int> lhs, std::pair<int, int> rhs) const {
    return lhs.second > rhs.second;
  }

public:
  ListNode *removeNodes(ListNode *head) {
    int count{1};

    // <key, value> :: <val, index>
    std::map<int, int> valMap{};

    // loop through list and add
    while (head) {
      valMap[count] = head->val;
      ++count;
    }

    // sort map
    std::sort(valMap.begin(), valMap.end(), mapCmp);

    // add to new list
    ListNode *newList;
    valMap[0];

    // FIX: change return value
    return head;
  }
};

int main() {
  Solution ans = Solution();

  List input{List(test1())};

  // run operation here

  input.print();

  return 0;
}
