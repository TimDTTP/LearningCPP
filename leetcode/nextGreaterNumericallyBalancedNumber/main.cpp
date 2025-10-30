
#include <algorithm>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    int n;
    int output;
  };

  TestCase testA() { return {1, 22}; }

  TestCase testB() { return {1000, 1333}; }

  TestCase testC() { return {3000, 3133}; }
};

class Solution {
public:
  int nextBeautifulNumber(int n) {
    // int to vector
    std::vector<int> num{};
    int temp;
    while (n > 0) {
      temp = n % 10;
      num.push_back(temp);
      n /= 10;
    }
    std::reverse(num.begin(), num.end());

    // Normalize number
    int size = num.size();
    num.emplace(num.begin(), 0);
    for (int i{0}; i < size; ++i) {
      if (num[i + 1] > size) {
        ++num[i];
        std::fill(num.begin() + (i + 1), num.end(), 0);
        i = 0;
      }
    }

    return 0;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
  int output{solCur.nextBeautifulNumber(unit.n)};

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
