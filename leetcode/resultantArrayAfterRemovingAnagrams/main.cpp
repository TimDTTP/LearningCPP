
#include <iostream>
#include <unordered_map>
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
    std::vector<std::unordered_map<char, int>> table{};

    // compile words into vector<map<char, int>>
    for (std::string word : words) {
      std::unordered_map<char, int> charInWord{};
      for (char letter : word) {
        charInWord[letter]++;
      }
      table.push_back(charInWord);
    }

    // loop through and check if congruent
    int size = words.size();
    for (int i{0}; i < (size - 1); ++i) {
      if (table[i] == table[i + 1]) {
        table.erase(table.begin() + (i + 1));
        words.erase(words.begin() + (i + 1));
        --i;
        --size;
      }
    }

    return words;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
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
