
#include <algorithm>
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

  TestCase testC() {
    TestCase obj{{23, 47, 63, 72, 81, 99, 88, 55, 21, 33, 32}, 1};
    return obj;
  }

  TestCase testD() {
    TestCase obj{{100, 92, 89, 77, 74, 66, 64, 66, 64}, 6};
    return obj;
  }
};

class Solution {
private:
  std::vector<int> increasingSequence(std::vector<int> &nums) {
    int numGreaterThan;
    // traverse from left to right tracking values to its left
    std::vector<int> allGreater{};
    allGreater.resize(nums.size(), 0);
    for (int i{1}; i < nums.size() - 1; i++) {
      numGreaterThan = 0;
      // traverse backward and find first value it is greater than
      for (int j{i - 1}; j >= 0; j--) {
        // if value is greater add 1 to found pos
        if (nums[i] > nums[j] && allGreater[j] >= numGreaterThan) {
          allGreater[i] = allGreater[j] + 1;
          numGreaterThan = allGreater[j];
        }
      }
    }

    return allGreater;
  }

public:
  int minimumMountainRemovals(std::vector<int> &nums) {
    const int start = 0;
    const int end = nums.size();
    int numGreaterThan;

    std::vector<int> left{increasingSequence(nums)};

    std::reverse(nums.begin(), nums.end());
    std::vector<int> right{increasingSequence(nums)};
    std::reverse(right.begin(), right.end());

    // compare found values and take peak of largest mountain
    int mountainSize{0};
    int temp{0};
    for (int i{0}; i < end; i++) {
      if (left[i] != 0 && right[i] != 0)
        temp = left[i] + right[i] + 1;

      mountainSize = std::max(mountainSize, temp);
    }

    return end - mountainSize;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testD()};
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
