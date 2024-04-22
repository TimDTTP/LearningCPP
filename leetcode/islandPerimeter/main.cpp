
#include <iostream>
#include <vector>

std::vector<std::vector<int>> test() {
  std::vector<std::vector<int>> grid{
      {0, 1, 0, 0},
      {1, 1, 1, 0},
      {0, 1, 0, 0},
      {1, 1, 0, 0},
  };

  return grid;
}

std::vector<std::vector<int>> test1() {
  std::vector<std::vector<int>> grid{
      {1},
      {0},
  };

  return grid;
}

std::vector<std::vector<int>> test2() {
  std::vector<std::vector<int>> grid{
      {1, 1, 1, 1},
      {1, 0, 1, 1},
  };

  return grid;
}

std::vector<std::vector<int>> test3() {
  std::vector<std::vector<int>> grid{
      {0, 1, 0, 0},
      {1, 1, 1, 0},
      {0, 1, 0, 0},
      {1, 1, 0, 0},
  };

  return grid;
}

std::vector<std::vector<int>> test4() {
  std::vector<std::vector<int>> grid{
      {1, 0, 1},
      {1, 1, 1},
  };

  return grid;
}

class Solution {
private:
  int dfs(std::vector<std::vector<int>> &grid, int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
        grid[r][c] == 0)
      return 1;
    if (grid[r][c] == -1)
      return 0;

    grid[r][c] = -1;

    return (dfs(grid, r - 1, c) + dfs(grid, r + 1, c) + dfs(grid, r, c - 1) +
            dfs(grid, r, c + 1));
  }

public:
  int islandPerimeter(std::vector<std::vector<int>> &grid) {
    size_t row{grid.size()};
    size_t col{grid[0].size()};
    int perimeter{0};

    for (int i{0}; i < row; ++i) {
      for (int j{0}; j < col; ++j) {
        if (grid[i][j] == 1)
          perimeter += dfs(grid, i, j);
      }
    }

    return perimeter;
  }
};

int main() {
  Solution ans = Solution();

  std::vector<std::vector<int>> grid{test1()};

  std::cout << ans.islandPerimeter(grid) << '\n';

  return 0;
}
