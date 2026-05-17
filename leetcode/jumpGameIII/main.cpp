
#include <ios>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> arr;
    int start;
    bool expected;
  };

  TestCase testA() { return {{4, 2, 3, 0, 3, 1, 2}, 5, true}; }
  TestCase testB() { return {{4, 2, 3, 0, 3, 1, 2}, 0, true}; }
  TestCase testC() { return {{3, 0, 2, 1, 2}, 2, false}; }
  std::vector<TestCase> all() { return {testA()}; };
};

class Solution {
public:
  bool canReach(std::vector<int> &arr, int start) {
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
    bool result = sol.canReach(unit.arr, unit.start);

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
