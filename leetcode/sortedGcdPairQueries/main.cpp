
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    std::vector<long long> queries;
    std::vector<int> expected;
  };

  TestCase testA() { return {{2, 3, 4}, {0, 2, 2}, {1, 2, 2}}; }
  TestCase testB() { return {{4, 4, 2, 1}, {5, 3, 1, 0}, {4, 2, 1, 1}}; }
  TestCase testC() { return {{2, 2}, {0, 0}, {2, 2}}; }
  std::vector<TestCase> all() { return {testA()}; };
};

class Solution {
public:
  std::vector<int> gcdValues(std::vector<int> &nums,
                             std::vector<long long> &queries) {
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
    std::vector<int> result = sol.gcdValues(unit.nums, unit.queries);

    if (result == unit.expected) {
      std::cout << "✅ Test " << i + 1 << " passed!\n";
      ++passed;
    } else {
      std::cout << "❌ Test " << i + 1 << " failed!\n";
      std::cout << "   Expected: " << std::endl;
      for (int num : unit.expected) {
        std::cout << num << ' ';
      }
      std::cout << std::endl;
      std::cout << "   Got: " << std::endl;
      for (int num : result) {
        std::cout << num << ' ';
      }
      std::cout << std::endl;
    }
  }
  std::cout << "\nSummary: " << passed << "/" << cases.size()
            << " tests passed.\n";

  return 0;
}
