
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int maximumBit;
    std::vector<int> output;
  };

  TestCase testA() {
    TestCase obj{{0, 1, 1, 3}, 2, {0, 3, 2, 3}};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{2, 3, 4, 7}, 3, {5, 2, 6, 5}};
    return obj;
  }

  TestCase testC() {
    TestCase obj{{0, 1, 2, 2, 5, 7}, 3, {4, 3, 6, 4, 6, 7}};
    return obj;
  }
};

class Solution {
public:
  std::vector<int> getMaximumXor(std::vector<int> &nums, int maximumBit) {
    return nums;
  }
};

void printVector(std::vector<int> output) {
  for (int i : output) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::vector<int> output{solCur.getMaximumXor(unit.nums, unit.maximumBit)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: ";
    printVector(unit.output);
    std::cout << "Actual:   ";
    printVector(output);
  }
  std::cout << std::endl;
}
