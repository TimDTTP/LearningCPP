
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int values;
    int output;
  };

  TestCase testA() {
    return {
        {1, -10, 7, 13, 6, 8},
        5,
        4,
    };
  }

  TestCase testB() {
    return {
        {1, -10, 7, 13, 6, 8},
        7,
        2,
    };
  }
};

class Solution {
public:
  int findSmallestInteger(std::vector<int> &nums, int value) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.findSmallestInteger(unit.nums, unit.values)};

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
