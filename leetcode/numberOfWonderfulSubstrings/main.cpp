
#include <iostream>
#include <string>
#include <unordered_map>

struct TestCase {
  std::string word;
  int expected;
};

TestCase test1() {
  TestCase obj;
  obj.word = "aba";
  obj.expected = 4;

  return obj;
}

TestCase test2() {
  TestCase obj;
  obj.word = "aabb";
  obj.expected = 9;

  return obj;
}

TestCase test3() {
  TestCase obj;
  obj.word = "he";
  obj.expected = 2;

  return obj;
}

class Solution {
public:
  long long wonderfulSubstrings(std::string word) {
    int counter{0};

    return counter;
  }
};

int main() {
  Solution answer = Solution();

  TestCase input{test1()};
  long long actual{answer.wonderfulSubstrings(input.word)};

  std::cout << "Expected: " << '\n' << input.expected << '\n';
  std::cout << "Actual: " << '\n' << actual << '\n';

  return 0;
}
