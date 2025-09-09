
#include <iostream>

class Test {
public:
  struct TestCase {
    int n;
    int delay;
    int forget;
    int output;
  };

  TestCase testA() { return {6, 2, 4, 5}; }

  TestCase testB() { return {4, 1, 3, 6}; }
};

class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    // some useful
    // code here
    return 0;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.peopleAwareOfSecret(unit.n, unit.delay, unit.forget)};

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
