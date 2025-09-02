
#include <iostream>

class Test {
public:
  struct TestCase {
    std::vector<std::vector<int>> points;
    int output;
  };

  TestCase testA() { return {{{1, 1}, {2, 2}, {3, 3}}, 0}; }

  TestCase testB() { return {{{6, 2}, {4, 4}, {2, 6}}, 2}; }

  TestCase testC() { return {{{3, 1}, {1, 3}, {1, 1}}, 2}; }
};

class Solution {
public:
  int numberOfPairs(std::vector<std::vector<int>> &points) {
    // useful code here
    return 0;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.numberOfPairs(unit.points)};

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
