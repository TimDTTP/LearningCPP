
#include <functional>
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

class Solution {
private:
  void BFS(int n, int m, int islandCounter,
           std::vector<std::vector<std::pair<int, int>>> &foundIslands,
           std::vector<std::vector<int>> &grid2,
           std::vector<std::vector<int>> &visited) {
    // base case; if already visited or is NOT land
    if (visited[n][m] == 1 || grid2[n][m] == 0)
      return;

    // if land
    if (grid2[n][m] == 1) {
      visited[n][m] = 1;
      foundIslands[islandCounter - 1].push_back({n, m});
    }

    // check above
    if (n > 0)
      BFS(n - 1, m, islandCounter, foundIslands, grid2, visited);
    // check right
    if (m < grid2[0].size() - 1)
      BFS(n, m + 1, islandCounter, foundIslands, grid2, visited);
    // check down
    if (n < grid2.size() - 1) {
      BFS(n + 1, m, islandCounter, foundIslands, grid2, visited);
    }
    // check left
    if (m > 0)
      BFS(n, m - 1, islandCounter, foundIslands, grid2, visited);
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

    // store coordinate of found islands on grid2
    int islandCounter{0};
    std::vector<std::vector<std::pair<int, int>>> foundIslands{};

    // iterate through and find land
    for (int n{0}; n < grid2.size(); ++n) {
      for (int m{0}; m < grid2[0].size(); ++m) {
        // skip if already visited
        if (visited[n][m] == 1)
          continue;

        // if land is founded, add to vector islands and perform BFS
        if (grid2[n][m] == 1) {
          // counter tracks how many islands thus far
          ++islandCounter;

          // init vector
          foundIslands.push_back({});

          // invoke lambda function
          BFS(n, m, islandCounter, foundIslands, grid2, visited);
        }
      }
    }

    return 0;
  }
};

int main() {
  Solution cursor = Solution();

  testCase test{testA()};

  cursor.countSubIslands(test.grid1, test.grid2);

  return 0;
}
