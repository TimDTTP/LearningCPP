
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> robot;
    std::vector<std::vector<int>> factory;
    long long output;
  };

  TestCase testA() {
    TestCase obj;
    obj.robot = {0, 4, 6};
    obj.factory = {{2, 2}, {6, 2}};
    obj.output = 4;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.robot = {1, -1};
    obj.factory = {{-2, 1}, {2, 1}};
    obj.output = 2;
    return obj;
  }
};

class Solution {
public:
  long long minimumTotalDistance(std::vector<int> &robot,
                                 std::vector<std::vector<int>> &factory) {}
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  long long output{solCur.minimumTotalDistance(unit.robot, unit.factory)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
