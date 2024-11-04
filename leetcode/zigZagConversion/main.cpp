
#include <iostream>

class Test {
public:
  struct TestCase {
    std::string s;
    int numRows;
    std::string output;
  };

  TestCase testA() {
    TestCase obj;
    obj.s = "PAYPALISHIRING";
    obj.numRows = 3;
    obj.output = "PAHNAPLSIIGYIR";
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.s = "PAYPALISHIRING";
    obj.numRows = 4;
    obj.output = "PINALSIGYAHRPI";
    return obj;
  }

  TestCase testC() {
    TestCase obj;
    obj.s = "A";
    obj.numRows = 1;
    obj.output = "A";
    return obj;
  }
};

class Solution {
public:
  std::string convert(std::string s, int numRows) {}
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::string output{solCur.convert(unit.s, unit.numRows)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
