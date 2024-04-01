
#include <iostream>
#include <map>
#include <string>

int approach1(std::string s) {
  // map char to values
  std::map<char, int> romanConvert{
      {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
      {'C', 100}, {'D', 500}, {'M', 1000},
  };

  // total
  int sum{0};

  // loop through string to compare values
  for (int i{0}; i < s.length(); ++i) {
    if (romanConvert[s[i + 1]] > romanConvert[s[i]]) {
      sum += (romanConvert[s[i + 1]] - romanConvert[s[i]]);
      // skip next value
      ++i;
    } else {
      sum += romanConvert[s[i]];
    }
  }

  return sum;
}

class Solution {
public:
  int romanToInt(std::string s) { return approach1(s); }
};

int main() {
  std::string number{"CM"};
  Solution cursor = Solution();

  std::cout << cursor.romanToInt(number) << '\n';

  return 0;
}
