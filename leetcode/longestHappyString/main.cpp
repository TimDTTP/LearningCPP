
#include <algorithm>
#include <iostream>
#include <queue>
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

    std::string output{""};
    std::queue<char> temp;

    for (int i{0}; i < table[1].second; i++) {
      temp.push(table[0].first);
      table[0].second--;
      temp.push(table[1].first);
      table[1].second--;
    }
    std::cout << "size: " << temp.size() << '\n';

    for (int i{0}; i < std::min(table[0].second, table[2].second); i++) {
      temp.push(table[0].first);
      table[0].second--;
      temp.push(table[2].first);
      table[2].second--;
    }

    int target;
    int change;
    if (table[0].second) {
      target = 0;
      change = 0;
    } else {
      target = 1;
      change = 2;
    }

    while (!temp.empty()) {
      output += temp.front();
      if (temp.front() == table[target].first && table[change].second > 0) {
        output += table[change].first;
        table[change].second--;
      }
      temp.pop();
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
