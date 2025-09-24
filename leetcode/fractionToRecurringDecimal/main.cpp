
#include <iostream>

class Test {
public:
  struct TestCase {
    int numerator;
    int denominator;
    std::string output;
  };

  TestCase testA() { return {1, 2, "0.5"}; }

  TestCase testB() { return {2, 1, "2"}; }

  TestCase testC() { return {4, 333, "0.(012)"}; }
};

class Solution {
public:
  std::string fractionToDecimal(int numerator, int denominator) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::string output{
      solCur.fractionToDecimal(unit.numerator, unit.denominator)};

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
