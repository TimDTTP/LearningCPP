
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> A;
    std::vector<int> B;
    std::vector<int> expected;
  };

  TestCase testA() { return {{1, 3, 2, 4}, {3, 1, 2, 4}, {0, 2, 3, 4}}; }
  TestCase testB() { return {{2, 3, 1}, {3, 1, 2}, {0, 1, 3}}; }
  std::vector<TestCase> all() { return {testA()}; };

  void print(std::vector<int> vec) {
    for (int i : vec) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;
  }
};

class Solution {
public:
  std::vector<int> findThePrefixCommonArray(std::vector<int> &A,
                                            std::vector<int> &B) {
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
    std::vector<int> result = sol.findThePrefixCommonArray(unit.A, unit.B);

    if (result == unit.expected) {
      std::cout << "✅ Test " << i + 1 << " passed!\n";
      ++passed;
    } else {
      std::cout << "❌ Test " << i + 1 << " failed!\n";
      std::cout << "Expected:\n";
      tests.print(unit.expected);
      std::cout << "Got:\n";
      tests.print(result);
      std::cout << std::endl;
    }
  }
  std::cout << "\nSummary: " << passed << "/" << cases.size()
            << " tests passed.\n";

  return 0;
}
