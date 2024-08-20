
#include <iostream>
#include <vector>

class Solution {
public:
  bool lemonadeChange(std::vector<int> &bills) {
    const int cost{5};
    bool track{false};
    int change{0};

    // iterate through vector
    for (int i{0}; i < bills.size(); ++i) {
      /*
       * If exact change...
       * - Add 5 to dictionary
       *
       * If 10...
       * - Check if 5
       * - Remove 5 and add 10
       *
       * If 20...
       * - Attempt to return 10 + 5
       * - Else attempt to return 5 x 3
       */

      if (bills[i] == 5)
    }

    return track;
  }
};

int main() {
  // setup here
  std::vector<int> testA{5, 5, 5, 10, 20};
  std::vector<int> testB{5, 5, 10, 10, 20};

  Solution answer = Solution();

  std::cout << answer.lemonadeChange(testA) << '\n';
  std::cout << answer.lemonadeChange(testB) << '\n';

  return 0;
}
