
#include <cstddef>
#include <iostream>
#include <numeric>
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
  TestCase testE() { return {"10100101", 7}; }
  std::vector<TestCase> all() {
    return {testA(), testB(), testC(), testD(), testE()};
  };
};

class Solution {
public:
  int maxActiveSectionsAfterTrade(std::string s) {
    int n = s.size();

    // get length into vector
    std::vector<int> substring{};
    int totalOnes{0};
    int curr{0};
    bool isActive{(s[0] == '1') ? true : false};
    for (int i{0}; i < n; ++i) {
      if ((s[i] == '1') == isActive) {
        ++curr;
      } else {
        substring.push_back(curr);
        if (isActive) {
          totalOnes += curr;
        }
        curr = 1;
        isActive = !isActive;
      }
    }
    substring.push_back(curr);
    if (isActive) {
      totalOnes += curr;
    }

    // edge cases
    isActive = (s[0] == '1') ? true : false;
    int occur = substring.size();
    if (occur == 1) {
      return (isActive ? substring[0] : 0);
    }
    if (occur <= 3) {
      switch (occur) {
      case (1):
        return (isActive ? substring[0] : 0);
      case (2):
        return (isActive ? substring[0] : substring[1]);
      case (3):
        if (isActive) {
          return substring[0] + substring[2];
        } else {
          break;
        }
      }
    }

    // compare
    int max{0};
    for (int i{(s[0] == '1') ? 0 : 1}; i < occur; i += 2) {
      curr = std::accumulate((substring.begin() + std::max(0, i - 1)),
                             (substring.begin() + std::min(occur, (i + 2))), 0);
      max = std::max(max, (totalOnes - substring[i] + curr));
    }

    return max;
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
