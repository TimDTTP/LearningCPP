
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int output;
  };

  TestCase testA() { return {{10, 20, 30, 5, 10, 50}, 65}; }

  TestCase testB() { return {{10, 20, 30, 40, 50}, 150}; }

  TestCase testC() { return {{12, 17, 15, 13, 10, 11, 12}, 33}; }
};

class Solution {
public:
  int maxAscendingSum(std::vector<int> &nums) {
    int maxSoFar{0};
    int currSum{nums[0]};

    for (int i{0}; i < nums.size() - 1; ++i) {
      if (nums[i] < nums[i + 1]) {
        currSum += nums[i + 1];
      } else {
        maxSoFar = std::max(maxSoFar, currSum);
        currSum = nums[i + 1];
      }
    }
    maxSoFar = std::max(maxSoFar, currSum);

    return maxSoFar;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  int output{solCur.maxAscendingSum(unit.nums)};

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
