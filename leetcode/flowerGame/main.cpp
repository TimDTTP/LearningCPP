
#include <iostream>

class Test {
public:
  struct TestCase {
    int n;
    int m;
    long long output;
  };

  TestCase testA() { return {3, 2, 3}; }

  TestCase testB() { return {1, 1, 0}; }
};

class Solution {
public:
  long long flowerGame(int n, int m) {
    // useful code here
    return 0;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  long long output{solCur.flowerGame(unit.n, unit.m)};

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
