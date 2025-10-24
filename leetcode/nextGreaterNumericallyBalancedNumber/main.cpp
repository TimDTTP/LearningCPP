
#include <iostream>

class Test {
public:
  struct TestCase {
    int n;
    int output;
  };

  TestCase testA() { return {1, 22}; }

  TestCase testB() { return {1000, 1333}; }

  TestCase testC() { return {3000, 3133}; }
};

class Solution {
public:
  int nextBeautifulNumber(int n) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.nextBeautifulNumber(unit.n)};

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
