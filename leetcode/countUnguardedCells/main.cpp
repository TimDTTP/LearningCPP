
#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Test {
public:
  struct TestCase {
    int m;
    int n;
    std::vector<std::vector<int>> guards;
    std::vector<std::vector<int>> walls;
    int output;
  };

  TestCase testA() {
    TestCase obj;
    obj.m = 4;
    obj.n = 6;
    obj.guards = {{0, 0}, {1, 1}, {2, 3}};
    obj.walls = {{0, 1}, {2, 2}, {1, 4}};
    obj.output = 7;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.m = 3;
    obj.n = 3;
    obj.guards = {{1, 1}};
    obj.walls = {{0, 1}, {1, 0}, {2, 1}, {1, 2}};
    obj.output = 4;
    return obj;
  }
};

class Solution {
  // WARNING: TEST
  void print(std::vector<bool> vec) {
    std::cout << "printing...\n";
    for (int i{0}; i < vec.size(); i++) {
      std::cout << i << ' ' << vec[i] << '\n';
    }
  }

  void printTable(std::vector<bool> tab, int n) {
    for (int i{0}; i < tab.size(); i++) {
      if (i % n == 0) {
        std::cout << std::endl;
      }
      std::cout << tab[i] << ' ';
    }
  }

public:
  int countUnguarded(int m, int n, std::vector<std::vector<int>> &guards,
                     std::vector<std::vector<int>> &walls) {
    std::unordered_map<int, std::unordered_set<int>> mObstructions;
    std::unordered_map<int, std::unordered_set<int>> nObstructions;
    std::vector<bool> track(m * n, 0);

    // handle walls
    for (std::vector<int> w : walls) {
      track[w[0] * n + w[1]] = 1;
      mObstructions[w[0]].insert(w[1]);
      nObstructions[w[1]].insert(w[0]);
    }

    // handle guards
    for (std::vector<int> g : guards) {
      track[g[0] * n + g[1]] = 1;
      mObstructions[g[0]].insert(g[1]);
      nObstructions[g[1]].insert(g[0]);
    }

    // track guarded cells
    for (std::vector<int> g : guards) {
      // up
      if (g[0] > 0) {
        for (int u{g[0] - 1}; u >= 0; u--) {
          if (nObstructions[g[1]].count(u)) {
            break;
          } else {
            track[u * n + g[1]] = 1;
          }
        }
      }

      // right
      if (g[1] < n) {
        for (int r{g[1] + 1}; r < n; r++) {
          if (mObstructions[g[0]].count(r)) {
            break;
          } else {
            track[g[0] * n + r] = 1;
          }
        }
      }

      // down
      if (g[0] < m) {
        for (int d{g[0] + 1}; d < m; d++) {
          if (nObstructions[g[1]].count(d)) {
            break;
          } else {
            track[d * n + g[1]] = 1;
          }
        }
      }

      // left
      if (g[1] > 0) {
        for (int l{g[1] - 1}; l >= 0; l--) {
          if (mObstructions[g[0]].count(l)) {
            break;
          } else {
            track[g[0] * n + l] = 1;
          }
        }
      }
    }
    printTable(track, n);
    std::cout << std::endl;

    int count{0};
    for (int i : track) {
      count += i;
    }

    return m * n - count;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.countUnguarded(unit.m, unit.n, unit.guards, unit.walls)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
