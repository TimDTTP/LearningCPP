
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
    const int overhead{k * 2};
    const int size = nums.size();
    std::sort(nums.begin(), nums.end());

    // first: max overhead
    // second: # of values that satisfy limit
    std::vector<std::pair<int, int>> table{};
    int tracker{0};

    table.push_back({nums[0] + overhead, 1});
    for (int i{1}; i < size; ++i) {
      table.push_back({nums[i] + overhead, 0});

      while (nums[i] > table[tracker].first) {
        table[tracker].second = i - tracker;
        ++tracker;
      }
    }

    // handle remaining values that are leftover when loop fully iterates
    for (int i{tracker}; i < size; ++i) {
      table[i].second = size - i;
    }

    return std::max_element(table.begin(), table.end(),
                            [](std::pair<int, int> a, std::pair<int, int> b) {
                              return a.second < b.second;
                            })
        ->second;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
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
