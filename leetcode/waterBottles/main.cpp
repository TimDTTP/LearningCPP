
#include <iostream>

class Test {
public:
  struct TestCase {
    int numBottles;
    int numExchanges;
    int output;
  };

  TestCase testA() { return {9, 3, 13}; }

  TestCase testB() { return {15, 4, 19}; }
};

class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.numWaterBottles(unit.numBottles, unit.numExchanges)};

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
