
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  std::string removeKdigits(std::string num, int k) {
    std::stack<int> numStack{};
    int length{static_cast<int>(num.length())};
    int index{0};

    // insert digits into stack
    for (int digit : num) {
      while (!numStack.empty() && k > 0 && numStack.top() > digit) {
        numStack.pop();
        --k;
      }
      numStack.push(digit);
    }

    // if k > 0 still
    while (k > 0 && !numStack.empty()) {
      numStack.pop();
      --k;
    }

    // pull from stack and append to string
    std::string result{};
    while (!numStack.empty()) {
      result += numStack.top();
      numStack.pop();
    }
    std::reverse(result.begin(), result.end());

    // remove leading 0's
    size_t pos = result.find_first_not_of('0');
    if (pos != std::string::npos)
      result = result.substr(pos);
    else
      return "0";

    return result;
  }
};

int main() {
  std::string num{"54321"};
  int target{1};

  Solution ans = Solution();

  std::cout << ans.removeKdigits(num, target) << '\n';

  return 0;
}
