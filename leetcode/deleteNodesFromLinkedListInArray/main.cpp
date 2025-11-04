
#include "listnode.h"
#include <iostream>
#include <vector>

class Test {
private:
  ListNode *vectorToListNode(std::vector<int> vec) {
    ListNode *head;
    ListNode *tail = nullptr;
    for (int val : vec) {
      ListNode curr(val);
      if (tail == nullptr) {
        head = &curr;
      }
      tail->next = &curr;
      tail = &curr;
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

public:
  std::vector<TestCase> all() { return {testA()}; };
};

class Solution {
public:
  ListNode *modifiedList(std::vector<int> &nums, ListNode *head) {
    // Useful code
    // here
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

    if (result == unit.expected) {
      std::cout << "✅ Test " << i + 1 << " passed!\n";
      ++passed;
    } else {
      std::cout << "❌ Test " << i + 1 << " failed!\n";
      std::cout << "   Expected: " << unit.expected << " | Got: " << result
                << "\n";
    }
  }
  std::cout << "\nSummary: " << passed << "/" << cases.size()
            << " tests passed.\n";

  return 0;
}
