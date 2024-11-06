
#include <algorithm>
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
};

class Solution {
private:
  unsigned int countSetBit(int num) {
    unsigned int count{0};
    while (num) {
      count += num & 1;
      num >>= 1;
    }
    return count;
  }

  bool check(std::vector<int> &nums, std::vector<int> &setBits) {
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

public:
  bool canSortArray(std::vector<int> &nums) {
    // track number of set bits
    std::vector<int> setBits{};
    for (int num : nums)
      setBits.push_back(countSetBit(num));

    // check sorting forwards
    bool forward{check(nums, setBits)};

    // reverse vector
    std::reverse(nums.begin(), nums.end());
    std::reverse(setBits.begin(), setBits.end());

    // check again
    bool backwards{check(nums, setBits)};

    return (forward || backwards);
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  bool output{solCur.canSortArray(unit.nums)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
