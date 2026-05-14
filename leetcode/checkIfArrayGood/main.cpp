
#include <ios>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  TestCase testA() { return {{2, 1, 3}, false}; }
  TestCase testB() { return {{1, 3, 3, 2}, true}; }
  TestCase testC() { return {{1, 1}, true}; }
  TestCase testD() { return {{3, 4, 4, 1, 2, 1}, false}; }
  std::vector<TestCase> all() { return {testA(), testB(), testC(), testD()}; };
};

class Solution {
public:
  bool isGood(std::vector<int> &nums) {
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
    bool result = sol.isGood(unit.nums);

    std::cout << std::boolalpha;
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
