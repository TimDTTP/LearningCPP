
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> target;
    int output;
  };

  TestCase testA() { return {{1, 2, 3, 2, 1}, 3}; }

  TestCase testB() { return {{3, 1, 1, 2}, 4}; }

  TestCase testC() { return {{3, 1, 5, 4, 2}, 7}; }
};

class Solution {
public:
  int minNumberOperations(std::vector<int> &target) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.minNumberOperations(unit.target)};

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
