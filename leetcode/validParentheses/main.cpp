
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

class Solution {
public:
  bool isValid(std::string s) {
    std::unordered_map<char, char> bracketPair{
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
    };

    std::stack<char> open{};

    // function to find key value
    auto findKey{[](std::unordered_map<char, char> map, char lookUp) {
      if (map.find(lookUp) == map.end())
        return false;
      else
        return true;
    }};

    // while loop
    for (char bracket : s) {
      if (findKey(bracketPair, bracket)) {
        open.push(bracket);
        continue;
      } else if (bracketPair[open.top()] != bracket) {
        return false;
      } else if (bracketPair[open.top()] == bracket) {
        open.pop();
      }
    }

    // check for dangling open parentheses
    if (!open.empty())
      return false;

    return true;
  }
};

int main() {
  std::string s{"(){[]]}"};

  Solution cursor = Solution();
  std::cout << std::boolalpha;
  std::cout << cursor.isValid(s) << '\n';

  return 0;
}
