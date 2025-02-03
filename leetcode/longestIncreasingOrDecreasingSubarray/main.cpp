
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int output;
  };

  TestCase testA() { return {{1, 4, 3, 3, 2}, 2}; }
  TestCase testB() { return {{3, 3, 3, 3}, 1}; }
  TestCase testC() { return {{3, 2, 1}, 3}; }
};

class Solution {
public:
  int longestMonotonicSubarray(std::vector<int> &nums) {
    int maxSoFar{1};

    int counter{1};
    bool isIncreasing{};
    for (int index{0}; index < nums.size() - 1; ++index) {
      // if duplicate; end
      if (nums[index] == nums[index + 1]) {
        maxSoFar = std::max(maxSoFar, counter);
        counter = 1;
      }

      // strictly increasing or decreasing
      else if (counter > 1) {
        if ((nums[index] < nums[index + 1]) == isIncreasing) {
          ++counter;
        } else {
          --index;
          maxSoFar = std::max(maxSoFar, counter);
          counter = 1;
        }
      } else {
        isIncreasing = nums[index] < nums[index + 1];
        ++counter;
      }
    }
    maxSoFar = std::max(maxSoFar, counter);

    return maxSoFar;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  int output{solCur.longestMonotonicSubarray(unit.nums)};

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
