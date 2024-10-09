
#include <iostream>
#include <string>

class Solution {
public:
  int minAddToMakeValid(std::string s) {
    std::stack<char> currParentheses;
    int counter{0};

    for (char parentheses : s) {
      if (parentheses == '(')
        currParentheses.push(parentheses);
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

  int output{solCur.minAddToMakeValid("())")};
  std::cout << output << '\n';
}
