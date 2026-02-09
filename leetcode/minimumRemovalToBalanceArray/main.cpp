
#include <algorithm>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int k;
    int expected;
  };

  TestCase testA() { return {{2, 1, 5}, 2, 1}; }
  TestCase testB() { return {{1, 6, 2, 9}, 3, 2}; }
  TestCase testC() { return {{4, 6}, 2, 0}; }
  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
public:
  int minRemoval(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());

    int size = nums.size();
    int currMin{size};
    bool earlyExit;
    int checkpoint{0};

    // edge case
    if (size == 1)
      return 0;

    for (int i{0}; i < (size - 1); ++i) {
      for (int j{checkpoint}; j < size; ++j) {
        earlyExit = false;
        if (nums[j] > ((long long)nums[i] * (long long)k)) {
          currMin = std::min(currMin, (i + (size - j)));
          checkpoint = j;
          if (currMin == 0)
            return 0;
          earlyExit = true;
          break;
        }
      }
      if (!earlyExit) {
        return std::min(currMin, i);
      }
    }

    return currMin;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    int result = sol.minRemoval(unit.nums, unit.k);

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
