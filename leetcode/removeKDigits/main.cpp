
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  std::string removeKdigits(std::string num, int k) {
    std::stack<int> numStack{};
    int length{static_cast<int>(num.length())};
    int index{0};

    while (index < length && k > 0) {
      if (numStack.empty()) {
        numStack.push(num[index]);
        continue;
      }

      if (numStack.top() < num[index])
        numStack.push(num[index]);
      else {
        while (numStack.top() >= num[index] && k > 0) {
          numStack.pop();
          --k;
        }
        numStack.push(num[index]);
      }
    }

    // pull from stack and append to string
    // remove leading 0's

    return num;
  }
};

int main() {
  std::string num{"54321"};
  int target{1};

  Solution ans = Solution();

  std::cout << ans.removeKdigits(num, target) << '\n';

  return 0;
}
