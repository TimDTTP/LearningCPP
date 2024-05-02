
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

struct TestCase {
  std::vector<int> nums;
  int expected;
};

// Test cases
TestCase test1() {
  TestCase obj;
  obj.nums = {-1, 2, -3, 3};
  obj.expected = 3;

  return obj;
}

TestCase test2() {
  TestCase obj;
  obj.nums = {-1, 10, 6, 7, -7, 1};
  obj.expected = 7;

  return obj;
}

TestCase test3() {
  TestCase obj;
  obj.nums = {-10, 8, 6, 7, -2, -3};
  obj.expected = -1;

  return obj;
}

class Solution {
public:
  int findMaxK(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    int ptr1{0};
    size_t ptr2{nums.size() - 1};

    while (ptr1 < ptr2) {
      if (nums[ptr1] > 0 || nums[ptr2] < 0)
        return -1;
      else if (0 + (0 - nums[ptr1]) == nums[ptr2])
        return nums[ptr2];
      else if (0 + (0 - nums[ptr1]) >= nums[ptr2])
        ++ptr1;
      else if (0 + (0 - nums[ptr1]) <= nums[ptr2])
        --ptr2;
    }

    // if no match
    return -1;
  }
};

class OnlineSolution {
public:
  int findMaxK(std::vector<int> &nums) {
    int result = -1;
    std::unordered_set<int> table{nums.begin(), nums.end()};

    for (int num : table) {
      if (table.find(num * -1) != table.end())
        result = std::max(result, num);
    }

    return result;
  }
};

int main() {
  TestCase input{test3()};
  Solution answer = Solution();

  int output{answer.findMaxK(input.nums)};

  std::cout << "Expected: " << '\n' << input.expected << "\n\n";
  std::cout << "Actual: " << '\n' << output << "\n\n";

  // online solution
  OnlineSolution online = OnlineSolution();
  output = online.findMaxK(input.nums);
  std::cout << "Online: " << '\n' << output << "\n\n";

  return 0;
}
