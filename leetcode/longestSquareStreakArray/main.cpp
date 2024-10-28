
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> input;
    int output;
  };

  TestCase testA() {
    TestCase obj{{4, 3, 6, 16, 8, 2}, 3};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{2, 3, 5, 6, 7}, -1};
    return obj;
  }
};

class Solution {
public:
  int longestSquareStreak(std::vector<int> &nums) {}
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{};
  int output{};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
