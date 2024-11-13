
#include <cmath>
#include <iostream>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int lower;
    int upper;
    long long output;
  };

  TestCase testA() {
    TestCase obj;
    obj.nums = {0, 1, 7, 4, 4, 5};
    obj.lower = 3;
    obj.upper = 6;
    obj.output = 6;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.nums = {1, 7, 9, 2, 5};
    obj.lower = 11;
    obj.upper = 11;
    obj.output = 1;
    return obj;
  }

  TestCase testC() {
    TestCase obj;
    obj.nums = {-1, 0};
    obj.lower = 1;
    obj.upper = 1;
    obj.output = 0;
    return obj;
  }

  TestCase testD() {
    TestCase obj;
    obj.nums = {0, 0, 0, 0, 0, 0};
    obj.lower = 0;
    obj.upper = 0;
    obj.output = 15;
    return obj;
  }

  TestCase testE() {
    TestCase obj;
    obj.nums = {-5, -7, -5, -7, -5};
    obj.lower = -12;
    obj.upper = -12;
    obj.output = 6;
    return obj;
  }
};

class Solution {
public:
  long long countFairPairs(std::vector<int> &nums, int lower, int upper) {
    std::sort(nums.begin(), nums.end());

    long long count{0};
    int lB, uB;
    bool found;

    // set upper limit
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] <= upper + nums[0]) {
        uB = i;
        break;
      }
    }

    // iterate through possible values
    for (int index{0};
         nums[index] <= std::abs(upper / 2) && index < nums.size() - 1;
         index++) {
      lB = index + 1;
      found = false;

      // find lower bound if it exists
      for (int start{lB}; start <= uB; start++) {
        if (nums[start] + nums[index] >= lower &&
            nums[start] + nums[index] <= upper) {
          found = true;
          lB = start;
          break;
        }
      }
      // if a match exists
      if (found) {
        // set upper bound
        for (int start{uB}; start >= lB; start--) {
          if (nums[start] <= upper - nums[index]) {
            uB = start;
            break;
          }
        }

        // add to count
        count += uB - lB + 1;
      }
      std::cout << std::boolalpha;
      std::cout << found << '\n';
    }

    return count;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testE()};
  long long output{solCur.countFairPairs(unit.nums, unit.lower, unit.upper)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
