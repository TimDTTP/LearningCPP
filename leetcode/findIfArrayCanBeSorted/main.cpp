
#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    bool output;
  };

  TestCase testA() {
    TestCase obj{{8, 4, 2, 30, 15}, true};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{1, 2, 3, 4, 5}, true};
    return obj;
  }

  TestCase testC() {
    TestCase obj{{3, 16, 8, 4, 2}, false};
    return obj;
  }

  TestCase testD() {
    TestCase obj{{20, 16}, false};
    return obj;
  }
};

class Solution {
public:
  bool canSortArray(std::vector<int> &nums) {
    // track number of set bits
    std::vector<int> setBits{};
    unsigned int count;
    for (int num : nums) {
      count = 0;
      while (num) {
        count += num & 1;
        num >>= 1;
      }
      setBits.push_back(count);
    }

    // sort with same number of set bits
    int start{0};
    for (int end{0}; end < setBits.size(); end++) {
      if (setBits[start] != setBits[end]) {
        std::sort(nums.begin() + start, nums.begin() + end);
        start = end;
      }
    }
    std::sort(nums.begin() + start, nums.end());

    // check if array is sorted
    int last{1};
    for (int num : nums) {
      if (num < last)
        return false;
      last = num;
    }

    return true;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  bool output{solCur.canSortArray(unit.nums)};

  std::cout << std::boolalpha;
  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
