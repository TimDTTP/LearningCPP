
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int k;
    long long output;
  };

  TestCase testA() {
    TestCase obj{{1, 5, 4, 2, 9, 9, 9}, 3, 15};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{4, 4, 4}, 3, 0};
    return obj;
  }

  TestCase testC() {
    TestCase obj{{1, 1, 1, 7, 8, 9}, 3, 24};
    return obj;
  }

  TestCase testD() {
    TestCase obj{{9, 9, 9, 1, 2, 3}, 3, 12};
    return obj;
  }
};

class Solution {
public:
  long long maximumSubarraySum(std::vector<int> &nums, int k) {
    int ptr1{0};
    int ptr2{k};
    long long maxSoFar{0};
    int unique;
    std::unordered_map<int, int> tracked{};

    // get initial setup
    // add values to set
    for (int start{ptr1}; start < k; start++)
      tracked[nums[start]]++;
    unique = tracked.size();
    if (unique == k)
      maxSoFar = std::accumulate(nums.begin(), nums.begin() + ptr2, 0);

    // traverse and compare
    long long temp;
    while (ptr2 <= nums.size()) {
      tracked[nums[ptr1]]--;
      if (tracked[nums[ptr1]] == 0)
        unique--;

      ptr1++;
      ptr2++;

      if (tracked.count(nums[ptr2 - 1]) == 0) {
        unique++;
      } else if (tracked[nums[ptr2 - 1]] == 0) {
        unique++;
      }
      tracked[nums[ptr2 - 1]]++;

      if (unique == k) {
        temp = std::accumulate(nums.begin() + ptr1, nums.begin() + ptr2, 0);
        maxSoFar = std::max(maxSoFar, temp);
      }
    }

    return maxSoFar;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testD()};
  long long output{solCur.maximumSubarraySum(unit.nums, unit.k)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
