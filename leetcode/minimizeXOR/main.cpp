
#include <iostream>

class Test {
public:
  struct TestCase {
    int num1;
    int num2;
    int output;
  };

  TestCase testA() { return {3, 5, 3}; }

  TestCase testB() { return {1, 12, 3}; }
};

class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int out;
    return out;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.minimizeXor(unit.num1, unit.num2)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
