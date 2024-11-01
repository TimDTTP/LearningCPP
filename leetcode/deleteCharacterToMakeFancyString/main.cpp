
#include <iostream>
#include <string>

class Test {
public:
  struct TestCase {
    std::string s;
    std::string output;
  };

  TestCase testA() {
    TestCase obj{"leeetcode", "leetcode"};
    return obj;
  }

  TestCase testB() {
    TestCase obj{"aaabaaaa", "aabaa"};
    return obj;
  }
};

class Solution {
public:
  std::string makeFancyString(std::string s) {
    char last{s[0]};
    int freq{1};

    for (int i{1}; i < s.size(); i++) {
      if (s[i] == last) {
        freq++;
      } else {
        if (freq > 2) {
          s.erase(i - (freq - 2), freq - 2);
          i = i - (freq - 2);
        }
        last = s[i];
        freq = 1;
      }
    }

    if (freq > 2)
      s.erase(s.size() - (freq - 2), freq - 2);

    return s;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::string output{solCur.makeFancyString(unit.s)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
