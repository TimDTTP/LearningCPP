
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> array;
    int output;
  };

  TestCase testA() {
    TestCase obj{{1, 3, 1}, 0};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{2, 1, 1, 5, 6, 2, 3, 1}, 3};
    return obj;
  }
};

class Solution {
public:
  int minimumMountainRemovals(std::vector<int> &nums) {}
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.minimumMountainRemovals(unit.array)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
