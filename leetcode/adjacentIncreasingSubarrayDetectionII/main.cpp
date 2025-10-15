
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int output;
  };

  TestCase testA() { return {{2, 5, 7, 8, 9, 2, 3, 4, 3, 1}, 3}; }
  TestCase testB() { return {{1, 2, 3, 4, 4, 4, 4, 5, 6, 7}, 2}; }
};

class Solution {
public:
  int maxIncreasingSubarrays(std::vector<int> &nums) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.maxIncreasingSubarrays(unit.nums)};

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
