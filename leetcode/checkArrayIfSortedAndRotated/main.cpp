
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  TestCase testA() { return {{3, 4, 5, 1, 2}, true}; }
  TestCase testB() { return {{2, 1, 3, 4}, false}; }
  TestCase testC() { return {{1, 2, 3}, true}; }
  std::vector<TestCase> all() { return {testA()}; };
};

class Solution {
public:
  bool check(std::vector<int> &nums) {
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
    bool result = sol.check(unit.nums);

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
