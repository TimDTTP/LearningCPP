
#include <iostream>
#include <string>

// testcases
struct TestCase {
  std::string s;
  int k;
  int expected;
};

TestCase test1() {
  TestCase obj;
  obj.s = "acfgbd";
  obj.k = 2;
  obj.expected = 4;

  return obj;
}

TestCase test2() {
  TestCase obj;
  obj.s = "abcd";
  obj.k = 3;
  obj.expected = 4;

  return obj;
}

class Solution {
public:
  int longestIdealString(std::string s, int k) {
    // lorem ipsum

    return k;
  }
};

int main() {
  Solution solution = Solution();
  TestCase input = test1();

  std::cout << "Expected: " << input.expected << '\n' << '\n';
  std::cout << "Actual: " << solution.longestIdealString(input.s, input.k)
            << '\n'
            << '\n';

  return 0;
}
