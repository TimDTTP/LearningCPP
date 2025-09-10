
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    int n;
    std::vector<std::vector<int>> languages;
    std::vector<std::vector<int>> friendships;
    int output;
  };

  TestCase testA() {
    TestCase obj;
    obj.n = 2;
    obj.languages = {{1}, {2}, {1, 2}};
    obj.friendships = {{1, 2}, {1, 3}, {2, 3}};
    obj.output = 1;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.n = 3;
    obj.languages = {{2}, {1, 3}, {1, 2}, {3}};
    obj.friendships = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
    obj.output = 2;
    return obj;
  }
};

class Solution {
public:
  int minimumTeachings(int n, std::vector<std::vector<int>> &languages,
                       std::vector<std::vector<int>> &friendships) {
    // useful code
    // here
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.minimumTeachings(unit.n, unit.languages, unit.friendships)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;

  return 0;
}
