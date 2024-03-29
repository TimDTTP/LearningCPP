
#include <iostream>
#include <stack>

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
    std::stack<int> start{};
    std::stack<int> end{};

    while (x > 0) {
      int digit{x % 10};
      x /= 10;
      numStack.push(digit);
    }

    return true;
  }
};

int main() {
  int val{121};

  Solution cursor = Solution();
  cursor.isPalindrome(val);

  return 0;
}
