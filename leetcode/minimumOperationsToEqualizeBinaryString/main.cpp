
#include <iostream>
#include <utility>
#include <vector>

class Test {
public:
  struct TestCase {
    std::string s;
    int k;
    int expected;
  };

  TestCase testA() { return {"110", 1, 1}; }
  TestCase testB() { return {"0101", 3, 2}; }
  TestCase testC() { return {"101", 2, -1}; }
  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
private:
  bool ifPossible(int zeroes, int k) {
    while (k > 0) {
      if ((zeroes % k) == 0)
        return true;
      else
        k -= 2;
    }
    return false;
  }

public:
  int minOperations(std::string s, int k) {
    std::pair<int, int> binaryQuantity{};
    for (char digit : s) {
      ((digit - '0') ? ++binaryQuantity.second : ++binaryQuantity.first);
    }

    // check if possible
    if (!ifPossible(binaryQuantity.first, k)) {
      return -1;
    }

    return 1;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    int result = sol.minOperations(unit.s, unit.k);

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
