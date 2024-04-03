
#define NULL 0
#include <vector>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// create linked list for testing purposes
ListNode *list(std::vector<int> nums) {
  ListNode *temp;

  for (int i : nums) {
    // if empty make val head
    // add onto value
  }
}

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *master{};

    do {

    } while ((list1->next != NULL) && (list2->next != NULL));

    return list1;
  }
};

int main() {
  struct ListNode *list1;
  struct ListNode *a1 = NULL;
  struct ListNode *a2 = NULL;
  list1->val = 1;
  a1->val = 2;
  a2->val = 4;
  list1->next = a1;
  a1->next = a2;
  a2->next = NULL;

  struct ListNode *list2;
  struct ListNode *b1 = NULL;
  struct ListNode *b2 = NULL;
  list2->val = 1;
  b1->val = 3;
  b2->val = 4;
  list2->next = b1;
  b1->next = b2;
  b2->next = NULL;

  return 0;
}
