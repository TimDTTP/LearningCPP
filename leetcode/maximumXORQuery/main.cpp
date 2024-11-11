
#include <iostream>
#include <sys/types.h>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int maximumBit;
    std::vector<int> output;
  };

  TestCase testA() {
    TestCase obj{{0, 1, 1, 3}, 2, {0, 3, 2, 3}};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{2, 3, 4, 7}, 3, {5, 2, 6, 5}};
    return obj;
  }

  TestCase testC() {
    TestCase obj{{0, 1, 2, 2, 5, 7}, 3, {4, 3, 6, 4, 6, 7}};
    return obj;
  }
};

class Solution {
public:
  std::vector<int> getMaximumXor(std::vector<int> &nums, int maximumBit) {
    int last;
    int temp;

    for (int i{0}; i < nums.size(); i++) {
      // XOR values
      if (i != 0) {
        nums[i] = last ^ nums[i];
      }
      last = nums[i];

      // flip bits
      std::bitset<20> num(nums[i]);
      for (int j{0}; j < maximumBit; j++) {
        num[j].flip();
      }
      nums[i] = (int)(num.to_ulong());
    }
    std::reverse(nums.begin(), nums.end());

    return nums;
  }
};

void printVector(std::vector<int> output) {
  for (int i : output) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  std::vector<int> output{solCur.getMaximumXor(unit.nums, unit.maximumBit)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: ";
    printVector(unit.output);
    std::cout << "Actual:   ";
    printVector(output);
  }
  std::cout << std::endl;
}
