
#include <iostream>
#include <string>

class Solution {
public:
  void deleteDigits(std::string &num, int start, int end) {
    num.erase(num.begin() + start, num.begin() + end);
  }

  std::string removeKdigits(std::string num, int k) {
    int start{0};
    int end{0};

    // if length matches number of digit
    if (num.length() == k)
      return static_cast<std::string>("0");

    // check if first k'th digits result in 0
    if (num[k] == '0') {
      bool found{false};
      // find first non-leading zero integer
      for (int i{k}; i < num.length(); ++i) {
        if (num[i] != '0') {
          found = true;
          end = i;
          break;
        }
      }

      // if 0 is at the end of num
      if (!found)
        return static_cast<std::string>("0");

      // delete k and leading 0's
      deleteDigits(num, start, end);

      return num;
    }

    // lastly, just delete largest value and following k'th digits
    for (int digit{0}; digit <= (num.length() - k); ++digit) {
      if (num[digit] > num[start])
        start = digit;
    }
    deleteDigits(num, start, start + k);

    return num;
  }
};

int main() {
  std::string num{"10"};
  int target{1};

  Solution ans = Solution();

  std::cout << ans.removeKdigits(num, target) << '\n';

  return 0;
}
