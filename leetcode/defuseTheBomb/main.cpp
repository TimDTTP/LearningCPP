
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> code;
    int k;
    std::vector<int> output;
  };

  TestCase testA() {
    TestCase obj{{5, 7, 1, 4}, 3, {12, 10, 16, 13}};
    return obj;
  }

  TestCase testB() {
    TestCase obj{{1, 2, 3, 4}, 0, {0, 0, 0, 0}};
    return obj;
  }

  TestCase testC() {
    TestCase obj{{2, 4, 9, 3}, -2, {12, 5, 6, 13}};
    return obj;
  }
};

class Solution {
public:
  std::vector<int> decrypt(std::vector<int> &code, int k) {
    std::vector<int> out;
    return out;
  }
};

void print(std::vector<int> vec) {
  for (int i : vec)
    std::cout << i << ' ';
  std::cout << '\n';
}

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::vector<int> output{solCur.decrypt(unit.code, unit.k)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: ";
    print(unit.output);
    std::cout << "Actual: ";
    print(output);
  }
  std::cout << std::endl;
}
