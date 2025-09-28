
#include <algorithm>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int output;
  };

  TestCase testA() { return {{2, 1, 2}, 5}; }

  TestCase testB() { return {{1, 2, 1, 10}, 0}; }
};

class Solution {
public:
  int largestPerimeter(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());

    int end;
    for (int i{0}; i < nums.size() - 2; i++) {
      end = nums[i] - nums[i + 1] - nums[i + 2];
      if (end < 0) {
        return (nums[i] + nums[i + 1] + nums[i + 2]);
      }
    }

    return 0;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
  int output{solCur.largestPerimeter(unit.nums)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;

  return 0;
}
