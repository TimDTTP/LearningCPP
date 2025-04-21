
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> differences;
    int lower;
    int upper;
    int output;
  };

  TestCase testA() {
    return {
        {1, -3, 4},
        1,
        6,
        2,
    };
  }

  TestCase testB() {
    return {
        {3, -4, 5, 1, -2},
        -4,
        5,
        4,
    };
  }

  TestCase testC() {
    return {
        {4, -7, 2},
        3,
        6,
        0,
    };
  }
};

class Solution {
public:
  int numberOfArray(std::vector<int> &differences, int lower, int upper) {
    int slider{0};
    std::pair<int, int> extremes{0, 0};
    for (int addend : differences) {
      slider += addend;
      if (slider > extremes.first)
        extremes.first = slider;
      else if (slider < extremes.second)
        extremes.second = slider;
    }

    int delta{(upper - lower) - (extremes.first - extremes.second) + 1};
    return (delta > 0) ? delta : 0;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  int output{solCur.numberOfArray(unit.differences, unit.lower, unit.upper)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;

  return 0;
}
