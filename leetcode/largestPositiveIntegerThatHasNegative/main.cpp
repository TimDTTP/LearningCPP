
#include <iostream>
#include <vector>

struct TestCase {
  std::vector<int> nums;
  int expected;
};

// Test cases
TestCase test1() {
  TestCase obj;
  obj.nums = {-1, 2, -3, 3};
  obj.expected = 3;

  return obj;
}

TestCase test2() {
  TestCase obj;
  obj.nums = {-1, 10, 6, 7, -7, 1};
  obj.expected = 7;

  return obj;
}

TestCase test3() {
  TestCase obj;
  obj.nums = {-10, 8, 6, 7, -2, -3};
  obj.expected = -1;

  return obj;
}

class Solution {
public:
  int findMaxK(std::vector<int> &nums) { return 0; }
};

int main() {
  TestCase input{test1()};
  Solution answer = Solution();

  int output{answer.findMaxK(input.nums)};

  std::cout << "Expected: " << '\n' << input.expected << "\n\n";
  std::cout << "Actual: " << '\n' << output << "\n\n";

  return 0;
}
