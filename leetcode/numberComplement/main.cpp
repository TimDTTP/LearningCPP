
#include <iostream>
#include <stack>

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

  int complement(int bin) {
    int bit{};
    int compBin{};
    while (bin != 0) {
      bit = bin % 10;
      bin /= 10;

      // flip
      if (bit == 1)
        bit = 0;
      else
        bit = 1;

      compBin = compBin * 10 + bit;
    }

    return compBin;
  }

  int binToDec(int bin) {
    // assuming leading 0's dropped
    std::stack<int> nums{};
    while (bin != 0) {
      nums.push(bin % 10);
      bin /= 10;
    }
    while (!nums.empty()) {
      bin = bin * 2 + nums.top();
      nums.pop();
    }

    return bin;
  }

public:
  int findComplement(int num) {
    int result{decToBin(num)};
    result = complement(result);
    result = binToDec(result);

    return result;
  }
};

int main() {
  // setup
  Solution cur = Solution();
  test caseA{testA()};
  test caseB{testB()};

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

  return 0;
}
