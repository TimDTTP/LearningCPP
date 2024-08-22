
#include <iostream>

struct test {
  int input;
  int output;
};

test testA() {
  test obj{5, 2};
  return obj;
}

test testB() {
  test obj{1, 0};
  return obj;
}

class Solution {
public:
  int findComplement(int num) { return num; }
};

int main() {
  // setup
  Solution cur = Solution();
  test caseA{testA()};
  test caseB{testB()};

  if (cur.findComplement(caseA.input) == caseA.output)
    std::cout << "Success!\n" << std::endl;
  else
    std::cout << "Failed!\n" << std::endl;

  if (cur.findComplement(caseB.input) == caseB.output)
    std::cout << "Success!\n" << std::endl;
  else
    std::cout << "Failed!\n" << std::endl;

  return 0;
}
