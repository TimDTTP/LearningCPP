
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

test testE() {
  test obj;
  obj.s = "abc";
  obj.turns = 3;

  return obj;
}

class Solution {
private:
  int countTurns(std::string s, int start, int end, int counter) {
    // find repeat
    while (s[end] != s[start] && start < end)
      --end;

    ++counter;
    if (start >= end)
      return counter;
    ++start;
    --end;

    return countTurns(s, start, end, counter);
  }

public:
  int strangerPrinter(std::string s) {
    const int len{static_cast<int>(s.size())};
    int start{0};
    int end{len - 1};
    int turns{0};

    turns = countTurns(s, start, end, turns);

    // find repeat
    // call function
    // use end as next start
    // end when start == end

    return turns;
  }
};

int main() {
  Solution cur = Solution();

  test caseA{testA()};
  test caseB{testB()};
  test caseC{testC()};
  test caseD{testD()};
  test caseE{testE()};

  // if (cur.strangerPrinter(caseA.s) == caseA.turns)
  //   std::cout << "Success!" << '\n' << std::endl;
  // else
  //   std::cout << "Fail!" << '\n' << std::endl;
  //
  // if (cur.strangerPrinter(caseB.s) == caseB.turns)
  //   std::cout << "Success!" << '\n' << std::endl;
  // else
  //   std::cout << "Fail!" << '\n' << std::endl;
  //
  // if (cur.strangerPrinter(caseC.s) == caseC.turns)
  //   std::cout << "Success!" << '\n' << std::endl;
  // else
  //   std::cout << "Fail!" << '\n' << std::endl;
  //
  // if (cur.strangerPrinter(caseD.s) == caseD.turns)
  //   std::cout << "Success!" << '\n' << std::endl;
  // else
  //   std::cout << "Fail!" << '\n' << std::endl;

  std::cout << cur.strangerPrinter(caseE.s) << '\n';
  if (cur.strangerPrinter(caseE.s) == caseE.turns)
    std::cout << "Success!" << '\n' << std::endl;
  else
    std::cout << "Fail!" << '\n' << std::endl;

  return 0;
}
