
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> candidates;
    int output;
  };

  TestCase testA() {
    TestCase obj{{16, 17, 71, 62, 24, 14}, 4};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{8, 8}, 2};
    return obj;
  }
};

class Solution {
public:
  int largestCombination(std::vector<int> &candidates) {}
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.largestCombination(unit.candidates)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
