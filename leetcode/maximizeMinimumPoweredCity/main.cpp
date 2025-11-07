
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> stations;
    int r;
    int k;
    long long expected;
  };

private:
  TestCase testA() { return {{1, 2, 4, 5, 0}, 1, 2, 5}; }

  TestCase testB() { return {{4, 4, 4, 4}, 0, 3, 4}; }

public:
  std::vector<TestCase> all() { return {testA(), testB()}; };
};

class Solution {
public:
  long long maxPower(std::vector<int> &stations, int r, int k) {
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
    long long result = sol.maxPower(unit.stations, unit.r, unit.k);

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
