
#include <iostream>
#include <numeric>
#include <string>

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
    int occurences[26]{};

    for (char c : s) {
      occurences[c - 'a'] = (occurences[c - 'a'] == 1)
                                ? occurences[c - 'a'] = 2
                                : occurences[c - 'a'] = 1;
    }
    return std::accumulate(std::begin(occurences), std::end(occurences), 0);
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
