
#include <iostream>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int k;
    long long output;
  };

  TestCase testA() {
    TestCase obj{{1, 5, 4, 2, 9, 9, 9}, 3, 15};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{4, 4, 4}, 3, 0};
    return obj;
  }
};

class Solution {
public:
  long long maximumSubarraySum(std::vector<int> &nums, int k) {
    long long output;
    return output;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  long long output{solCur.maximumSubarraySum(unit.nums, unit.k)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
