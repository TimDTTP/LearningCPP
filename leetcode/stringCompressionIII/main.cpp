
#include <iostream>

class Test {
public:
  struct TestCase {
    std::string word;
    std::string output;
  };

  TestCase testA() {
    TestCase obj{"abcde", "1a1b1c1d1e"};
    return obj;
  }

  TestCase testB() {
    TestCase obj{"aaaaaaaaaaaaaabb", "9a5a2b"};
    return obj;
  }
};

class Solution {
public:
  std::string compressedString(std::string word) {
    std::string comp;
    return comp;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::string output{solCur.compressedString(unit.word)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
