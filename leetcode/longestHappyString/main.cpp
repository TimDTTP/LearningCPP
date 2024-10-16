
#include <array>
#include <iostream>
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
};

class Solution {
public:
  std::string longestDiverseString(int a, int b, int c) {
    std::array<std::pair<int, int>, 3> moves;

    // add values to array
    moves[0].second = a;
    moves[1].second = b;
    moves[2].second = c;

    // sort array from greatest to least
    std::sort(moves.begin(), moves.end(),
              [](std::pair<int, int> a, std::pair<int, int> b) {
                return a.second > b.second;
              });

    // WARN: print current array
    for (std::pair<int, int> letters : moves) {
      std::cout << letters.second << std::endl;
    }

    // reduce moves

    return "";
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
