
#include <algorithm>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  TestCase testA() { return {{3, 4, 5, 1, 2}, 1}; }
  TestCase testB() { return {{4, 5, 6, 7, 0, 1, 2}, 0}; }
  TestCase testC() { return {{11, 13, 15, 17}, 11}; }
  TestCase testD() { return {{1}, 1}; }
  TestCase testE() { return {{2, 1}, 1}; }
  std::vector<TestCase> all() {
    return {testA(), testB(), testC(), testD(), testE()};
  };
};

class Helper {
public:
  std::vector<int> rotate(std::vector<int> nums, int rotate) {
    for (int i{0}; i < rotate; ++i) {
      nums.push_back(nums[0]);
      nums.erase(nums.begin());
    }
    return nums;
  }
};

class Solution {
public:
  int findMin(std::vector<int> &nums) {
    int lower{0};
    int upper = nums.size() - 1;
    int curr{};
    int minSoFar{nums[0]};

    // edge case n < 3

    while ((upper - lower) >= 2) {
      curr = lower + ((upper - lower) / 2);
      if (nums[curr - 1] > nums[curr]) {
        return nums[curr];
      }
      minSoFar = std::min(nums[lower], minSoFar);

      bool left{nums[curr] > nums[lower]};
      lower = (left) ? curr : lower;
      upper = (left) ? upper : curr;
    }

    return std::min(nums[upper], minSoFar);
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    int result = sol.findMin(unit.nums);

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
