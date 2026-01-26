
#include <algorithm>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  TestCase testA() { return {{5, 2, 3, 1}, 2}; }
  TestCase testB() { return {{1, 2, 2}, 0}; }
  TestCase testC() { return {{7, 5, 3, 1, 2, 4, 6}, 5}; }
  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };

  void printVec(std::vector<int> v) {
    for (int i : v) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;
  }
};

class Solution {
private:
  bool isDecreasing(std::vector<int> const vec) {
    for (int i{0}; i < vec.size() - 1; ++i) {
      if (vec[i] > vec[i + 1])
        return true;
    }
    return false;
  }

public:
  int minimumPairRemoval(std::vector<int> &nums) {
    // sums vector
    std::vector<int> sums{};
    for (int i{0}; i < nums.size() - 1; ++i) {
      sums.push_back(nums[i] + nums[i + 1]);
    }

    // checker block
    int count{0};
    while (isDecreasing(nums)) {
      std::size_t index =
          std::min_element(sums.begin(), sums.end()) - sums.begin();
      if (index > 0) {
        sums[index - 1] = sums[index] + nums[index - 1];
      }
      if (index < sums.size() - 1) {
        sums[index + 1] = sums[index] + nums[index + 2];
      }
      nums[index] = sums[index];
      nums.erase(nums.begin() + index + 1);
      sums.erase(sums.begin() + index);
      ++count;
    }

    return count;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    int result = sol.minimumPairRemoval(unit.nums);

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
