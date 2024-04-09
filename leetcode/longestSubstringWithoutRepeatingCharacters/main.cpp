
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int maxSoFar{0};
    std::unordered_map<char, int> map{};

    for (int i{0}; i < s.length(); ++i) {
      // does not exist in map
      if (map.find(s[i]) == map.end()) {
        map[s[i]] = i;
      }

      // does exist in map
      else {
        // compare
        int diff{i - map[s[i]]};
        maxSoFar = std::max(diff, maxSoFar);

        // replace index value
        map[s[i]] = i;
      }
    }

    return maxSoFar;
  }
};

int main() {
  std::string s{"abcabcdefgbb"};

  Solution ans = Solution();

  int result = ans.lengthOfLongestSubstring(s);
  std::cout << result << '\n';

  return 0;
}
