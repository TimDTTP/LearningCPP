
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> arr;
    int start;
    bool expected;
  };

  TestCase testA() { return {{4, 2, 3, 0, 3, 1, 2}, 5, true}; }
  TestCase testB() { return {{4, 2, 3, 0, 3, 1, 2}, 0, true}; }
  TestCase testC() { return {{3, 0, 2, 1, 2}, 2, false}; }
  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class DSU {
private:
  std::vector<int> parent{};
  std::vector<int> size{};

public:
  DSU(int val) {
    parent.resize(val);
    std::iota(parent.begin(), parent.end(), 0);
    size.assign(val, 1);
  }

  int find(int target) {
    if (parent[target] == target) {
      return target;
    }
    return parent[target] = find(parent[target]);
  }

  bool unite(int a, int b) {
    int rootA{find(a)};
    int rootB{find(b)};

    if (rootA != rootB) {
      if (size[rootA] < size[rootB]) {
        std::swap(rootA, rootB);
      }
      parent[rootB] = rootA;
      size[rootA] += size[rootB];
      return true;
    } else {
      return false;
    }
  }
};

class Solution {
private:
  bool search(std::vector<int> &arr, int curr, std::vector<bool> &visited) {
    if ((curr < 0) || (curr >= arr.size()) || (visited[curr])) {
      return false;
    }
    if (arr[curr] == 0) {
      return true;
    }
    visited[curr] = true;

    return (search(arr, curr - arr[curr], visited) ||
            search(arr, curr + arr[curr], visited));
  }

public:
  bool canReach(std::vector<int> &arr, int start) {
    int size = arr.size();
    std::vector<bool> visited{};
    visited.resize(size, false);

    return search(arr, start, visited);
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    bool result = sol.canReach(unit.arr, unit.start);

    std::cout << std::boolalpha;
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
