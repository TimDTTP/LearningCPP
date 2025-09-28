
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<std::vector<int>> triangle;
    int output;
  };

  TestCase testA() { return {{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, 11}; }

  TestCase testB() { return {{{-10}}, -10}; }
};

class Solution {
public:
  int minimumTotal(std::vector<std::vector<int>> triangle) {
    for (int i{static_cast<int>(triangle.size()) - 2}; i >= 0; i--) {
      for (int j{0}; j < triangle[i].size(); j++) {
        triangle[i][j] = std::min((triangle[i][j] + triangle[i + 1][j]),
                                  (triangle[i][j] + triangle[i + 1][j + 1]));
      }
    }
    return triangle[0][0];
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
  int output{solCur.minimumTotal(unit.triangle)};

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
