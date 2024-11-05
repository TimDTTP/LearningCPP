
#include <iostream>
#include <string>

class Test {
public:
  struct TestCase {
    std::string s;
    int output;
  };

  TestCase testA() {
    TestCase obj{"1001", 2};
    return obj;
  }

  TestCase testB() {
    TestCase obj{"10", 1};
    return obj;
  }

  TestCase testC() {
    TestCase obj{"0000", 0};
    return obj;
  }

  TestCase testD() {
    TestCase obj{"111001100011100111", 5};
    return obj;
  }
};

class Solution {
public:
  int minChanges(std::string s) {
    int changes{0};
    std::queue<bool> isEven{};

    // traverse string, add odd || even to queue
    int counter{0};
    char last{s[0]};
    for (char i : s) {
      if (i == last) {
        counter++;
      } else {
        isEven.push(!(counter % 2));
        counter = 1;
        last = i;
      }
    }
    if (counter > 0)
      isEven.push(!(counter % 2));

    // traverse queue
    bool oddLoaded{false};
    while (!isEven.empty()) {
      // odd
      if (!isEven.front()) {
        if (!oddLoaded) {
          oddLoaded = true;
          counter = 1;
        } else {
          changes += counter;
          oddLoaded = false;
        }
      }
      // even
      else {
        if (oddLoaded)
          counter++;
      }
      isEven.pop();
    }

    return changes;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testD()};
  int output{solCur.minChanges(unit.s)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
