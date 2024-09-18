
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class TestCases {
public:
  struct Sample {
    std::string s1;
    std::string s2;
  };

  Sample testA() {
    Sample obj;
    obj.s1 = "this apple is sweet";
    obj.s2 = "this apple is sour";

    return obj;
  }

  Sample testB() {
    Sample obj;
    obj.s1 = "apple apple";
    obj.s2 = "banana";

    return obj;
  }
};

class Solution {
public:
  std::vector<std::string> uncommonFromSentences(std::string s1,
                                                 std::string s2) {
    std::vector<std::string> out;
    std::unordered_map<std::string, int> word;

    // combine to 1 string
    s1 += ' ' + s2;

    // lambda function to check if word is pre-existing
    auto check = [&](std::unordered_map<std::string, int> &word,
                     std::string temp) {
      if (word.count(temp)) {
        ++word[temp];
      } else {
        word[temp] = 1;
      }
    };

    // add s1 to vector
    std::size_t search{};
    std::string temp{};
    while (!s1.empty()) {
      search = s1.find(' ');
      if (search == std::string::npos) {
        temp = s1;
        check(word, temp);
        s1.clear();
      } else {
        temp = s1.substr(0, search);
        check(word, temp);
        s1.erase(0, search + 1);
      }
    }

    for (std::pair<std::string, int> occur : word) {
      if (occur.second == 1)
        out.push_back(occur.first);
    }

    return out;
  }
};

int main() {
  TestCases testCur = TestCases();
  Solution solCur = Solution();

  TestCases::Sample input{testCur.testA()};
  std::vector<std::string> output{
      solCur.uncommonFromSentences(input.s1, input.s2)};

  for (std::string i : output)
    std::cout << i << ' ';
  std::cout << '\n';

  return 0;
}
