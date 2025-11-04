
#include "listnode.h"
#include <iostream>
#include <unordered_set>
#include <vector>

class Test {
private:
  ListNode *vectorToListNode(std::vector<int> vec) {
    ListNode *head = new ListNode(vec[0]);
    ListNode *tail = head;
    for (int i{1}; i < vec.size(); ++i) {
      tail->next = new ListNode(vec[i]);
      tail = tail->next;
    }
    return head;
  }

public:
  struct TestCase {
    std::vector<int> nums;
    ListNode *head;
    ListNode *expected;
  };

private:
  TestCase testA() {
    TestCase obj;
    obj.nums = {1, 2, 3};
    obj.head = vectorToListNode({1, 2, 3, 4, 5});
    obj.expected = vectorToListNode({4, 5});
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.nums = {1};
    obj.head = vectorToListNode({1, 2, 1, 2, 1, 2});
    obj.expected = vectorToListNode({2, 2, 2});
    return obj;
  }

  TestCase testC() {
    TestCase obj;
    obj.nums = {5};
    obj.head = vectorToListNode({1, 2, 3, 4});
    obj.expected = vectorToListNode({1, 2, 3, 4});
    return obj;
  }

  TestCase testD() {
    TestCase obj;
    obj.nums = {9, 2, 5};
    obj.head = vectorToListNode({2, 10, 9});
    obj.expected = vectorToListNode({10});
    return obj;
  }

public:
  std::vector<TestCase> all() { return {testA(), testB(), testC(), testD()}; };

  bool checkEqual(ListNode *result, ListNode *expected) {
    std::vector<int> resultVec, expectedVec;

    while (result != nullptr) {
      resultVec.push_back(result->val);
      result = result->next;
    }
    while (expected != nullptr) {
      expectedVec.push_back(expected->val);
      expected = expected->next;
    }

    return (resultVec == expectedVec);
  }

  void printList(ListNode *head) {
    while (head != nullptr) {
      std::cout << head->val << ' ';
      head = head->next;
    }
    std::cout << std::endl;
  }
};

class Solution {
public:
  ListNode *modifiedList(std::vector<int> &nums, ListNode *head) {
    std::unordered_set<int> numSet{nums.begin(), nums.end()};

    ListNode *newHead = nullptr;
    ListNode *tail = nullptr;
    while (head != nullptr) {

      if (!numSet.contains(head->val)) {
        if (!newHead) {
          newHead = head;
          tail = head;
        } else {
          tail->next = head;
          tail = head;
        }
      }
      head = head->next;
    }
    tail->next = nullptr;

    return newHead;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    ListNode *result = sol.modifiedList(unit.nums, unit.head);

    if (tests.checkEqual(result, unit.expected)) {
      std::cout << "✅ Test " << i + 1 << " passed!\n";
      ++passed;
    } else {
      std::cout << "❌ Test " << i + 1 << " failed!\n";
      std::cout << "   Expected: ";
      tests.printList(unit.expected);
      std::cout << "        Got: ";
      tests.printList(result);
    }
  }
  std::cout << "\nSummary: " << passed << "/" << cases.size()
            << " tests passed.\n";

  return 0;
}
