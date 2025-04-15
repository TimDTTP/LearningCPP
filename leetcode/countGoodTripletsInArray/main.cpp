
#include <iostream>

class Test {
public:
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    long long output;
  };

  TestCase testA() {
    TestCase obj;
    obj.nums1 = {2, 0, 1, 3};
    obj.nums2 = {0, 1, 2, 3};
    obj.output = 1;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.nums1 = {4, 0, 1, 3, 2};
    obj.nums2 = {4, 1, 0, 2, 3};
    obj.output = 4;
    return obj;
  }
};

class Solution {
public:
  long long goodTriplets(std::vector<int> &nums1, std::vector<int> &nums2) {
    long long out;
    return out;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  long long output{solCur.goodTriplets(unit.nums1, unit.nums2)};

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
