
#include <iostream>
#include <unordered_map>
#include <vector>

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

  TestCase testC() {
    TestCase obj;
    obj.nums1 = {13, 14, 10, 2, 12, 3, 9, 11, 15, 8, 4, 7, 0, 6, 5, 1};
    obj.nums2 = {8, 7, 9, 5, 6, 14, 15, 10, 2, 11, 4, 13, 3, 12, 1, 0};
    obj.output = 77;
    return obj;
  }
};

class Solution {
public:
  long long goodTriplets(std::vector<int> &nums1, std::vector<int> &nums2) {
    long long counter{0};

    // add nums2 to a map for better lookup
    const size_t size{nums2.size()};
    std::unordered_map<int, int> screen;
    for (int i{0}; i < size; ++i) {
      screen.insert({nums2[i], i});
    }

    // loop through nums1 and find permutation
    for (int first{0}; first < (size - 2); ++first) {
      for (int second{first + 1}; second < (size - 1); ++second) {
        // check second value is after first
        if (screen[nums1[first]] < screen[nums1[second]]) {
          for (int third{second + 1}; third < size; ++third) {
            // check third value is after second
            if (screen[nums1[second]] < screen[nums1[third]]) {
              ++counter;
            }
          }
        } else {
          continue;
        }
      }
    }

    return counter;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
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
