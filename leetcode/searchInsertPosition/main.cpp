
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int target;
    int output;
  };

  TestCase testA() {
    TestCase obj{{2, 4, 6, 8, 10}, 4, 1};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{1, 3, 5, 6}, 2, 1};
    return obj;
  }

  TestCase testC() {
    TestCase obj{{1, 3, 5, 6}, 5, 2};
    return obj;
  }

  TestCase testD() {
    TestCase obj{{1, 3, 5, 6}, 7, 4};
    return obj;
  }
};

class Solution {
public:
  int searchInsert(std::vector<int> &nums, int target) {
    int start{0};
    int end = nums.size() - 1;
    int pivot;

    while (end - start > 2) {
      pivot = start + ((end - start) / 2);

      if (nums[pivot] == target)
        return pivot;
      else if (nums[pivot] > target)
        end = pivot;
      else
        start = pivot;
    }

    // iterate through vector
    for (int i{start}; i <= end; i++) {
      if (nums[i] == target)
        return i;
      else if (nums[i] > target)
        return i;
    }

    return end + 1;
  }
};

int main() {
  Solution solCur{Solution()};
  Test testCur{Test()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.searchInsert(unit.nums, unit.target)};

  if (unit.output == output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;

  return 0;
}
