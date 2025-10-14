
#include <ios>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int k;
    bool output;
  };

  TestCase testA() { return {{2, 5, 7, 8, 9, 2, 3, 4, 3, 1}, 3, true}; }
  TestCase testB() { return {{1, 2, 3, 4, 4, 4, 4, 5, 6, 7}, 5, false}; }
  TestCase testC() { return {{-15, 19}, 1, true}; }
  TestCase testD() { return {{5, 8, -2, -1}, 2, true}; }
};

class Solution {
public:
  bool hasIncreasingSubarrays(std::vector<int> &nums, int k) {
    if (k == 1) {
      return true;
    }
    int prev{0};
    int count{1};

    for (int i{1}; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        ++count;
        if ((prev >= k) && (count >= k)) {
          return true;
        }
        if (count >= (2 * k)) {
          return true;
        }
      } else {
        prev = count;
        count = 1;
      }
    }

    return false;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  bool output{solCur.hasIncreasingSubarrays(unit.nums, unit.k)};

  std::cout << std::boolalpha;
  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;

  return 0;
}
