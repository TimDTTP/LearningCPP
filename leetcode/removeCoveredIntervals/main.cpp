
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    int expected;
    std::vector<std::vector<int>> intervals;
  };

  TestCase testA() { return {2, {{1, 4}, {3, 6}, {2, 8}}}; }
  TestCase testB() { return {1, {{1, 4}, {2, 3}}}; }

  std::vector<TestCase> all() { return {testA()}; };
};

class Solution {
public:
  int removeCoveredIntervals(std::vector<std::vector<int>> &intervals) {
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
    int result = sol.removeCoveredIntervals(unit.intervals);

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
