
#include <iostream>
#include <string>

class Test {
public:
  struct TestCase {
    std::string s;
    int output;
  };

  TestCase testA() { return {"abaacbcbb", 5}; }

  TestCase testB() { return {"aa", 2}; }
};

class Solution {
public:
  int minimumLength(std::string s) {
    int out{0};
    return out;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.minimumLength(unit.s)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
