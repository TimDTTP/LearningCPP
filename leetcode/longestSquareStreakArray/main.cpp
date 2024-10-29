
#include <iostream>
#include <unordered_set>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> input;
    int output;
  };

  TestCase testA() {
    TestCase obj{{4, 3, 6, 16, 8, 2}, 3};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{2, 3, 5, 6, 7}, -1};
    return obj;
  }

  TestCase testC() {
    TestCase obj{{3, 9, 81, 6561}, 4};
    return obj;
  }
};

class Solution {
public:
  int longestSquareStreak(std::vector<int> &nums) {
    std::unordered_set<int> allVals{};

    // all nums to vals for faster lookup
    for (int num : nums)
      allVals.insert(num);

    // look up and find longest
    int longest, counter, currNum;
    longest = 0;
    for (int i{0}; i < nums.size(); i++) {
      counter = 0;
      currNum = nums[i];
      while (allVals.find(currNum) != allVals.end()) {
        counter++;
        if (currNum < 1000)
          currNum = std::pow(currNum, 2);
        else {
          break;
        }
      }
      longest = std::max(longest, counter);
    }

    return (longest != 1) ? longest : -1;
  }
};

class OnlineSolution {
public:
  int longestSquareStreak(std::vector<int> &nums) {
    constexpr int N{100'000};
    std::array<bool, N + 1> ns{};

    for (const int i : nums) {
      ns[i] = true;
    }

    int ans{-1};

    for (size_t i{0}; i < N; ++i) {
      if (ns[i] == false) {
        continue;
      }

      int len{0};
      size_t index{i};
      while (index < N && ns[index]) {
        ++len;
        index = index * index;
      }

      if (len > 1) {
        ans = std::max(ans, len);
      }
    }

    return ans;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  int output{solCur.longestSquareStreak(unit.input)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
