
#include <format>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    int n;
    std::vector<int> output;
  };

  TestCase testA() { return {2, {1, 1}}; }
  TestCase testB() { return {11, {2, 9}}; }
};

class Solution {
public:
  std::vector<int> getNoZeroIntegers(int n) {
    // useful code here
    return {};
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::vector<int> output{solCur.getNoZeroIntegers(unit.n)};

  if (output[0] + output[1] == unit.n) {
    std::cout << "Success!\n";
  } else {
    std::cout << "Failed!\n{";
  }
  std::cout << std::format("[{}, {}]", output[0], output[1]);

  return 0;
}
