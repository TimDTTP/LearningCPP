
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> values;
    int output;
  };

  TestCase testA() { return {{1, 2, 3}, 6}; }

  TestCase testB() { return {{3, 7, 4, 5}, 144}; }

  TestCase testC() { return {{1, 3, 1, 4, 1, 5}, 13}; }

  TestCase testD() { return {{2, 1, 4, 4}, 24}; }
};

class Solution {
public:
  int dp[50][50] = {};

  int minScoreTriangulation(std::vector<int> &values, int i = 0, int j = 0,
                            int res = 0) {
    if (j == 0)
      j = values.size() - 1;
    if (dp[i][j] != 0)
      return dp[i][j];
    for (int k = i + 1; k < j; ++k) {
      res = std::min(res == 0 ? INT_MAX : res,
                     minScoreTriangulation(values, i, k) +
                         values[i] * values[k] * values[j] +
                         minScoreTriangulation(values, k, j));
    }
    return dp[i][j] = res;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  int output{solCur.minScoreTriangulation(unit.values)};

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
