
#include <iostream>
#include <string>

class Solution {
public:
  // FIX:
  int strStr(std::string haystack, std::string needle) {}
};

// Test cases
struct tests {
  std::string h;
  std::string n;
  int output;
};

tests testA() {
  tests obj;
  obj.h = "sadbutsad";
  obj.n = "sad";
  obj.output = 0;

  return obj;
}

tests testB() {
  tests obj;
  obj.h = "leetcode";
  obj.n = "leeto";
  obj.output = -1;

  return obj;
}

int main() {
  // set up
  Solution cur = Solution();
  tests test;

  test = testA();
  if (cur.strStr(test.h, test.n) == test.output)
    std::cout << "Success!" << '\n';

  test = testB();
  if (cur.strStr(test.h, test.n) == test.output)
    std::cout << "Success!" << '\n';

  return 0;
}
