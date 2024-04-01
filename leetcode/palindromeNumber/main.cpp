
#include <ios>
#include <iostream>
#include <stack>

// function to print stack
void printStack(std::stack<int> uStack) {
  while (!uStack.empty()) {
    std::cout << uStack.top() << '\n';
    uStack.pop();
  }
  std::cout << '\n';
}

class Solution {
public:
  bool isPalindrome(int x) {
    // lorem ipsum
    /*
     * Approach
     * - divide in half
     * - push into stack
     * - pop
     *   - if equal, return true
     *   - if not, return false
     */

    std::stack<int> stackPrime{};
    std::stack<int> stackCompare{};

    int numCount{};

    // push values into stack
    while (x > 0) {
      int digit{x % 10};
      x /= 10;
      stackPrime.push(digit);
      ++numCount;
    }

    // return true if remainder == 1, false is remainder == 0
    auto isOdd{[](int size) -> bool { return (size % 2); }};

    // pop half of stack into second stack
    for (int i{0}; i < numCount / 2; ++i) {
      stackCompare.push(stackPrime.top());
      stackPrime.pop();
    }

    // pop median if odd
    if (isOdd(numCount))
      stackPrime.pop();

    // compare both stack return false if not matching
    while (!stackPrime.empty() && !stackCompare.empty()) {
      // if stacks DO NOT match
      if (!(stackPrime.top() == stackCompare.top())) {
        return false;
      } else {
        stackPrime.pop();
        stackCompare.pop();
      }
    }

    return true;
  }
};

int main() {
  int val{14141};

  Solution cursor = Solution();
  std::cout << std::boolalpha;
  std::cout << (cursor.isPalindrome(val)) << '\n';

  return 0;
}
