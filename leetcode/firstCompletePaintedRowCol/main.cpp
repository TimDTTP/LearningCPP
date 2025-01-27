
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> arr;
    std::vector<std::vector<int>> mat;
    int output;
  };

  TestCase testA() {
    TestCase obj;
    obj.arr = {1, 3, 4, 2};
    obj.mat = {{1, 4}, {2, 3}};
    obj.output = 2;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.arr = {2, 8, 7, 4, 1, 3, 5, 6, 9};
    obj.mat = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    obj.output = 3;
    return obj;
  }
};

class Solution {
public:
  int firstCompleteIndex(std::vector<int> &arr,
                         std::vector<std::vector<int>> &mat) {
    int out;
    return out;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.firstCompleteIndex(unit.arr, unit.mat)};

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
