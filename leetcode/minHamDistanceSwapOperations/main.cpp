
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> source;
    std::vector<int> target;
    std::vector<std::vector<int>> allowedSwaps;
    int expected;
  };

  TestCase testA() { return {{1, 2, 3, 4}, {2, 1, 4, 5}, {{0, 1}, {2, 3}}, 1}; }
  TestCase testB() { return {{1, 2, 3, 4}, {1, 3, 2, 4}, {}, 2}; }
  TestCase testC() {
    return {
        {5, 1, 2, 4, 3}, {1, 5, 4, 2, 3}, {{0, 4}, {4, 2}, {1, 3}, {1, 4}}, 0};
  }
  TestCase testD() { return {{86}, {49}, {}, 1}; }
  TestCase testE() { return {{1, 5, 5}, {5, 1, 1}, {{0, 1}}, 1}; }

  std::vector<TestCase> all() {
    return {testA(), testB(), testC(), testD(), testE()};
  };
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

  int find(int val) {
    if (parent[val] == val) {
      return val;
    }
    return parent[val] = find(parent[val]);
  }

  bool unite(int a, int b) {
    int rootA{find(a)};
    int rootB{find(b)};

    if (rootA != rootB) {
      // attach smaller tree to larger tree
      if (size[rootA] < size[rootB])
        std::swap(rootA, rootB);
      parent[rootB] = rootA;
      size[rootA] += size[rootB];
      return true;
    } else
      return false; // already in same set
  }
};

class Solution {
public:
  int minimumHammingDistance(std::vector<int> &source, std::vector<int> &target,
                             std::vector<std::vector<int>> &allowedSwaps) {
    // init dsu with max size in source and occupied
    int n = source.size();
    DSU dsu{n};

    for (int i{0}; i < allowedSwaps.size(); ++i) {
      dsu.unite(allowedSwaps[i][0], allowedSwaps[i][1]);
    }

    // BUG:
    // Target does not allow multiple of same values. Repeating value's index
    // get overwritten

    // convert target to constant search
    std::unordered_map<int, std::unordered_map<int, int>> targetMap{};

    for (int i{0}; i < n; ++i) {
      int root = dsu.find(i);
      targetMap[root][source[i]]++;
    }

    int counter{0};
    for (int i{0}; i < n; ++i) {
      int root = dsu.find(i);
      int val = target[i];

      if (targetMap[root][val] > 0) {
        targetMap[root][val]--;
      } else {
        counter++;
      }
    }

    return counter;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    int result =
        sol.minimumHammingDistance(unit.source, unit.target, unit.allowedSwaps);

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
