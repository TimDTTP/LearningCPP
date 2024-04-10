
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int maxSoFar{1};
    int counter{0};
    std::unordered_map<char, int> charMap{};

    for (int i{0}; i < s.length(); ++i) {
      ++counter;

      // if char already exist in map
      if (charMap.find(s[i]) != charMap.end()) {
        int diff{i - charMap[s[i]]};
        maxSoFar = std::max(diff, maxSoFar);
        counter = 0;
      }
      // if new char appears
      else {
        charMap[s[i]] = i;
      }

      // compare values
      maxSoFar = std::max(counter, maxSoFar);
    }

    return maxSoFar;
  }
};

int main() {
  std::string s{"abba"};

  Solution ans = Solution();

  int result = ans.lengthOfLongestSubstring(s);
  std::cout << result << '\n';

  return 0;
}
