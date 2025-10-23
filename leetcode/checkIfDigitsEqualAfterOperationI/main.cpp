
#include <iostream>
#include <string>

class Test {
public:
  struct TestCase {
    std::string s;
    bool output;
  };

  TestCase testA() { return {"3902", true}; }

  TestCase testB() { return {"34789", false}; }
};

class Solution {
public:
  bool hasSameDigits(std::string s) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  bool output{solCur.hasSameDigits(unit.s)};

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
