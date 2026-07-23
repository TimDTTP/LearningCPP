
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::string s;
    int expected;
  };

  TestCase testA() { return {"01", 1}; }
  TestCase testB() { return {"0100", 4}; }
  TestCase testC() { return {"1000100", 7}; }
  TestCase testD() { return {"01010", 4}; }
  std::vector<TestCase> all() { return {testA()}; };
};

class Solution {
public:
  int maxActiveSectionsAfterTrade(std::string s) {
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
    int result = sol.maxActiveSectionsAfterTrade(unit.s);

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
