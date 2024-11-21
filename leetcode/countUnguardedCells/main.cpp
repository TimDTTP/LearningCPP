
#include <iostream>

class Test {
public:
  struct TestCase {
    int m;
    int n;
    std::vector<std::vector<int>> guards;
    std::vector<std::vector<int>> walls;
    int output;
  };

  TestCase testA() {
    TestCase obj;
    obj.m = 4;
    obj.n = 6;
    obj.guards = {{0, 0}, {1, 1}, {2, 3}};
    obj.walls = {{0, 1}, {2, 2}, {1, 4}};
    obj.output = 7;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.m = 3;
    obj.n = 3;
    obj.guards = {{1, 1}};
    obj.walls = {{0, 1}, {1, 0}, {2, 1}, {1, 2}};
    obj.output = 4;
    return obj;
  }
};

class Solution {
public:
  int countUnguarded(int m, int n, std::vector<std::vector<int>> &guards,
                     std::vector<std::vector<int>> &walls) {
    int out;
    return out;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.countUnguarded(unit.m, unit.n, unit.guards, unit.walls)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
