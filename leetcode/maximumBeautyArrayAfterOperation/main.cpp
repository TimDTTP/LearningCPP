
#include <algorithm>
#include <iostream>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int k;
    int output;
  };

  TestCase testA() { return {{4, 6, 1, 2}, 2, 3}; }

  TestCase testB() { return {{1, 1, 1, 1}, 10, 4}; }
};

class Solution {
public:
  int maximumBeauty(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> freq;

    for (int num : nums) {
      for (int start{num - k}; start <= num + k; ++start) {
        ++freq[start];
      }
    }

    return std::max_element(freq.begin(), freq.end(),
                            [](std::pair<int, int> a, std::pair<int, int> b) {
                              return a.second < b.second;
                            })
        ->second;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.maximumBeauty(unit.nums, unit.k)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
