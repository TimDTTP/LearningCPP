
#include <algorithm>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<std::vector<int>> input;
    std::vector<std::vector<int>> output;
  };

  void print(std::vector<std::vector<int>> mat) {
    for (std::vector<int> row : mat) {
      for (int col : row) {
        std::cout << col << ' ';
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  TestCase testA() {
    TestCase obj;
    obj.input = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
    obj.output = {{8, 2, 3}, {9, 6, 7}, {4, 5, 1}};
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.input = {{0, 1}, {1, 2}};
    obj.output = {{2, 1}, {1, 0}};
    return obj;
  }
};

class Solution {
public:
  std::vector<std::vector<int>>
  sortMatrix(std::vector<std::vector<int>> &grid) {
    int size = grid[0].size();

    std::vector<int> temp{};
    std::pair<int, int> coord{};

    // sort bottom left
    for (int i{size - 2}; i >= 0; --i) {
      for (int j{0}; j + i < size; ++j) {
        temp.push_back(grid[i + j][j]);
      }
      std::sort(temp.begin(), temp.end(), std::greater<int>());

      coord.first = i;
      coord.second = 0;
      while (!temp.empty()) {
        grid[coord.first][coord.second] = temp[0];
        temp.erase(temp.begin());
        ++coord.first;
        ++coord.second;
      }
    }

    // sort top right
    for (int i{1}; i < size; ++i) {
      for (int j{0}; j + i < size; ++j) {
        temp.push_back(grid[j][i + j]);
        std::sort(temp.begin(), temp.end());
      }

      coord.first = 0;
      coord.second = i;
      while (!temp.empty()) {
        grid[coord.first][coord.second] = temp[0];
        temp.erase(temp.begin());
        ++coord.first;
        ++coord.second;
      }
    }

    return grid;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
  std::vector<std::vector<int>> output{solCur.sortMatrix(unit.input)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: \n";
    testCur.print(unit.output);
    std::cout << "Actual: \n";
    testCur.print(output);
  }
  std::cout << std::endl;

  return 0;
}
