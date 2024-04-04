
#include <iostream>
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
void insert(ListNode **head, int num) {
  ListNode *temp = new ListNode;
  ListNode *ptr;

  temp->val = num;
  temp->next = NULL;

  if (*head == NULL)
    *head = temp;
  else {
    ptr = *head;
    while (ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = temp;
  }
}

ListNode *vectorToList(std::vector<int> vec) {
  ListNode *head = NULL;
  for (int num : vec) {
    insert(&head, num);
  }

  return head;
}

// print linked list
void printList(ListNode *list) {
  std::cout << "Printed list: " << '\n';
  while (list != NULL) {
    std::cout << list->val << '\n';
    list = list->next;
  }
  std::cout << '\n';
}

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) { return list1; }
};

int main() {
  std::vector<int> a{1, 2, 4};
  std::vector<int> b{1, 3, 4};

  ListNode *list1{vectorToList(a)};
  ListNode *list2{vectorToList(b)};

  return 0;
}
