
#include <iostream>
#include <map>
#include <string>

class Test {
public:
  struct TestCase {
    int a;
    int b;
    int c;
  };

  TestCase testA() {
    TestCase obj;
    obj.a = 1;
    obj.b = 1;
    obj.c = 7;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.a = 7;
    obj.b = 1;
    obj.c = 0;
    return obj;
  }

  TestCase testC() {
    TestCase obj;
    obj.a = 76;
    obj.b = 69;
    obj.c = 92;
    return obj;
  }
};

class Solution {
private:
  bool static cmp(std::pair<char, int> &a, std::pair<char, int> &b) {
    return a.second > b.second;
  }

  int numPos(int a) { return ((a / 2) + (a % 2)); }

public:
  std::string longestDiverseString(int a, int b, int c) {
    std::vector<std::pair<char, int>> table{{'a', a}, {'b', b}, {'c', c}};

    // sort array from greatest to least
    std::sort(table.begin(), table.end(), cmp);

    // WARN: print current array
    std::cout << "Current array\n";
    for (std::pair<char, int> i : table) {
      std::cout << i.first << '\n';
    }
    std::cout << std::endl;

    int maxPos{numPos(table[0].second)};

    if (table[1].second < maxPos) {
    }

    return "SAMPLE";
  }
};

int main() {
  Test testCur = Test();
  Solution solCur = Solution();

  Test::TestCase input{testCur.testA()};
  std::string output{solCur.longestDiverseString(input.a, input.b, input.c)};
  std::cout << output << std::endl;

  return 0;
}
