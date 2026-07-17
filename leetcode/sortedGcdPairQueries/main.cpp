
#include <algorithm>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    std::vector<long long> queries;
    std::vector<int> expected;
  };

  TestCase testA() { return {{2, 3, 4}, {0, 2, 2}, {1, 2, 2}}; }
  TestCase testB() { return {{4, 4, 2, 1}, {5, 3, 1, 0}, {4, 2, 1, 1}}; }
  TestCase testC() { return {{2, 2}, {0, 0}, {2, 2}}; }
  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
private:
  int gcd(int a, int b) {
    if (a > b) {
      std::swap(a, b);
    }

    int temp;
    while ((a % b) != 0) {
      temp = a % b;
      a = b;
      b = temp;
    }

    return b;
  }

public:
  std::vector<int> gcdValues(std::vector<int> &nums,
                             std::vector<long long> &queries) {
    int n = nums.size();

    // brute force all GCDs
    std::vector<int> gcds;
    for (int a{0}; a < (n - 1); ++a) {
      for (int b{a + 1}; b < n; ++b) {
        gcds.push_back(gcd(nums[a], nums[b]));
      }
    }

    std::sort(gcds.begin(), gcds.end());

    std::vector<int> answer{};
    for (long long val : queries) {
      answer.push_back(gcds[val]);
    }

    return answer;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    std::vector<int> result = sol.gcdValues(unit.nums, unit.queries);

    if (result == unit.expected) {
      std::cout << "✅ Test " << i + 1 << " passed!\n";
      ++passed;
    } else {
      std::cout << "❌ Test " << i + 1 << " failed!\n";
      std::cout << "   Expected: " << std::endl;
      for (int num : unit.expected) {
        std::cout << num << ' ';
      }
      std::cout << std::endl;
      std::cout << "   Got: " << std::endl;
      for (int num : result) {
        std::cout << num << ' ';
      }
      std::cout << std::endl;
    }
  }
  std::cout << "\nSummary: " << passed << "/" << cases.size()
            << " tests passed.\n";

  return 0;
}
