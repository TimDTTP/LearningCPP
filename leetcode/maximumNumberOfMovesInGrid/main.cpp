
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int output;
  };

  TestCase testA() {
    TestCase obj;
    obj.grid = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
    obj.output = 3;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.grid = {{3, 2, 4}, {2, 1, 9}, {1, 1, 7}};
    obj.output = 0;
    return obj;
  }
};

class Solution {
public:
  int maxMoves(std::vector<std::vector<int>> &grid) {}
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.maxMoves(unit.grid)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
