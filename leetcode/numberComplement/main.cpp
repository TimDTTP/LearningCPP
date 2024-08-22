
#include <iostream>
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

class Solution {
private:
  int decToBin(int num) {
    int bin{};
    int rem{};

    while (num != 0) {
      rem = num % 2;
      num /= 2;
      bin = bin * 10 + rem;
    }

    return bin;
  }

  // std::string complement(std::string bin) {}
  //
  // int binToDec(std::string bin) {}

public:
  int findComplement(int num) {
    int result{decToBin(num)};

    return result;
  }
};

int main() {
  // setup
  Solution cur = Solution();
  test caseA{testA()};
  test caseB{testB()};

  int resA{cur.findComplement(caseA.input)};
  if (resA == caseA.output)
    std::cout << "Success!\n" << std::endl;
  else
    std::cout << "Failed!\n" << std::endl;

  int resB{cur.findComplement(caseB.input)};
  if (resB == caseB.output)
    std::cout << "Success!\n" << std::endl;
  else
    std::cout << "Failed!\n" << std::endl;

  return 0;
}
