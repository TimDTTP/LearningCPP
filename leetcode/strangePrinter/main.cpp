
#include <iostream>
#include <string>

// testing purposes
struct test {
  std::string s;
  int turns;
};

test testA() {
  test obj;
  obj.s = "aaabbb";
  obj.turns = 2;

  return obj;
}

test testB() {
  test obj;
  obj.s = "aba";
  obj.turns = 2;

  return obj;
}

test testC() {
  test obj;
  obj.s = "abcba";
  obj.turns = 3;

  return obj;
}

test testD() {
  test obj;
  obj.s = "ababa";
  obj.turns = 3;

  return obj;
}

class Solution {
public:
  int strangerPrinter(std::string s) {}
};

int main() {
  Solution cur = Solution();

  test caseA{testA()};
  test caseB{testB()};
  test caseC{testC()};
  test caseD{testD()};

  if (cur.strangerPrinter(caseA.s) == caseA.turns)
    std::cout << "Success!" << '\n' << std::endl;
  else
    std::cout << "Fail!" << '\n' << std::endl;

  if (cur.strangerPrinter(caseB.s) == caseB.turns)
    std::cout << "Success!" << '\n' << std::endl;
  else
    std::cout << "Fail!" << '\n' << std::endl;

  if (cur.strangerPrinter(caseC.s) == caseC.turns)
    std::cout << "Success!" << '\n' << std::endl;
  else
    std::cout << "Fail!" << '\n' << std::endl;

  if (cur.strangerPrinter(caseD.s) == caseD.turns)
    std::cout << "Success!" << '\n' << std::endl;
  else
    std::cout << "Fail!" << '\n' << std::endl;

  return 0;
}
