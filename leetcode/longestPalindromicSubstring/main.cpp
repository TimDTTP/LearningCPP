
#include <algorithm>
#include <iostream>
#include <string>

std::string test1() { return "ababa"; }
std::string test2() { return "babad"; }

class Solution {
private:
  std::string expandOdd(std::string s, int index) {
    std::string largest{""};
    int maxDelta{};
    maxDelta = std::min(index, (static_cast<int>(s.size()) - index));

    for (int delta{1}; delta <= maxDelta; ++delta) {
      if (s[index - delta] == s[index + delta]) {
        largest =
            s.substr(index - delta, ((index + delta) - (index - delta)) + 1);
      } else
        break;
    }

    return largest;
  }

public:
  std::string longestPalindrome(std::string s) {
    std::string max{};

    return max;
  }

  std::string testPrivate(std::string s, int index) {
    std::string testStr{expandOdd(s, index)};
    return testStr;
  }
};

int main() {
  Solution ans = Solution();

  // std::cout << ans.longestPalindrome(test1()) << '\n';

  std::cout << ans.testPrivate(test2(), 2) << '\n';

  return 0;
}
