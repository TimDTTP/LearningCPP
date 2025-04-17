
#include <iostream>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int k;
    int output;
  };

  TestCase testA() { return {{3, 1, 2, 2, 2, 1, 3}, 2, 4}; }
  TestCase testB() { return {{1, 2, 3, 4}, 1, 0}; }
};

class Solution {
public:
  int countPairs(std::vector<int> &nums, int k) {
    int output{0};
    return output;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.countPairs(unit.nums, unit.k)};

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
