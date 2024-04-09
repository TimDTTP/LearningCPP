
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int maxSoFar{1};
    int counter{0};
    std::unordered_map<char, int> map{};

    if (s.length() == 0)
      return 0;

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

        // reset counter
        counter = 0;
      }
      ++counter;

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
