
#include <iostream>

class Test {
public:
  struct TestCase {
    int x;
    int y;
    int z;
    int output;
  };

  TestCase testA() { return {2, 7, 4, 1}; }

  TestCase testB() { return {2, 5, 6, 2}; }

  TestCase testC() { return {1, 5, 3, 0}; }
};

class Solution {
public:
  int findClosest(int x, int y, int z) {
    // useful code here
    return 0;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.findClosest(unit.x, unit.y, unit.z)};

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
