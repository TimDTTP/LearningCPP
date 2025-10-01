
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int output;
  };

  TestCase testA() { return {{1, 2, 3, 4, 5}, 8}; }
  TestCase testB() { return {{5}, 5}; }
};

class Solution {
public:
  int triangularSum(std::vector<int> &nums) {
    int temp;

    while (nums.size() != 1) {
      for (int i{0}; i < (static_cast<int>(nums.size()) - 1); i++) {
        temp = nums[i + 1];
        nums[i] = (nums[i] + nums[i + 1]) % 10;
      }
      nums.erase(nums.end());
    }
    return nums[0];
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.triangularSum(unit.nums)};

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
