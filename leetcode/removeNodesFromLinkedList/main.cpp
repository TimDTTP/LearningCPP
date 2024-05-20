
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
  static bool mapCmp(std::pair<int, int> &lhs, std::pair<int, int> &rhs) {
    return lhs.second > rhs.second;
  }

private:
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

    // test print sort map
    for (const auto &[k, v] : valMap) {
      std::cout << '[' << k << ',' << v << ']' << '\n';
    }
    // add to new list

    // FIX: change return value
    return head;
  }
};

int main() {
  Solution ans = Solution();

  List input{List(test1())};

  // run operation here

  // input.print();

  return 0;
}
