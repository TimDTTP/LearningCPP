
#include <format>
#include <iostream>
#include <numeric>
#include <vector>

class Test {
public:
  struct TestCase {
    int n;
    std::vector<int> output;
  };

  TestCase testA() { return {5, {-7, -1, 1, 3, 4}}; }

  TestCase testB() { return {3, {-1, 0, 1}}; }

  TestCase testC() { return {1, {0}}; }
};

class Solution {
public:
  std::vector<int> sumZero(int n) {
    // useful code here
    return {};
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::vector<int> output{solCur.sumZero(unit.n)};

  // Test output
  int summation{std::accumulate(output.begin(), output.end(), 0)};
  if (summation == 0) {
    std::cout << "Success!\n";
  } else {
    std::cout << "Failed!\n";
    std::cout << std::format("Sum: {}\n{{", summation);
    for (int i : output) {
      std::cout << std::format("{} ", i);
    }
    std::cout << "}\n";
  }

  return 0;
}
