
#include <iostream>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int lower;
    int upper;
    long long output;
  };

  TestCase testA() {
    TestCase obj;
    obj.nums = {0, 1, 7, 4, 4, 5};
    obj.lower = 3;
    obj.upper = 6;
    obj.output = 6;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.nums = {1, 7, 9, 2, 5};
    obj.lower = 11;
    obj.upper = 11;
    obj.output = 1;
    return obj;
  }
};

class Solution {
public:
  long long countFairPairs(std::vector<int> &nums, int lower, int upper) {
    long long out;
    return out;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  long long output{solCur.countFairPairs(unit.nums, unit.lower, unit.upper)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
