
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>

class Test {
public:
  struct TestCase {
    std::vector<std::vector<int>> points;
    int output;
  };

  TestCase testA() { return {{{1, 1}, {2, 2}, {3, 3}}, 0}; }

  TestCase testB() { return {{{6, 2}, {4, 4}, {2, 6}}, 2}; }

  TestCase testC() { return {{{3, 1}, {1, 3}, {1, 1}}, 2}; }
};

class Solution {
public:
  int numberOfPairs(std::vector<std::vector<int>> &points) {
    std::map<int, std::vector<int>, std::less<int>> pointMap{};

    // insert
    for (std::vector<int> point : points) {
      pointMap[point[0]].push_back(point[1]);
    }

    for (std::pair<int, std::vector<int>> point : pointMap) {
      std::sort(point.second.begin(), point.second.end(), std::greater<int>());
    }

    int total{0};
    int count, lower, upper;

    // TEST:
    for (std::pair<int, std::vector<int>> i : pointMap) {
      std::cout << i.first << ": ";
      for (int j : i.second) {
        std::cout << j << ' ';
      }
      std::cout << std::endl;
    }

    // iterate left -> right
    for (int xPos{0}; xPos < pointMap.size(); ++xPos) {
      std::cout << xPos << '\n';
      // iterate up -> down
      for (int yPos{0}; yPos < pointMap[xPos].size(); ++yPos) {
        count = 0;
        upper = pointMap[xPos][yPos];
        lower = 0;

        // iterate left -> right
        // for (int xSearch{xPos}; xSearch < pointMap.size(); ++xSearch) {
        //   // iterate up -> down
        //   for (int ySearch{yPos + 1}; ySearch < pointMap[xPos].size();
        //        ++ySearch) {
        //     if (upper - lower < 1) {
        //       break;
        //     }
        //     if (upper >= pointMap[xSearch][ySearch] &&
        //         lower <= pointMap[xSearch][ySearch]) {
        //       ++count;
        //       lower = pointMap[xSearch][ySearch] + 1;
        //       break;
        //     }
        //   }
        // }

        total += count;
      }
    }

    return 0;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  int output{solCur.numberOfPairs(unit.points)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;

  return 0;
}
