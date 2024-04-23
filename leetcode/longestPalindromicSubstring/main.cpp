
#include <algorithm>
#include <iostream>
#include <string>

std::string test1() { return "ababa"; }

class Solution {
private:
  std::string expandOdd(std::string s, int index) {
    int delta{1};
    std::string max{};
    int max{std::min(index, s.size() - index)};

    if (s[index - delta] == s[index + delta]) {
    }
  }

public:
  std::string longestPalindrome(std::string s) {
    std::string max{};

    return max;
  }
};

int main() {
  Solution ans = Solution();

  std::cout << ans.longestPalindrome(test1()) << '\n';

  return 0;
}
