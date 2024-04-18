
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

class Solution {
public:
  int islandPerimeter(std::vector<std::vector<int>> &grid) {}
};

int main() {
  Solution ans = Solution();

  std::vector<std::vector<int>> grid{test()};

  std::cout << ans.islandPerimeter(grid) << '\n';

  return 0;
}
