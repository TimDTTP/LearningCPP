
#include <algorithm>
#include <iostream>
#include <string>

std::string test1() { return "ababa"; }
std::string test2() { return "babad"; }
std::string test3() { return "asdffds"; }
std::string test4() { return "cbbd"; }
std::string test5() { return "a"; }

class Solution {
private:
  std::string expandOdd(std::string s, int index) {
    std::string largest{};
    int maxDelta{};
    maxDelta = std::min(index, (static_cast<int>(s.size()) - index));

    for (int delta{1}; delta <= maxDelta; ++delta) {
      if (s[index - delta] == s[index + delta]) {
        largest =
            s.substr(index - delta, ((index + delta) - (index - delta)) + 1);
      } else
        break;
    }

    if (largest.empty())
      largest = s[index];

    return largest;
  }

  std::string expandEven(std::string s, int index) {
    std::string largest{""};
    int maxDelta{};

    // check if next char is same, if NOT just return
    if (s[index] != s[index + 1])
      return largest;
    else {
      largest = s.substr(index, 2);
    }

    maxDelta = std::min(index, (static_cast<int>(s.size()) - index));

    for (int delta{1}; delta <= maxDelta; ++delta) {
      if (s[index - delta] == s[index + 1 + delta]) {
        largest = s.substr(index - delta,
                           ((index + 1 + delta) - (index - delta)) + 1);
      } else
        break;
    }

    return largest;
  }

public:
  std::string longestPalindrome(std::string s) {
    std::string max{};

    // call functions and compare to current largest thus far
    for (int i{0}; i < s.size(); ++i) {
      std::string even{expandEven(s, i)};
      std::string odd{expandOdd(s, i)};

      max = (max.size() > even.size()) ? max : even;
      max = (max.size() > odd.size()) ? max : odd;
    }

    return max;
  }

  // TEST: REMOVE BEFORE SUBMITTING
  std::string testPrivate(std::string s, int index) {
    std::string testStr{expandEven(s, index)};
    return testStr;
  }
};

int main() {
  Solution ans = Solution();

  std::cout << ans.longestPalindrome(test2()) << '\n';

  return 0;
}
