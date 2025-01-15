
#include <bitset>
#include <iostream>

class Test {
public:
  struct TestCase {
    int num1;
    int num2;
    int output;
  };

  TestCase testA() { return {3, 5, 3}; }

  TestCase testB() { return {1, 12, 3}; }
};

class Solution {
public:
  int minimizeXor(int num1, int num2) {
    std::bitset<30> bitNum1(num1);
    std::bitset<30> bitNum2(num2);
    std::bitset<30> bitTemp;
    int count(bitNum2.count());
    int pos{0};

    // left to right, setting bits to match highest set bits
    while (count && (pos != 29)) {
      if (bitNum1[pos]) {
        bitTemp[pos].flip();
        --count;
      }
      ++pos;
    }
    std::cout << count << '\n';
    std::cout << bitTemp << '\n';

    // right to left, setting residual bits to slowly increment
    while (count) {
      std::cout << bitNum1[pos] << '\n';
      if (!bitNum1[pos]) {
        bitTemp[pos].flip();
        --count;
        std::cout << pos << '\n';
      }
      --pos;
    }

    return std::stoi(bitTemp.to_string(), nullptr, 2);
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
  int output{solCur.minimizeXor(unit.num1, unit.num2)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
