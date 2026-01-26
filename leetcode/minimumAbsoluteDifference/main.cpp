
#include <algorithm>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> arr;
    std::vector<std::vector<int>> expected;
  };

  TestCase testA() { return {{4, 2, 1, 3}, {{1, 2}, {2, 3}, {3, 4}}}; }
  TestCase testB() { return {{1, 3, 6, 10, 15}, {{1, 3}}}; }
  TestCase testC() {
    return {{3, 8, -10, 23, 19, -4, -14, 27}, {{-14, -10}, {19, 23}, {23, 27}}};
  }
  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };

  void printArr(std::vector<std::vector<int>> &arr) {
    for (std::vector<int> pair : arr) {
      std::cout << '[' << pair[0] << ", " << pair[1] << "] ";
    }
    std::cout << std::endl;
  }
};

class Solution {
public:
  std::vector<std::vector<int>> minimumAbsDifference(std::vector<int> &arr) {
    std::sort(arr.begin(), arr.end());

    // find min diff and pairs
    int minDiff{*(arr.end() - 1) - *arr.begin()};
    int temp{};
    std::vector<int> indexes{};
    for (int i{0}; i < arr.size() - 1; ++i) {
      temp = arr[i + 1] - arr[i];
      if (temp < minDiff) {
        minDiff = temp;
        indexes.clear();
        indexes.push_back(i);
      } else if (temp == minDiff) {
        indexes.push_back(i);
      }
    }

    // assemble array
    std::vector<std::vector<int>> pairs{};
    for (int i{0}; i < indexes.size(); ++i) {
      pairs.push_back({arr[indexes[i]], arr[indexes[i] + 1]});
    }

    return pairs;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    std::vector<std::vector<int>> result = sol.minimumAbsDifference(unit.arr);

    if (result == unit.expected) {
      std::cout << "✅ Test " << i + 1 << " passed!\n";
      ++passed;
    } else {
      std::cout << "❌ Test " << i + 1 << " failed!\n";
      std::cout << "   Expected: ";
      tests.printArr(unit.expected);
      std::cout << " | Got: ";
      tests.printArr(result);
      std::cout << std::endl;
    }
  }
  std::cout << "\nSummary: " << passed << "/" << cases.size()
            << " tests passed.\n";

  return 0;
}
