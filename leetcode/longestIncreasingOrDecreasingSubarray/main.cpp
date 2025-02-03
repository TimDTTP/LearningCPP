
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
    int out{};
    return out;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
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
