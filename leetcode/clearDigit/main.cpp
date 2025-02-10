
#include <iostream>
#include <string>

class Test {
public:
  struct TestCase {
    std::string s;
    std::string output;
  };

  TestCase testA() { return {"abc", "abc"}; }

  TestCase testB() { return {"cb34", ""}; }
};

class Solution {
public:
  std::string clearDigits(std::string s) {
    std::string out{s};
    return out;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::string output{solCur.clearDigits(unit.s)};

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
