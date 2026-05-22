
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int target;
    int expected;
  };

  TestCase testA() { return {{4, 5, 6, 7, 0, 1, 2}, 0, 4}; }
  TestCase testB() { return {{4, 5, 6, 7, 0, 1, 2}, 3, -1}; }
  TestCase testC() { return {{1}, 0, -1}; }
  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
public:
  int search(std::vector<int> &nums, int target) {
    int size = nums.size();

    // edge case size == 1
    if (size == 1) {
      return ((nums[0] == target) ? 0 : -1);
    }

    int lower{0};
    int upper{size - 1};
    int mid{};

    while ((upper - lower) > 1) {
      // narrow
      mid = lower + ((upper - lower) / 2);

      // check if range is rotated
      if (nums[lower] > nums[mid]) {
        if (nums[mid] <= target && target <= nums[upper]) {
          lower = mid;
        } else {
          upper = mid;
        }
      } else {
        if (nums[lower] <= target && target <= nums[mid]) {
          upper = mid;
        } else {
          lower = mid;
        }
      }
    }

    // return proper index
    if (nums[lower] == target || nums[upper] == target) {
      return ((nums[lower] == target) ? lower : upper);
    }

    return -1;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    int result = sol.search(unit.nums, unit.target);

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
