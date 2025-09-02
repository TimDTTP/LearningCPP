
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<std::vector<int>> classes;
    int extraStudents;
    double output;
  };

  TestCase testA() {
    TestCase obj;
    obj.classes = {{1, 2}, {3, 5}, {2, 2}};
    obj.extraStudents = 2;
    obj.output = 0.78333;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.classes = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
    obj.extraStudents = 4;
    obj.output = 0.53485;
    return obj;
  }
};

class Solution {
public:
  double maxAverageRatio(std::vector<std::vector<int>> &classes,
                         int extraStudents) {
    int size = classes.size();
    std::vector<std::pair<int, double>> diff{};

    // distille class
    std::pair<double, double> passRatio;
    for (int i{0}; i < size; ++i) {
      passRatio.first = classes[i][0];
      passRatio.second = classes[i][1];

      diff.push_back({i, (((passRatio.first + 1.0) / (passRatio.second + 1.0)) -
                          (passRatio.first / passRatio.second))});
    }

    // sort from greatest to least
    std::sort(diff.begin(), diff.end(),
              [](std::pair<int, double> a, std::pair<int, double> b) {
                return a.second > b.second;
              });

    // consider extraStudents to maximize
    int pos, begin, end;
    double pass, total;
    for (int i{0}; i < extraStudents; ++i) {
      // TEST:
      for (std::pair<double, double> i : diff) {
        std::cout << i.first << ' ' << i.second << '\n';
      }
      std::cout << std::endl;

      pos = diff.front().first;

      // change values
      pass = ++classes[pos][0];
      total = ++classes[pos][1];

      // re-insert in non-increasing order
      diff.push_back({pos, (((pass + 1.0) / (total + 1)) - (pass / total))});
      diff.erase(diff.begin());

      std::sort(diff.begin(), diff.end(),
                [](std::pair<int, double> a, std::pair<int, double> b) {
                  return a.second > b.second;
                });
    }

    // get avg pass ratio
    double avg{std::accumulate(
        classes.begin(), classes.end(), 0.0,
        [](double currentSum, std::vector<int> val) {
          return (currentSum + (static_cast<double>(val[0]) / val[1]));
        })};

    return (avg / size);
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
  double output{solCur.maxAverageRatio(unit.classes, unit.extraStudents)};

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
