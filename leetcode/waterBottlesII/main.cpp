
#include <iostream>

class Test {
public:
  struct TestCase {
    int numBottles;
    int numExchanges;
    int output;
  };

  TestCase testA() { return {13, 6, 15}; }

  TestCase testB() { return {10, 3, 13}; }
};

class Solution {
public:
  int maxBottlesDrunk(int numBottles, int numExchanges) {
    int total{numBottles};
    while (numBottles >= numExchanges) {
      numBottles = numBottles - numExchanges + 1;
      total++;
      numExchanges++;
    }

    return total;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
  int output{solCur.maxBottlesDrunk(unit.numBottles, unit.numExchanges)};

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
