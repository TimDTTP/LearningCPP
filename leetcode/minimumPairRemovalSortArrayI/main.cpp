
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  TestCase testA() { return {{5, 2, 3, 1}, 2}; }
  TestCase testB() { return {{1, 2, 2}, 0}; }
  std::vector<TestCase> all() { return {testA(), testB()}; };

  void printVec(std::vector<int> v) {
    for (int i : v) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;
  }
};

class Solution {
public:
  int minimumPairRemoval(std::vector<int> &nums) {
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
    int result = sol.minimumPairRemoval(unit.nums);

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
