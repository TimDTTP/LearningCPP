
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <unordered_set>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> stations;
    int r;
    int k;
    long long expected;
  };

private:
  TestCase testA() { return {{1, 2, 4, 5, 0}, 1, 2, 5}; }
  TestCase testB() { return {{4, 4, 4, 4}, 0, 3, 4}; }
  TestCase testC() { return {{13, 12, 8, 14, 7}, 2, 23, 52}; }
  TestCase testD() { return {{48, 16, 29, 41, 2, 43, 23}, 5, 40, 194}; }
  TestCase testE() {
    return {{57, 70, 35, 30, 29, 13, 17, 88, 89, 49}, 1, 90, 138};
  }

public:
  std::vector<TestCase> all() {
    return {testA(), testB(), testC(), testD(), testE()};
  };
};

class Solution {
private:
  void populateMap(std::vector<int> &stations,
                   std::multimap<long long, int, std::less<int>> &priority,
                   int r, int k, int n) {
    int lower, upper;
    priority.clear();
    for (int i{0}; i < stations.size(); ++i) {
      lower = std::max(0, (i - r));
      upper = std::min((n - 1), (i + r));
      priority.insert(std::pair<int, int>(
          std::accumulate(stations.begin() + lower,
                          stations.begin() + (upper + 1), 0),
          i));
    }
  }

public:
  long long maxPower(std::vector<int> &stations, int r, int k) {
    int n = stations.size();
    std::multimap<long long, int, std::less<int>> priority{};

    for (int j{0}; j < k; ++j) {
      // priority table
      populateMap(stations, priority, r, k, n);
      auto start = priority.begin();

      // List of possible "centers"
      std::unordered_set<int> possible{};
      std::unordered_set<int> temp{};
      possible.insert(start->second);
      for (int i{std::max(0, (start->second) - r)};
           i <= (std::min(n - 1, (start->second) + r)); ++i) {
        possible.insert(i);
      }

      // Narrow selection to 1
      int val{0};
      for (int i{1}; i < n; ++i) {
        if (possible.size() == 1)
          break;
        if (std::abs(std::next(start, i)->second - start->second) <= (2 * r)) {
          val = i;
        }

        // Shrink
        temp = possible;
        for (int num : temp) {
          if ((std::abs(num - val) > r) && (possible.size() > 1)) {
            possible.erase(num);
          }
        }
      }

      ++stations[*possible.begin()];
      // test
    }
    populateMap(stations, priority, r, k, n);

    return (priority.begin()->first);
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    long long result = sol.maxPower(unit.stations, unit.r, unit.k);

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
