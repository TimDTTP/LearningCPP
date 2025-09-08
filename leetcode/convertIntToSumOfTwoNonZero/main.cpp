
#include <format>
#include <iostream>
#include <string>
#include <vector>

class Test {
public:
  struct TestCase {
    int n;
    std::vector<int> output;
  };

  TestCase testA() { return {2, {1, 1}}; }
  TestCase testB() { return {11, {2, 9}}; }
};

class Solution {
public:
  std::vector<int> getNoZeroIntegers(int n) {
    auto noZero = [](int num) -> bool {
      std::string s{std::to_string(num)};
      for (int i{0}; i < s.length(); i++) {
        if (s[i] == '0') {
          return false;
        }
      }
      return true;
    };

    for (int a{1}; a < n; a++) {
      if (noZero(a) && noZero(n - a)) {
        return {a, (n - a)};
      }
    }

    // useful code here
    return {};
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  std::vector<int> output{solCur.getNoZeroIntegers(unit.n)};

  if (output[0] + output[1] == unit.n) {
    std::cout << "Success!\n";
  } else {
    std::cout << "Failed!\n{";
  }
  std::cout << std::format("[{}, {}]\n", output[0], output[1]);

  return 0;
}
