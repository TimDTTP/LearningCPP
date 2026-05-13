
#include <algorithm>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<std::vector<int>> tasks;
    int expected;
  };

  TestCase testA() { return {{{1, 2}, {2, 4}, {4, 8}}, 8}; }
  TestCase testB() {
    return {{{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}}, 32};
  }
  TestCase testC() {
    return {{{1, 7}, {2, 8}, {3, 9}, {4, 10}, {5, 11}, {6, 12}}, 27};
  }

  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
private:
  void sortTasks(std::vector<std::vector<int>> &tasks) {
    auto sort = [](std::vector<int> a, std::vector<int> b) {
      if (a[2] != b[2]) {
        return a[2] < b[2];
      }
      if (a[1] != b[1]) {
        return a[1] > b[1];
      }
      return a[0] > b[0];
    };
    std::sort(tasks.begin(), tasks.end(), sort);
  }

public:
  int minimumEffort(std::vector<std::vector<int>> &tasks) {
    int size = tasks.size();

    // add delta for each task
    for (int i{0}; i < size; ++i) {
      tasks[i].push_back(tasks[i][1] - tasks[i][0]);
    }

    sortTasks(tasks);

    // add together
    int total{tasks[0][1]};
    for (int i{1}; i < size; ++i) {
      total = (((total + tasks[i][0]) > tasks[i][1]) ? (total + tasks[i][0])
                                                     : (tasks[i][1]));
    }

    return total;
  }
};

class OnlineSolution {
public:
  int minimumEffort(std::vector<std::vector<int>> &tasks) {
    sort(tasks.begin(), tasks.end(),
         [&](std::vector<int> &a, std::vector<int> &b) {
           return a[1] - a[0] < b[1] - b[0];
         });
    int ans = 0;
    for (auto task : tasks) {
      ans = std::max(ans + task[0], task[1]);
    }
    return ans;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    int result = sol.minimumEffort(unit.tasks);

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
