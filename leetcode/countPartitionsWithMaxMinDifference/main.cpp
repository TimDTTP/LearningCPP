
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int k;
    int expected;
  };

  TestCase testA() { return {{9, 4, 1, 3, 7}, 4, 6}; };
  TestCase testB() { return {{3, 3, 4}, 0, 2}; };
  std::vector<TestCase> all() { return {testA(), testB()}; };
};

class Solution {
public:
  int countPartitions(std::vector<int> &nums, int k) {
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
    int result = sol.countPartitions(unit.nums, unit.k);

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
