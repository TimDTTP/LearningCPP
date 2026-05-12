
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<std::vector<int>> tasks;
    int expected;
  };

  TestCase testA() { return {{{1, 2}, {2, 4}, {4, 8}}, 8}; }
  TestCase testB() {
    return {{{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}}, 32};
  }
  TestCase testC() {
    return {{{1, 7}, {2, 8}, {3, 9}, {4, 10}, {5, 11}, {6, 12}}, 32};
  }

  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
public:
  int minimumEffort(std::vector<std::vector<int>> &tasks) {
    // useful code
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
    void result = sol;

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
