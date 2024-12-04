
#include <iostream>

class Test {
public:
  struct TestCase {
    std::string str1;
    std::string str2;
    bool output;
  };

  TestCase testA() { return {"abc", "ad", true}; }

  TestCase testB() { return {"zc", "ad", true}; }

  TestCase testC() { return {"ab", "d", false}; }
};

class Solution {
public:
  bool canMakeSubsequnce(std::string str1, std::string str2) {
    bool out;
    return out;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  bool output{solCur.canMakeSubsequnce(unit.str1, unit.str2)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
