
#include <ios>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> piles;
    bool expected;
  };

  TestCase testA() { return {{5, 3, 4, 5}, true}; }
  TestCase testB() { return {{3, 7, 2, 3}, true}; }
  std::vector<TestCase> all() { return {testA(), testB()}; };
};

class Solution {
public:
  bool stoneGame(std::vector<int> &piles) {
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
    bool result = sol.stoneGame(unit.piles);

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
