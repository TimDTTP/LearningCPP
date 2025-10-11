
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> power;
    long long output;
  };

  TestCase testA() { return {{1, 1, 3, 4}, 6}; }
  TestCase testB() { return {{7, 1, 6, 6}, 13}; }
};

class Solution {
public:
  long long maximumTotalDamage(std::vector<int> &power) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  long long output{solCur.maximumTotalDamage(unit.power)};

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
