
#include <iostream>
#include <numeric>
#include <unordered_map>

class Test {
public:
  struct TestCase {
    std::string s;
    int k;
    int output;
  };

  TestCase testA() {
    TestCase obj{"aabaaaacaabc", 2, 8};
    return obj;
  }

  TestCase testB() {
    TestCase obj{"a", 1, -1};
    return obj;
  }

  TestCase testC() {
    TestCase obj{"abc", 1, 3};
    return obj;
  }
};

class Solution {
private:
  void recursion(std::string s, std::unordered_map<char, int> targets,
                 int &lowest, int moves) {
    // exit condition
    int sum{std::accumulate(
        targets.begin(), targets.end(), 0,
        [](int total, const std::unordered_map<char, int>::value_type &item) {
          return total + item.second;
        })};
    if (sum == 0) {
      std::cout << moves << std::endl;
      lowest = std::min(lowest, moves);
      return;
    }
    if (s.size() == 0)
      return;

    moves++;
    std::string sTemp{s};
    std::unordered_map<char, int> targetsTemp{targets};

    // leftmost
    if (targets[s.front()] > 0)
      targetsTemp[s.front()]--;
    sTemp.erase(sTemp.begin());
    recursion(sTemp, targetsTemp, lowest, moves);

    // rightmost
    sTemp = s;
    targetsTemp = targets;
    if (targets[s.back()] > 0)
      targetsTemp[s.back()]--;
    sTemp.pop_back();
    recursion(sTemp, targetsTemp, lowest, moves);
  }

public:
  int takeCharacters(std::string s, int k) {
    std::unordered_map<char, int> targets{{'a', k}, {'b', k}, {'c', k}};
    int lowest = s.size() + 1;

    recursion(s, targets, lowest, 0);

    if (lowest == s.size() + 1)
      return -1;

    return lowest;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  int output{solCur.takeCharacters(unit.s, unit.k)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
