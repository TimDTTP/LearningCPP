
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int k;
    int output;
  };

  TestCase testA() { return {{1, 2, 2, 3, 3, 4}, 2, 6}; }

  TestCase testB() { return {{4, 4, 4, 4}, 1, 3}; }
};

class Solution {
public:
  int maxDistinctElements(std::vector<int> &nums, int k) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.maxDistinctElements(unit.nums, unit.k)};

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
