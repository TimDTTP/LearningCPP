
#include <functional>
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
  int countSubIslands(std::vector<std::vector<int>> &grid1,
                      std::vector<std::vector<int>> &grid2) {
    // find all islands on grid2
    //
    // Track all visited nodes
    std::vector<std::vector<int>> visited;
    for (int i{0}; i < grid1.size(); ++i) {
      for (int j{0}; j < grid2.size(); ++j) {
        visited[i][j] = 0;
      }
    }

    // store coordinate of found islands on grid2
    int islandCounter{0};
    std::vector<std::vector<std::pair<int, int>>> foundIslands;

    // iterate through and find land
    for (int n{0}; n < grid2.size(); ++n) {
      for (int m{0}; m < grid2.size(); ++m) {
        // skip if already visited
        if (visited[n][m] == 1)
          continue;

        // mark visited unit
        visited[n][m] = 1;

        // if land is founded, add to vector islands and perform BFS
        if (grid2[n][m] == 1) {
          // counter tracks how many islands thus far
          ++islandCounter;

          // perform BFS on unvisited units
          std::function<void(
              int, int, int, std::vector<std::vector<std::pair<int, int>>> &,
              std::vector<std::vector<int>> &, std::vector<std::vector<int>> &)>
              BFS = [&](int n, int m, int islandCounter,
                        std::vector<std::vector<std::pair<int, int>>>
                            &foundIslands,
                        std::vector<std::vector<int>> &grid2,
                        std::vector<std::vector<int>> &visited) {
                // base case; if already visited
                if (visited[n][m] == 1)
                  return;

                // if land
                if (grid2[n][m] == 1) {
                  visited[n][m] = 1;
                  foundIslands[islandCounter].push_back({n, m});
                }

                // check above
                if (n > 0)
                  BFS(n - 1, m, islandCounter, foundIslands, grid2, visited);
                // check right
                if (m < grid2[0].size() - 1)
                  BFS(n, m + 1, islandCounter, foundIslands, grid2, visited);
                // check down
                if (n < grid2.size() - 1)
                  BFS(n + 1, m, islandCounter, foundIslands, grid2, visited);
                // check left
                if (m > 0)
                  BFS(n, m - 1, islandCounter, foundIslands, grid2, visited);
              };

          // invoke lambda function
          BFS(n, m, islandCounter, foundIslands, grid2, visited);
        }
      }
    }

    return 0;
  }
};

int main() { return 0; }
