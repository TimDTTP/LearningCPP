
#include <iostream>
#include <string>

class Test {
public:
  struct TestCase {
    std::string s1;
    std::string s2;
    bool output;
  };

  TestCase testA() {
    TestCase obj;
    obj.s1 = "bank";
    obj.s2 = "kanb";
    obj.output = true;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.s1 = "attack";
    obj.s2 = "defend";
    obj.output = false;
    return obj;
  }

  TestCase testC() {
    TestCase obj;
    obj.s1 = "kelb";
    obj.s2 = "kelb";
    obj.output = true;
    return obj;
  }
};

class Solution {
public:
  bool areAlmostEqual(std::string s1, std::string s2) {
    bool out;
    return out;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  bool output{solCur.areAlmostEqual(unit.s1, unit.s2)};

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
