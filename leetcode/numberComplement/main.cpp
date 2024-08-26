
#include <bitset>
#include <iostream>
#include <stack>
#include <string>

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

test testC() {
  test obj{7, 0};
  return obj;
}

test testD() {
  test obj{2, 1};
  return obj;
}

class Solution {
public:
  int findComplement(int num) {
    // convert into binary
    std::string bin{std::bitset<32>(num).to_string()};

    // strip leading zeros
    bin.erase(bin.begin(), bin.begin() + bin.find_first_not_of('0'));

    // flip bits
    for (char &i : bin) {
      if (i == '0')
        i = '1';
      else
        i = '0';
    }

    // convert into decimal
    unsigned long dec{std::bitset<32>(bin).to_ulong()};

    return dec;
  }
};

int main() {
  // setup
  Solution cur = Solution();
  test caseA{testA()};
  test caseB{testB()};
  test caseC{testC()};
  test caseD{testD()};

  int resA{cur.findComplement(caseA.input)};
  std::cout << resA << '\n';
  if (resA == caseA.output)
    std::cout << "Success!\n" << std::endl;
  else
    std::cout << "Failed!\n" << std::endl;

  int resB{cur.findComplement(caseB.input)};
  std::cout << resB << '\n';
  if (resB == caseB.output)
    std::cout << "Success!\n" << std::endl;
  else
    std::cout << "Failed!\n" << std::endl;

  int resC{cur.findComplement(caseC.input)};
  std::cout << resC << '\n';
  if (resC == caseC.output)
    std::cout << "Success!\n" << std::endl;
  else
    std::cout << "Failed!\n" << std::endl;

  int resD{cur.findComplement(caseD.input)};
  std::cout << resD << '\n';
  if (resD == caseD.output)
    std::cout << "Success!\n" << std::endl;
  else
    std::cout << "Failed!\n" << std::endl;

  return 0;
}
