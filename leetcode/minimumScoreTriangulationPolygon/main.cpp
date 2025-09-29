
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> values;
    int output;
  };

  TestCase testA() { return {{1, 2, 3}, 6}; }

  TestCase testB() { return {{3, 7, 4, 5}, 144}; }

  TestCase testC() { return {{1, 3, 1, 4, 1, 5}, 13}; }
};

class Solution {
public:
  int minScoreTriangulation(std::vector<int> values) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.minScoreTriangulation(unit.values)};

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
