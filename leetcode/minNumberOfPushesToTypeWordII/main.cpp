
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::string word;
    int expected;
  };

  TestCase testA() { return {"abcde", 5}; }
  TestCase testB() { return {"xyzxyzxyzxyz", 12}; }
  TestCase testC() { return {"aabbccddeeffgghhiiiiii", 24}; }
  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
public:
  int minimumPushes(std::string word) {
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
    int result = sol.minimumPushes(unit.word);

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
