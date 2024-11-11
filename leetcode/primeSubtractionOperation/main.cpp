
#include <ios>
#include <iostream>

class Test {
public:
  struct TestCase {
    std::vector<int> nums;
    bool output;
  };

  TestCase testA() {
    TestCase obj{{4, 9, 6, 10}, true};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{6, 8, 11, 12}, true};
    return obj;
  }

  TestCase testC() {
    TestCase obj{{5, 8, 3}, false};
    return obj;
  }
};

class Solution {
public:
  bool primeSubOperation(std::vector<int> &nums) {}
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  bool output{solCur.primeSubOperation(unit.nums)};

  std::cout << std::boolalpha;
  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
