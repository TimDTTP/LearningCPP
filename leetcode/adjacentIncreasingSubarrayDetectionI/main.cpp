
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int k;
    bool output;
  };

  TestCase testA() { return {{2, 5, 7, 8, 9, 2, 3, 4, 3, 1}, 3, true}; }
  TestCase testB() { return {{1, 2, 3, 4, 4, 4, 4, 5, 6, 7}, 5, false}; }
};

class Solution {
public:
  bool hasIncreasingSubarrays(std::vector<int> &nums, int k) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  bool output{solCur.hasIncreasingSubarrays(unit.nums, unit.k)};

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
