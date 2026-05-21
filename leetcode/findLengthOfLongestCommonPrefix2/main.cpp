
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> arr1;
    std::vector<int> arr2;
    int expected;
  };

  TestCase testA() { return {{1, 10, 100}, {1000}, 3}; }
  TestCase testB() { return {{1, 2, 3}, {4, 4, 4}, 0}; }
  std::vector<TestCase> all() { return {testA()}; };
};

class Solution {
public:
  int longestCommonPrefix(std::vector<int> &arr1, std::vector<int> arr2) {
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
    int result = sol.longestCommonPrefix(unit.arr1, unit.arr2);

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
