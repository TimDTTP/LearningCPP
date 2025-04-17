
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int k;
    int output;
  };

  TestCase testA() { return {{3, 1, 2, 2, 2, 1, 3}, 2, 4}; }
  TestCase testB() { return {{1, 2, 3, 4}, 1, 0}; }
};

class Solution {
public:
  int countPairs(std::vector<int> &nums, int k) {
    constexpr int MAX_VALUE{100};
    int pairCounter{0};

    std::unordered_map<int, std::set<int>> table{};
    for (int i{0}; i < nums.size(); ++i) {
      table[nums[i]].insert(i);
    }

    for (std::pair<int, std::set<int>> number : table) {
      if (number.second.size() == 1) {
        continue;
      }
      for (int index{0}; index < number.second.size() - 1; ++index) {
        for (int cmp{index + 1}; cmp < number.second.size(); ++cmp) {
          if (!((number.second[index] * number.second[cmp]) % k)) {
            std::cout << index << ' ' << cmp << '\n';
            ++pairCounter;
          }
        }
      }
    }

    return pairCounter;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.countPairs(unit.nums, unit.k)};

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
