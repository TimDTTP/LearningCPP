
#include <iostream>
#include <string>

class Test {
public:
  struct TestCase {
    std::string s;
    int output;
  };

  TestCase testA() {
    TestCase obj{"1001", 2};
    return obj;
  }

  TestCase testB() {
    TestCase obj{"10", 1};
    return obj;
  }

  TestCase testC() {
    TestCase obj{"0000", 0};
    return obj;
  }
};

class Solution {
public:
  int minChanges(std::string s) {}
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.minChanges(unit.s)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
