
#include <iostream>
#include <string>
#include <unordered_map>

class Test {
public:
  struct TestCase {
    std::string s;
    int output;
  };

  TestCase testA() { return {"abaacbcbb", 5}; }

  TestCase testB() { return {"aa", 2}; }
};

class Solution {
public:
  int minimumLength(std::string s) {
    int count{0};
    std::unordered_map<char, bool> occurence;

    for (char c : s) {
      if (!occurence.count(c)) {
        occurence[c] = false;
        ++count;
      } else {
        if (occurence[c]) {
          occurence[c] = false;
          --count;
        } else {
          occurence[c] = true;
          ++count;
        }
      }
    }

    return count;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
  int output{solCur.minimumLength(unit.s)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
