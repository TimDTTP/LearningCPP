
#include <iostream>
#include <stack>
#include <vector>

struct TestCase {
  std::vector<std::vector<int>> grid;
  int expected;
};

TestCase test1() {
  TestCase obj;
  obj.grid = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };
  obj.expected = 13;

  return obj;
}

class Solution {
public:
  int minFallingPathSum(std::vector<std::vector<int>> &grid) {
    int length = grid.size();
    int res{INT_MAX};

    // mirror array to track min value
    std::vector<std::vector<int>> dp(length, std::vector<int>(length, -1));

    for (int i{0}; i < length; ++i)
      dp[0][i] = grid[0][i];

    /*
     * Fill in dp array
     * i = iterate through rows
     * j = iterate through columns
     * k = iterate through columns but one above
     */
    for (int i{1}; i < length; ++i) {
      for (int j{0}; j < length; ++j) {
        int temp{INT_MAX};
        for (int k{0}; k < length; ++k) {
          if (k != j)
            temp = std::min(temp, grid[i][j] + dp[i - 1][k]);

          // store min path for current element
          dp[i][j] = temp;
        }
      }
    }

    // find min in last row of dp
    for (int i{0}; i < length; ++i)
      res = std::min(res, dp[length - 1][i]);

    return res;
  }
};

int main() {
  TestCase input{test1()};
  Solution answer = Solution();

  int print{answer.minFallingPathSum(input.grid)};

  std::cout << "Expected: " << '\n';
  std::cout << input.expected << "\n\n";

  std::cout << "Actual: " << '\n';
  std::cout << print << '\n';

  return 0;
}
