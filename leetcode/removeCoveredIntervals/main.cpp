
#include <algorithm>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    int expected;
    std::vector<std::vector<int>> intervals;
  };

  TestCase testA() { return {2, {{1, 4}, {3, 6}, {2, 8}}}; }
  TestCase testB() { return {1, {{1, 4}, {2, 3}}}; }
  TestCase testC() { return {1, {{1, 2}, {1, 4}, {3, 4}}}; }

  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
public:
  int removeCoveredIntervals(std::vector<std::vector<int>> &intervals) {
    // sort by first value ascending order
    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                return ((a[0] != b[0]) ? (a[0] < b[0]) : (a[1] > b[1]));
              });

    // traverse, track
    int size = intervals.size();
    int counter{0};
    int currMax{intervals[0][1]};

    // edge
    if (size == 1) {
      return 1;
    }

    for (int i{1}; i < size; ++i) {
      if (intervals[i][1] > currMax) {
        currMax = intervals[i][1];
        continue;
      } else {
        ++counter;
      }
    }

    return size - counter;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    int result = sol.removeCoveredIntervals(unit.intervals);

    if (result == unit.expected) {
      std::cout << "✅ Test " << i + 1 << " passed!\n";
      ++passed;
    } else {
      std::cout << "❌ Test " << i + 1 << " failed!\n";
      std::cout << "   Expected: " << unit.expected << " | Got: " << result
                << "\n";
    }
  }
  std::cout << "\nSummary: " << passed << "/" << cases.size()
            << " tests passed.\n";

  return 0;
}
