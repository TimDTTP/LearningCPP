
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

// nested loop
std::string approachA(std::vector<std::string> &strs) {
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

class SolutionA {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    return "true";
  }
};

int main() {
  std::vector<std::string> sample{"fight", "figggg", "fign"};
  std::cout << approachA(sample) << '\n';

  return 0;
}
