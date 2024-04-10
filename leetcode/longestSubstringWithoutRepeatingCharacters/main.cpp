
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int maxSoFar{0};
    int lowerPos{0};
    std::unordered_map<char, int> charMap{};

    for (int i{0}; i < s.length(); ++i) {
      // if char does not exist in map
      if (charMap.count(s[i]) == 0 || charMap[s[i]] < lowerPos) {
        charMap[s[i]] = i;
        maxSoFar = std::max(maxSoFar, (i - lowerPos) + 1);
      }
      // if char exists in map
      else {
        lowerPos = charMap[s[i]] + 1;
        charMap[s[i]] = i;
      }
    }

    return maxSoFar;
  }
};

int main() {
  std::string s{"dvdf"};

  Solution ans = Solution();

  int result = ans.lengthOfLongestSubstring(s);
  std::cout << result << '\n';

  return 0;
}
