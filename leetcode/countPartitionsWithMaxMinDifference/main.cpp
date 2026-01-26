
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int k;
    int expected;
  };

  TestCase testA() { return {{9, 4, 1, 3, 7}, 4, 6}; };
  TestCase testB() { return {{3, 3, 4}, 0, 2}; };
  TestCase testC() { return {{15, 23}, 1, 1}; };
  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
private:
  void permutation(std::vector<int> &nums, int k, int min, int max, int index,
                   int &count) {
    // +1 over possible index
    if (index == nums.size() - 1) {
      ++count;
      if ((max - min) <= k) {
        ++count;
      }
      return;
    }

    // if next value satisfy condition
    if (nums[index + 1] > max)
      max = nums[index + 1];
    else if (nums[index + 1] < min)
      min = nums[index + 1];

    // increment 1 next
    permutation(nums, k, nums[index + 1], nums[index + 1], index + 1, count);

    if ((max - min) <= k) {
      permutation(nums, k, min, max, index + 1, count);
    }
  }

public:
  int countPartitions(std::vector<int> &nums, int k) {
    int count{0};
    permutation(nums, k, nums[0], nums[0], 0, count);

    return count;
  }
};

int main() {
  Test tests;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    Solution sol;
    auto &unit = cases[i];
    int result = sol.countPartitions(unit.nums, unit.k);

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
