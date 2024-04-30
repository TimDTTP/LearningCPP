
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

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

    // loop through string
    for (int start{0}; start < word.size(); ++start) {
      std::unordered_map<char, int> map{};
      std::unordered_set<char> isOdd{};

      // loop through the rest of string
      for (int rest{start}; rest < word.size(); ++rest) {
        // increment char in map
        ++map[word[rest]];

        // if odd add to set
        if (map[word[rest]] % 2 != 0)
          isOdd.insert(word[rest]);
        else
          isOdd.erase(word[rest]);

        // check # of odd
        if (isOdd.size() <= 1)
          ++counter;
      }

      // clear containers
      map.clear();
      isOdd.clear();
    }

    return counter;
  }
};

int main() {
  Solution answer = Solution();

  TestCase input{test3()};
  long long actual{answer.wonderfulSubstrings(input.word)};

  std::cout << "Expected: " << '\n' << input.expected << '\n';
  std::cout << "Actual: " << '\n' << actual << '\n';

  return 0;
}
