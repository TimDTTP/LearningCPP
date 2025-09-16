
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> output;
  };

  TestCase testA() { return {{6, 4, 3, 2, 7, 6, 2}, {12, 7, 6}}; }

  TestCase testB() { return {{2, 2, 1, 1, 3, 3, 3}, {2, 1, 1, 3}}; }

  void printVec(std::vector<int> arr) {
    std::cout << "[";
    for (int i : arr) {
      std::cout << i << ", ";
    }
    std::cout << ']' << std::endl;
  }
};

class Solution {
public:
  std::vector<int> replaceNonCoprimes(std::vector<int> &nums) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::vector<int> output{solCur.replaceNonCoprimes(unit.nums)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: ";
    testCur.printVec(unit.output);
    std::cout << "Actual: ";
    testCur.printVec(output);
  }
  std::cout << std::endl;

  return 0;
}
