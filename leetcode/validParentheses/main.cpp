
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

    // while loop
    for (char bracket : s) {
      if (bracketPair.c {
      }
    }
    // push into stack
    // conditional
  }
};

int main() { return 0; }
