
#include <array>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int output;
  };

  TestCase testA() {
    TestCase obj;
    obj.grid = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
    obj.output = 3;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.grid = {{3, 2, 4}, {2, 1, 9}, {1, 1, 7}};
    obj.output = 0;
    return obj;
  }
};

class Solution {
private:
  void maxPerCell(std::vector<std::vector<int>> &grid, std::pair<int, int> cell,
                  int &max, int counter) {
    int moves{counter + 1};
    std::array<int, 3> directions{-1, 0, 1};

    for (int i : directions) {
      // bound check
      // x axis
      if (cell.first + 1 > grid.size())
        return;

      // y axis
      if (cell.second + i < 0 || cell.second + i >= grid[0].size())
        continue;

      // if greater than
      if (grid[cell.second + i][cell.first + 1] >
          grid[cell.second][cell.first]) {
        maxPerCell(grid, {cell.first + 1, cell.second + i}, max, moves);
      } else {
        max = std::max(max, counter);
      }
    }
  }

public:
  int maxMoves(std::vector<std::vector<int>> &grid) {
    int max{0};
    int counter{0};

    for (int i{0}; i < grid.size(); i++) {
      counter = 0;
      maxPerCell(grid, {0, i}, max, counter);
    }

    return max;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.maxMoves(unit.grid)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
