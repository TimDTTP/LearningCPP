
#include <iostream>
#include <string>
#include <vector>

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
    int size = s.size();
    std::vector<int> vs;

    // insert s into vs
    for (char num : s) {
      vs.push_back(num - '0');
    }

    // perform operation
    for (int i{0}; i < (size - 2); ++i) {
      for (int j{0}; j < (vs.size() - i - 1); ++j) {
        vs[j] = (vs[j] + vs[j + 1]) % 10;
      }
    }

    return (vs[0] == vs[1]);
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
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
