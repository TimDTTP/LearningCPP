
#include <iostream>
#include <string>
#include <vector>

class Test {
public:
  struct TestCase {
    std::string s;
    int expected;
  };

  TestCase testA() { return {"aabca", 3}; }
  TestCase testB() { return {"adc", 0}; }
  TestCase testC() { return {"bbcbaba", 4}; }
  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
public:
  int countPalindromicSubsequence(std::string s) {
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
    int result = sol.countPalindromicSubsequence(unit.s);

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
