
#include <iostream>
#include <string>
#include <unordered_set>

class Test {
public:
  struct Case {
    std::string input;
    int output;
  };

  Case testA() {
    Case obj{"ababccc", 5};
    return obj;
  }

  Case testB() {
    Case obj{"aba", 2};
    return obj;
  }

  Case testC() {
    Case obj{"aa", 1};
    return obj;
  }

  Case testD() {
    Case obj{"wwwzfvedwfvhsww", 11};
    return obj;
  }
};

class Solution {
private:
  int findMaxSplit(int start, std::string s,
                   std::unordered_set<std::string> &existing) {
    int counter{0};

    for (int end{start + 1}; end <= s.size(); end++) {
      std::string substring{s.substr(start, end - start)};
      if (!existing.count(substring)) {
        existing.insert(substring);
        counter = std::max(counter, findMaxSplit(end, s, existing) + 1);
        existing.erase(substring);
      }
    }

    return counter;
  }

public:
  int maxUniqueSplit(std::string s) {
    std::unordered_set<std::string> existing{};

    // function call to recursively track
    return findMaxSplit(0, s, existing);
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};
  Test::Case input{testCur.testB()};
  int output{solCur.maxUniqueSplit(input.input)};

  if (output == input.output) {
    std::cout << "Success!\n" << std::endl;
  } else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << input.output << '\n';
    std::cout << "Actual: " << output << '\n';
    std::cout << std::endl;
  }

  return 0;
}
