
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> candidates;
    int output;
  };

  TestCase testA() {
    TestCase obj{{16, 17, 71, 62, 24, 14}, 4};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{8, 8}, 2};
    return obj;
  }
};

class Solution {
public:
  int largestCombination(std::vector<int> &candidates) {
    // sort array descending order
    std::sort(candidates.begin(), candidates.end(), std::greater());

    const int xAxis = std::floor(std::log2(candidates.front())) + 1;
    const int yAxis = candidates.size();
    std::vector<std::vector<int>> matrix;
    matrix.reserve(yAxis);

    for (int num : candidates) {
      std::vector<int> temp{};
      temp.resize(xAxis, 0);
      for (int col{xAxis - 1}; col >= 0; col--) {
        if (num != 0) {
          temp[col] = num % 2;
          num /= 2;
        } else {
          break;
        }
      }
      matrix.push_back(temp);
    }

    // TEST
    for (std::vector<int> h : matrix) {
      for (int g : h) {
        std::cout << g << ' ';
      }
      std::cout << '\n';
    }
    std::cout << std::endl;

    // iterate through and count
    int maxCount{0};
    int count;
    for (int col{0}; col < xAxis; col++) {
      count = 0;
      for (int row{0}; row < yAxis; row++) {
        if (matrix[row][col] == 1)
          count++;
      }

      maxCount = std::max(maxCount, count);
    }

    return maxCount;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
  int output{solCur.largestCombination(unit.candidates)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
