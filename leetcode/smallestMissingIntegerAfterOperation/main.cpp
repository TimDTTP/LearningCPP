
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int values;
    int output;
  };

  TestCase testA() {
    return {
        {1, -10, 7, 13, 6, 8},
        5,
        4,
    };
  }

  TestCase testB() {
    return {
        {1, -10, 7, 13, 6, 8},
        7,
        2,
    };
  }

  TestCase testC() {
    return {
        {0, -3},
        4,
        2,
    };
  }
};

class Solution {
public:
  int findSmallestInteger(std::vector<int> &nums, int value) {
    // count remainders
    std::unordered_map<int, int> base{};
    for (int i : nums) {
      if (i < 0) {
        ++base[i +
               (std::abs(i) % value ? (-i / value + 1) : -i / value) * value];
      } else {
        ++base[i % value];
      }
    }

    // check and count
    int i = 0, ans = 0;
    while (true) {
      if (base[i] > 0) {
        --base[i];
        ++i;
        ++ans;
        i %= value;
      } else {
        return ans;
      }
    }
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.findSmallestInteger(unit.nums, unit.values)};

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
