
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> input;
    int target;
    int output;
  };

  TestCase testA() {
    TestCase obj;
    obj.input = {1, 3, 5, 6};
    obj.target = 5;
    obj.output = 2;

    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.input = {1, 3, 5, 6};
    obj.target = 2;
    obj.output = 1;

    return obj;
  }

  TestCase testC() {
    TestCase obj;
    obj.input = {1, 3, 5, 6};
    obj.target = 7;
    obj.output = 4;

    return obj;
  }
};

class Solution {
public:
  int searchInsert(std::vector<int> &nums, int target) {}
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase input{testCur.testA()};
  int output{solCur.searchInsert(input.input, input.target)};

  if (output == input.output) {
    std::cout << "Success!\n";
  } else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << input.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;

  return 0;
}
