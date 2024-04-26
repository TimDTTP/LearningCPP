
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

TestCase test3() {
  TestCase obj;
  obj.s = "pvjcci";
  obj.k = 4;
  obj.expected = 2;

  return obj;
}

class Solution {
private:
  int outBounds(std::string s, int k, int ptr1, int ptr2, int &max) {
    int counter{1};
    while (ptr2 < s.length()) {
      if (abs(s[ptr1] - s[ptr2]) <= k) {
        ++counter;
        ++ptr1;
        ++ptr2;
      } else {
        max = std::max(max, counter);
        return counter;
      }
    }

    return counter;
  }

public:
  int longestIdealString(std::string s, int k) {
    int max{1};
    int counter{1};
    int ptr1{0};
    int ptr2{1};

    while (ptr2 < s.length()) {
      // within k
      if (abs(ptr2 - ptr1) <= k) {
        ++counter;
        ++ptr1;
        ++ptr2;
      } else {
        int jump = outBounds(s, k, ptr1 + 1, ptr2 + 1, max);
        ptr1 += jump + 1;
        ptr2 += jump + 1;
      }
    }
    max = std::max(max, counter);

    return max;
  }
};

int main() {
  Solution solution = Solution();
  TestCase input = test3();

  std::cout << "Expected: " << input.expected << '\n' << '\n';
  std::cout << "Actual: " << solution.longestIdealString(input.s, input.k)
            << '\n'
            << '\n';

  return 0;
}
