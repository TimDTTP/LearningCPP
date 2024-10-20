
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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
    obj.a = 2;
    obj.b = 2;
    obj.c = 1;
    return obj;
  }
};

class Solution {
private:
  bool static cmp(std::pair<char, int> &a, std::pair<char, int> &b) {
    return a.second > b.second;
  }

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

    // to double up or not
    bool doubleUp{table[0].second > (table[1].second + table[2].second)};
    std::string output{""};

    if (!doubleUp) {
      int xz{table[0].second - table[1].second};
      int xyz{table[2].second - xz};

      // string creation
      for (int i{0}; i < (xyz + xz); i++) {
        if (xyz > 0) {
          output += table[0].first;
          output += table[1].first;
          output += table[2].first;
          xyz--;
        } else {
          output += table[0].first;
          output += table[2].first;
          xz--;
        }
      }

      return output;
    } else {
      std::cout << "here" << '\n';
      int doubleLargest{};
      int maxPosition{table[1].second + table[2].second + 1};
      if (table[0].second * 2 > maxPosition)
        table[0].second = maxPosition * 2;

      doubleLargest = table[0].second - maxPosition;

      // string creation
      while (table[0].second > 0 || table[1].second > 0 ||
             table[2].second > 0) {
        if (doubleLargest > 0) {
          output += table[0].first;
          output += table[0].first;
          doubleLargest--;
          table[0].second -= 2;
        } else {
          output += table[0].first;
        }
        if (table[1].second > 0) {
          output += table[1].first;
          table[1].second--;
        } else if (table[2].second > 0) {
          output += table[2].first;
          table[2].second--;
        }
      }

      return output;
    }

    return output;
  }
};

int main() {
  Test testCur = Test();
  Solution solCur = Solution();

  Test::TestCase input{testCur.testC()};
  std::string output{solCur.longestDiverseString(input.a, input.b, input.c)};
  std::cout << output << std::endl;

  return 0;
}
