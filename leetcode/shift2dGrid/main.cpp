
#include <iostream>
#include <string>
#include <vector>

class Test {
private:
  int numLength(int x) {
    std::string s{std::to_string(x)};

    return s.length();
  }

public:
  // proper spacing for double digits
  void print(std::vector<std::vector<int>> v) {
    int n = v.size();
    int m = v[0].size();

    // print
    for (int i{0}; i < n; ++i) {
      for (int j{0}; j < m; ++j) {
        std::cout << v[i][j];
        // spaces
        for (int s{7 - (numLength(v[i][j]))}; s > 0; --s) {
          std::cout << ' ';
        }
      }
      std::cout << std::endl;
    }
  }

  struct TestCase {
    std::vector<std::vector<int>> grid;
    int k;
    std::vector<std::vector<int>> expected;
  };

  TestCase testA() {
    return {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
            1,
            {{9, 1, 2}, {3, 4, 5}, {6, 7, 8}}};
  }
  TestCase testB() {
    return {{{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}},
            4,
            {{12, 0, 21, 13}, {3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}}};
  }
  TestCase testC() {
    return {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
            9,
            {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
  }
  TestCase testD() {
    return {{{1}, {2}, {3}, {4}, {7}, {6}, {5}},
            23,
            {{6}, {5}, {1}, {2}, {3}, {4}, {7}}};
  }

  std::vector<TestCase> all() { return {testA(), testB(), testC(), testD()}; };
};

class Solution {
public:
  std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>> &grid,
                                          int k) {
    int n = grid.size();
    int m = grid[0].size();

    std::vector<int> vals{};
    for (int i{0}; i < n; ++i) {
      for (int j{0}; j < m; ++j) {
        vals.push_back(grid[i][j]);
      }
    }

    std::pair<int, int> coord{};
    coord.first = ((k / m) < (n - 1) ? (k / m) : ((k / m) % n));
    coord.second = k % m;
    // populate tail
    for (int i : vals) {
      grid[coord.first][coord.second] = i;
      ++coord.second;
      if (coord.second >= m) {
        coord.second = 0;
        ++coord.first;
        if (coord.first >= n) {
          coord.first = 0;
        }
      }
    }

    return grid;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    std::vector<std::vector<int>> result = sol.shiftGrid(unit.grid, unit.k);

    if (result == unit.expected) {
      std::cout << "✅ Test " << i + 1 << " passed!\n";
      ++passed;
    } else {
      std::cout << "❌ Test " << i + 1 << " failed!\n";
      std::cout << "Expected:\n";
      tests.print(unit.expected);
      std::cout << "Got:\n";
      tests.print(result);
    }
  }
  std::cout << "\nSummary: " << passed << "/" << cases.size()
            << " tests passed.\n";

  return 0;
}
