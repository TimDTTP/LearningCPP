
#include <algorithm>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    long long expected;
  };

  TestCase testA() { return {{2, 6, 4}, 2}; }
  TestCase testB() { return {{3, 6, 2, 8}, 5}; }
  std::vector<TestCase> all() { return {testA(), testB()}; };
};

class Solution {
private:
  int gcd(int a, int b) {
    if (a < b) {
      std::swap(a, b);
    }

    // Euclid algo
    int temp;
    while ((a % b) != 0) {
      temp = a % b;
      a = b;
      b = temp;
    }

    return b;
  }

public:
  long long gcdSum(std::vector<int> &nums) {
    int n = nums.size();

    // max array
    std::vector<int> max;
    max.resize(n);
    int currMax{0};
    for (int i{0}; i < n; ++i) {
      if (nums[i] > currMax) {
        currMax = nums[i];
      }
      max[i] = currMax;
    }

    // prefixGcd array
    std::vector<int> prefixGcd;
    prefixGcd.resize(n);
    for (int i{0}; i < n; ++i) {
      prefixGcd[i] = gcd(nums[i], max[i]);
    }

    std::sort(prefixGcd.begin(), prefixGcd.end(), std::less<int>());

    // pair and sum
    long long sum{0};
    for (int dist{0}; dist < (n / 2); ++dist) {
      sum += gcd(prefixGcd[dist], prefixGcd[n - 1 - dist]);
    }

    return sum;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    long long result = sol.gcdSum(unit.nums);

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
