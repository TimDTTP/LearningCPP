
#include <iostream>
#include <string>
#include <vector>

void printVector(std::vector<std::string> s) {
  for (auto i : s) {
    std::cout << i << '\n';
  }
  std::cout << '\n';
}

// comp loop
bool isLesser(std::string &a, std::string &b) {
  return (a.length() < b.length());
}

// nested loop approach
class SolutionA {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    std::string result{""};

    // sort vector from shortest word to longest
    std::sort(strs.begin(), strs.end(), isLesser);

    // loop #1 to loop through first word
    for (int i{0}; i < strs[0].length(); ++i) {
      // loop #2 to loop through vector
      for (std::string j : strs) {
        // exit condition
        if (strs[0][i] != j[i]) {
          return result;
        }
      }
      result += strs[0][i];
    }

    return result;
  }
};

// elimination approach
class SolutionB {
public:
  std::string longestCommonPrefix(std::vector<std::string> strs) {
    std::string result{strs[0]};

    // loop through vector
    for (int i{1}; i < strs.size(); ++i) {
      unsigned long maxLength{std::min(result.length(), strs[i].length())};

      if (strs[i].empty())
        return "";

      // loop through word
      for (int j{0}; j < maxLength; ++j) {
        if (result.length() > strs[i].length())
          result.erase(strs[i].length(), result.size());

        if (result[j] != strs[i][j]) {
          // delete rest of result
          result.erase(0 + j, result.size());
          break;
        }
      }
    }

    return result;
  }
};

int main() {
  std::vector<std::string> sample{"ca", "a"};

  SolutionA approachA;
  std::cout << "Approach A" << '\n';
  std::cout << "\"" << approachA.longestCommonPrefix(sample) << "\"" << '\n';
  std::cout << '\n';

  SolutionB approachB;
  std::cout << "Approach B" << '\n';
  std::cout << "\"" << approachB.longestCommonPrefix(sample) << "\"" << '\n';
  std::cout << '\n';

  return 0;
}
