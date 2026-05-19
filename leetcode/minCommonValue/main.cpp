
#include <iostream>
#include <unordered_set>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    int expected;
  };

  TestCase testA() { return {{1, 2, 3}, {2, 4}, 2}; }
  TestCase testB() { return {{1, 2, 3, 6}, {2, 3, 4, 5}, 2}; }
  std::vector<TestCase> all() { return {testA(), testB()}; };
};

class Solution {
public:
  int getCommon(std::vector<int> &nums1, std::vector<int> &nums2) {
    if (nums1.size() > nums2.size()) {
      std::swap(nums1, nums2);
    }
    std::unordered_set<int> checkList{nums2.begin(), nums2.end()};

    for (int num : nums1) {
      if (checkList.find(num) != checkList.end()) {
        return num;
      }
    }

    return -1;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    int result = sol.getCommon(unit.nums1, unit.nums2);

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
