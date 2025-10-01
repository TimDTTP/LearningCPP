
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
    int total{numBottles};
    int add{0};
    int rem{0};
    while (numBottles >= numExchange) {
      add = numBottles / numExchange;
      rem = numBottles % numExchange;
      total += add;
      numBottles = add + rem;
    }
    return total;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
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
