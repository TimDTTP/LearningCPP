
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> output;
  };

  TestCase testA() { return {{6, 4, 3, 2, 7, 6, 2}, {12, 7, 6}}; }

  TestCase testB() { return {{2, 2, 1, 1, 3, 3, 3}, {2, 1, 1, 3}}; }

  TestCase testC() {
    return {{287, 41, 49, 287, 899, 23, 23, 20677, 5, 825}, {2009, 20677, 825}};
  }

  void printVec(std::vector<int> arr) {
    std::cout << "[";
    for (int i : arr) {
      std::cout << i << ", ";
    }
    std::cout << ']' << std::endl;
  }
};

class Solution {
public:
  int lcm(int a, int b) {
    // euclid's algo
    int greater{a > b ? a : b};
    int lesser{a > b ? b : a};
    int temp{};

    while (greater % lesser != 0) {
      temp = greater % lesser;
      greater = lesser;
      lesser = temp;
    }

    return lesser;
  }

  std::vector<int> replaceNonCoprimes(std::vector<int> &nums) {
    int multiple{};
    for (int i{0}; i < (nums.size() - 1); i++) {
      multiple = lcm(nums[i], nums[i + 1]);
      if (multiple != 1) {
        nums[i] = ((long long)nums[i] * nums[i + 1]) / multiple;
        nums.erase(nums.begin() + (i + 1));
        i = (i > 0) ? (i - 2) : (i - 1);
      } else {
      }
    }

    return nums;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  std::vector<int> output{solCur.replaceNonCoprimes(unit.nums)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: ";
    testCur.printVec(unit.output);
    std::cout << "Actual: ";
    testCur.printVec(output);
  }
  std::cout << std::endl;

  return 0;
}
