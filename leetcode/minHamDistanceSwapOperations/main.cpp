
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> source;
    std::vector<int> target;
    std::vector<std::vector<int>> allowedSwaps;
    int expected;
  };

  TestCase testA() { return {{1, 2, 3, 4}, {2, 1, 4, 5}, {{0, 1}, {2, 3}}, 1}; }
  TestCase testB() { return {{1, 2, 3, 4}, {1, 3, 2, 4}, {{}}, 2}; }
  TestCase testC() {
    return {
        {5, 1, 2, 4, 3}, {1, 5, 4, 2, 3}, {{0, 4}, {4, 2}, {1, 3}, {1, 4}}, 0};
  }

  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
public:
  int minimumHammingDistance(std::vector<int> &source, std::vector<int> &target,
                             std::vector<std::vector<int>> &allowedSwaps) {
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
    int result =
        sol.minimumHammingDistance(unit.source, unit.target, unit.allowedSwaps);

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
