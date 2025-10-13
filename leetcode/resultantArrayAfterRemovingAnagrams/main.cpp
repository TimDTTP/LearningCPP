
#include <iostream>
#include <vector>

class Test {
public:
  void printVec(std::vector<std::string> vec) {
    for (std::string i : vec) {
      std::cout << i << ' ';
    }
    std::cout << '\n' << std::endl;
  }

  struct TestCase {
    std::vector<std::string> words;
    std::vector<std::string> output;
  };

  TestCase testA() { return {{"abba", "baba", "cd", "cd"}, {"abba", "cd"}}; }

  TestCase testB() {
    return {{"a", "b", "c", "d", "e"}, {"a", "b", "c", "d", "e"}};
  }
};

class Solution {
public:
  std::vector<std::string> removeAnagrams(std::vector<std::string> &words) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::vector<std::string> output{solCur.removeAnagrams(unit.words)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << '\n';
    testCur.printVec(unit.output);
    std::cout << "Actual: " << '\n';
    testCur.printVec(output);
  }
  std::cout << std::endl;

  return 0;
}
