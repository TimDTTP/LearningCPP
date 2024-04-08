
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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *result = NULL;

    if (list1 == NULL) {
      result = list2;
      return result;
    }
    if (list2 == NULL) {
      result = list1;
      return result;
    }

    while ((list1 != NULL) && (list2 != NULL)) {
      if (list1->val == list2->val) {
        insert(&result, list1->val);
        insert(&result, list2->val);

        list1 = list1->next;
        list2 = list2->next;
      } else if (list1->val < list2->val) {
        insert(&result, list1->val);

        list1 = list1->next;
      } else if (list1->val > list2->val) {
        insert(&result, list2->val);

        list2 = list2->next;
      }
    }

    // if there are remaining numbers in each list
    ListNode *ptr = result;
    if (list1 != NULL) {
      while (ptr->next != NULL)
        ptr = ptr->next;

      ptr->next = list1;
    }

    if (list2 != NULL) {
      while (ptr->next != NULL)
        ptr = ptr->next;

      ptr->next = list2;
    }

    return result;
  }
};

// Improved code based on online submissions
class OnlineSolution {
public:
  ListNode *mergeSortedLists(ListNode *list1, ListNode *list2) {
    // base case of empty list
    if (list1 == NULL)
      return list2;
    if (list2 == NULL)
      return list1;

    // ptr will hold head of list
    ListNode *ptr = list1;

    // set head of list
    if (list1->val > list2->val) {
      ptr = list2;
      list2 = list2->next;
    } else {
      list1 = list1->next;
    }
    ListNode *curr = ptr;

    // loop to sort list
    while (list1 && list2) {
      if (list1->val < list2->val) {
        curr->next = list1;
        list1 = list1->next;
      } else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
    }

    // if one list ends prematurely
    if (list1)
      curr->next = list1;
    else
      curr->next = list2;

    return ptr;
  }
};

int main() {
  std::vector<int> a{1, 2, 4};
  std::vector<int> b{1, 3, 4};
  std::vector<int> c{};
  std::vector<int> d{0};

  ListNode *list1{vectorToList(c)};
  ListNode *list2{vectorToList(d)};

  Solution cur = Solution();

  ListNode *result{cur.mergeTwoLists(list1, list2)};
  printList(result);

  return 0;
}
