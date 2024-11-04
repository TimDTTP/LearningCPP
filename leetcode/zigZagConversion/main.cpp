
#include <cstddef>
#include <iostream>

class Test {
public:
  struct TestCase {
    std::string s;
    int numRows;
    std::string output;
  };

  TestCase testA() {
    TestCase obj;
    obj.s = "PAYPALISHIRING";
    obj.numRows = 3;
    obj.output = "PAHNAPLSIIGYIR";
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.s = "PAYPALISHIRING";
    obj.numRows = 4;
    obj.output = "PINALSIGYAHRPI";
    return obj;
  }

  TestCase testC() {
    TestCase obj;
    obj.s = "A";
    obj.numRows = 1;
    obj.output = "A";
    return obj;
  }
};

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    std::size_t size{s.size()};
    std::string convStr{""};

    // edge case
    if (numRows == 1)
      return s;

    // interate through first numRows
    int temp;
    bool down;
    for (int i{0}; i < numRows; i++) {
      if (i >= size)
        return convStr;
      convStr.push_back(s[i]);
      temp = i;
      down = true;
      if (i == 0 || i == numRows - 1) {
        temp += (numRows - 1) * 2;
        while (temp < size) {
          convStr.push_back(s[temp]);
          temp += (numRows - 1) * 2;
        }
      } else {
        temp += (numRows - (i + 1)) * 2;
        while (temp < size) {
          // down direction
          if (down) {
            convStr.push_back(s[temp]);
            temp += i * 2;
            down = false;
          }

          // up direction
          else {
            convStr.push_back(s[temp]);
            temp += (numRows - (i + 1)) * 2;
            down = true;
          }
        }
      }
    }

    return convStr;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  std::string output{solCur.convert(unit.s, unit.numRows)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
