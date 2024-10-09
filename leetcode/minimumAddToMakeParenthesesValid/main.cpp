
#include <iostream>
#include <sstream>
#include <string>

class Solution {
public:
  int minAddToMakeValid(std::string s) {
    std::stringstream ss{s};
    char c;
    std::stack<char> currParentheses;
    int counter;

    while (ss >> c) {
      if (c == '(')
        currParentheses.push(c);
      else {
        if (currParentheses.empty())
          counter++;
        else
          currParentheses.pop();
      }
    }

    // if remaining '('
    if (!currParentheses.empty())
      counter += currParentheses.size();

    return counter;
  }
};

int main() {
  Solution solCur = Solution();

  int output{solCur.minAddToMakeValid("(((")};
  std::cout << output << '\n';
}
