
#include "listnode.h"
#include <unordered_set>
#include <vector>

class Solution {
public:
  ListNode *modifiedList(std::vector<int> &nums, ListNode *head) {
    std::unordered_set<int> numSet{};
    for (int i : nums)
      numSet.insert(i);

    while (numSet.count(head->val) != 0)
      head = head->next;

    ListNode *first{head};
    ListNode *second{head->next};

    while (second != nullptr) {
      if (numSet.count(second->val) == 0) {
        first = second;
        second = second->next;
      } else {
        second = second->next;
        first->next = second;
      }
    }

    return head;
  }
};

int main() { return 0; }
