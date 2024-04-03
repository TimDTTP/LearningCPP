
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

class Solution {
private:
  void printStack(std::stack<char> uStack) {
    std::cout << "Printing stack: " << '\n';

    while (!uStack.empty()) {
      std::cout << uStack.top() << '\n';
      uStack.pop();
    }
    std::cout << '\n';
  }

  void printQueue(std::queue<char> uQueue) {
    std::cout << "Printing queue: " << '\n';

    while (!uQueue.empty()) {
      std::cout << uQueue.front() << '\n';
      uQueue.pop();
    }
    std::cout << '\n';
  }

public:
  bool const isValid(std::string s) {
    std::unordered_map<char, char> bracketPair{
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
    };

    std::stack<char> open{};

    // while loop
    for (char bracket : s) {
      bool isOpen{bracketPair.find(bracket) != bracketPair.end()};

      if (isOpen) {
        open.push(bracket);
        continue;
      } else if ((open.empty() && !isOpen) ||
                 (bracketPair[open.top()] != bracket)) {
        return false;
      } else {
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
  std::string s{"(){[]}"};

  Solution cursor = Solution();
  std::cout << std::boolalpha;
  std::cout << cursor.isValid(s) << '\n';

  return 0;
}
