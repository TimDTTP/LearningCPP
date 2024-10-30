
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> array;
    int output;
  };

  TestCase testA() {
    TestCase obj{{1, 3, 1}, 0};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{2, 1, 1, 5, 6, 2, 3, 1}, 3};
    return obj;
  }
};

class Solution {
public:
  int minimumMountainRemovals(std::vector<int> &nums) {
    const int start = 0;
    const int end = nums.size();

    // traverse from left to right tracking values to its left
    std::vector<int> left{};
    left.resize(end, 0);
    for (int i{start + 1}; i < end - 1; i++) {
      // traverse backward and find first value it is greater than
      for (int j{i - 1}; j >= start; j--) {
        // if value is greater add 1 to found pos
        if (nums[i] > nums[j]) {
          left[i] = left[j] + 1;
          break;
        }
      }
      std::cout << nums[i] << ' ';
    }
    std::cout << std::endl;

    // WARNING: printing left
    for (int i : left) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;

    // traverse from right to left tracking values to its right
    std::vector<int> right{};
    right.resize(end, 0);
    for (int i{end - 2}; i > start; i--) {
      // traverse backward and find first value it is greater than
      for (int j{i + 1}; j < end; j++) {
        // if value is greater add 1 to found pos
        if (nums[i] > nums[j]) {
          right[i] = right[j] + 1;
          break;
        }
      }
      std::cout << nums[i] << ' ';
    }
    std::cout << std::endl;

    // WARNING: printing right
    for (int i : right) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;

    // compare found values and take peak of largest mountain
    int mountainSize{0};
    for (int i{0}; i < end; i++) {
      if (left[i] + right[i] + 1 > mountainSize) {
        mountainSize = left[i] + right[i] + 1;
      }
    }

    // WARNING: 0 is a placeholder value
    return end - mountainSize;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
  int output{solCur.minimumMountainRemovals(unit.array)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
