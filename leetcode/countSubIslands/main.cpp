
#include <iostream>
#include <vector>

struct testCase {
  std::vector<std::vector<int>> grid1;
  std::vector<std::vector<int>> grid2;
  int expectedSolution;
};

testCase testA() {
  testCase obj;
  obj.grid1 = {{1, 1, 1, 0, 0},
               {0, 1, 1, 1, 1},
               {0, 0, 0, 0, 0},
               {1, 0, 0, 0, 0},
               {1, 1, 0, 1, 1}};
  obj.grid2 = {{1, 1, 1, 0, 0},
               {0, 0, 1, 1, 1},
               {0, 1, 0, 0, 0},
               {1, 0, 1, 1, 0},
               {0, 1, 0, 1, 0}};

  obj.expectedSolution = 3;

  return obj;
}

testCase testB() {
  testCase obj;
  obj.grid1 = {{1, 0, 1, 0, 1},
               {1, 1, 1, 1, 1},
               {0, 0, 0, 0, 0},
               {1, 1, 1, 1, 1},
               {1, 0, 1, 0, 1}};
  obj.grid2 = {{0, 0, 0, 0, 0},
               {1, 1, 1, 1, 1},
               {0, 1, 0, 1, 0},
               {0, 1, 0, 1, 0},
               {1, 0, 0, 0, 1}};

  obj.expectedSolution = 2;

  return obj;
}

class Solution {
private:
  bool BFS(int n, int m, bool cmp, std::vector<std::vector<int>> &grid1,
           std::vector<std::vector<int>> &grid2,
           std::vector<std::vector<int>> &visited) {
    // base case; if already visited or is NOT land
    if (visited[n][m] == 1 || grid2[n][m] == 0)
      return cmp;

    // if land and if grid1 is not land
    if (grid2[n][m] == 1) {
      visited[n][m] = 1;

      if (grid1[n][m] != 1)
        cmp = false;
    }

    // check above
    if (n > 0)
      cmp = BFS(n - 1, m, cmp, grid1, grid2, visited);
    // check right
    if (m < grid2[0].size() - 1)
      cmp = BFS(n, m + 1, cmp, grid1, grid2, visited);
    // check down
    if (n < grid2.size() - 1)
      cmp = BFS(n + 1, m, cmp, grid1, grid2, visited);
    // check left
    if (m > 0)
      cmp = BFS(n, m - 1, cmp, grid1, grid2, visited);

    return cmp;
  }

  // WARNING: Delete when submitting
  void printVecVecInt(std::vector<std::vector<int>> vec) {
    for (std::vector<int> a : vec) {
      for (int b : a) {
        std::cout << b << ' ';
      }
      std::cout << '\n';
    }
  }

public:
  int countSubIslands(std::vector<std::vector<int>> &grid1,
                      std::vector<std::vector<int>> &grid2) {
    int subIslands{0};
    // find all islands on grid2
    //
    // Track all visited nodes
    std::vector<std::vector<int>> visited{};
    for (int i{0}; i < grid2.size(); i++) {
      visited.push_back({});
      for (int j{0}; j < grid2[0].size(); j++) {
        visited[i].push_back(0);
      }
    }

    // per island if all land is in grid2
    bool cmp;
    // iterate through and find land
    for (int n{0}; n < grid2.size(); ++n) {
      for (int m{0}; m < grid2[0].size(); ++m) {
        // skip if already visited
        if (visited[n][m] == 1)
          continue;

        // if land is founded, perform BFS
        if (grid2[n][m] == 1) {
          cmp = true;
          if (BFS(n, m, cmp, grid1, grid2, visited))
            ++subIslands;
        }

        visited[n][m] = 1;
      }
    }

    return subIslands;
  }
};

int main() {
  Solution cursor = Solution();

  testCase test{testA()};

  int out = cursor.countSubIslands(test.grid1, test.grid2);

  if (test.expectedSolution == out)
    std::cout << "Success!\n" << std::endl;
  else {
    std::cout << "Fail!\n";
    std::cout << "Expected: " << test.expectedSolution << '\n';
    std::cout << "Actual: " << out << '\n' << std::endl;
  }

  return 0;
}
