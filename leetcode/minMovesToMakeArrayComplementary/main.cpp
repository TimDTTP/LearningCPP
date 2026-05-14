
#include <algorithm>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int limit;
    int expected;
  };

  TestCase testA() { return {{1, 2, 4, 3}, 4, 1}; }
  TestCase testB() { return {{1, 2, 2, 1}, 2, 2}; }
  TestCase testC() { return {{1, 2, 1, 2}, 2, 0}; }
  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
public:
  int minMoves(std::vector<int> &nums, int limit) {
    int size = nums.size();
    if (size == 2) {
      return 0;
    }
    std::vector<int> target{};
    target.resize((2 * limit), 0);

    // iterate and find # of moves
    for (int i{0}; i < (size / 2); ++i) {
      int big{std::max(nums[i], nums[size - 1 - i])};
      int small{std::min(nums[i], nums[size - 1 - i])};
      int upperLimit{big + limit};
      int lowerLimit{small + 1};

      for (int tar{2}; tar < (2 * limit); ++tar) {
        if ((big + small) == tar) {
          continue;
        } else if ((lowerLimit <= tar) && (tar <= upperLimit)) {
          target[tar] += 1;
        } else {
          target[tar] += 2;
        }
      }
    }

    auto minMoves{std::min_element(target.begin() + 2, target.end())};
    return ((minMoves != target.end()) ? *minMoves : 0);
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    int result = sol.minMoves(unit.nums, unit.limit);

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
