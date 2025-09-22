
#include <iostream>
#include <unordered_map>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    int output;
  };

  TestCase testA() { return {{1, 2, 2, 3, 1, 4}, 4}; }

  TestCase testB() { return {{1, 2, 3, 4, 5}, 5}; }
};

class Solution {
public:
  int maxFrequencyElements(std::vector<int> nums) {
    int max{0}, count{0};
    std::unordered_map<int, int> table{};

    for (int i : nums) {
      table[i]++;
      if (table[i] > max) {
        max = table[i];
        count = table[i];
      } else if (table[i] == max) {
        count += table[i];
      }
    }
    return count;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
  int output{solCur.maxFrequencyElements(unit.nums)};

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
