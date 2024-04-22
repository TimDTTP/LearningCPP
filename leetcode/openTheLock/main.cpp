
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

struct testCases {
  std::vector<std::string> deadends{};
  std::string target;
};

testCases test1() {
  testCases obj{};
  obj.deadends = {"8887", "8889", "8878", "8898",
                  "8788", "8988", "7888", "9888"};
  obj.target = "8888";

  return obj;
}

class Solution {
public:
  int openLock(std::vector<std::string> &deadends, std::string target) {
    std::unordered_set<std::string> dead{deadends.begin(), deadends.end()};
    std::queue<std::pair<std::string, int>> queue{};
    std::unordered_set<std::string> visited{};

    // edge cases
    if (target == "0000")
      return 0;

    if (dead.count("0000"))
      return -1;

    // Set up BFS
    queue.push({"0000", 0});
    visited.insert("0000");

    // BFS
    while (!queue.empty()) {
      std::pair<std::string, int> current = queue.front();
      queue.pop();

      std::string combo{current.first};
      int moves{current.second};

      if (combo == target)
        return moves;

      for (int digit{0}; digit < 4; digit++) {
        for (int delta : {-1, 1}) {
          int newVal{(combo[digit] + delta + 10) % 10};
          std::string newCombo{combo};
          newCombo[digit] = newVal;

          if (dead.find(newCombo) == dead.end() &&
              visited.find(newCombo) == visited.end()) {
            visited.insert(newCombo);
            queue.push({newCombo, moves + 1});
          }
        }
      }
    }

    // No possible solutions
    return -1;
  }
};

int main() {
  Solution ans = Solution();

  testCases test{test1()};
  std::cout << ans.openLock(test.deadends, test.target) << '\n';

  return 0;
}
