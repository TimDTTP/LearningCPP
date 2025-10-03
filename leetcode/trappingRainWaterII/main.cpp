
#include <iostream>
#include <queue>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<std::vector<int>> heightMap;
    int output;
  };

  TestCase testA() {
    return {{{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}}, 4};
  }

  TestCase testB() {
    return {{{3, 3, 3, 3, 3},
             {3, 2, 2, 2, 3},
             {3, 2, 1, 2, 3},
             {3, 2, 2, 2, 3},
             {3, 3, 3, 3, 3}},
            10};
  }
};

class Solution {
public:
  int trapRainWater(std::vector<std::vector<int>> &heightMap) {
    std::vector<std::vector<int>> visited{};
    std::queue<std::pair<int, int>> children{};
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.trapRainWater(unit.heightMap)};

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
