
#include <iostream>
#include <unordered_set>
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
  int islandPerimeter(std::vector<std::vector<int>> &grid) {
    int perimeter{0};
    std::unordered_set<int> previous{};
    std::unordered_set<int> current{};

    for (int row{0}; row < grid.size(); ++row) {
      for (int col{0}; col < grid[0].size(); ++col) {
        if (grid[row][col] == 1) {
          current.insert(col);

          // if found in vector
          if (previous.find(col) != previous.end()) 
            perimeter -= 2;
        }
      }
      perimeter += current.size() * 2 + 2;

      previous = current;
      current.clear();
    }

    return perimeter;
  }
};

int main() {
  Solution ans = Solution();

  std::vector<std::vector<int>> grid{test()};

  std::cout << ans.islandPerimeter(grid) << '\n';

  return 0;
}
