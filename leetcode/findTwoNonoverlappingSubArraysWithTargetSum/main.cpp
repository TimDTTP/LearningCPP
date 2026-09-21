
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    int expected;
    std::vector<int> arr;
    int target;
  };

  TestCase testA() { return {2, {3, 2, 2, 4, 3}, 3}; }
  TestCase testB() { return {2, {7, 3, 4, 7}, 7}; }
  TestCase testC() { return {-1, {4, 3, 2, 6, 2, 3, 4}, 6}; }

  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
public:
  int minSumOfLengths(std::vector<int> &arr, int target) {
    // some useful code
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
    int result = sol.minSumOfLengths(unit.arr, unit.target);

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
