
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    bool output;
  };

  TestCase testA() {
    TestCase obj{{8, 4, 2, 30, 15}, true};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{1, 2, 3, 4, 5}, true};
    return obj;
  }

  TestCase testC() {
    TestCase obj{{3, 16, 8, 4, 2}, false};
    return obj;
  }
};

class Solution {
public:
  bool canSortArray(std::vector<int> &nums) {}
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  bool output{solCur.canSortArray(unit.nums)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
