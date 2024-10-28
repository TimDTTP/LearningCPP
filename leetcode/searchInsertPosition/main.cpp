
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int target;
    int output;
  };

  TestCase testA() {
    TestCase obj{{2, 4, 6, 8, 10}, 4, 1};
    return obj;
  }
};

class Solution {
public:
  int searchInsert(std::vector<int> &nums, int target) {}
};

int main() {
  Solution solCur{Solution()};
  Test testCur{Test()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.searchInsert(unit.nums, unit.target)};

  if (unit.output == output)
    std::cout << "Sucess!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;

  return 0;
}
