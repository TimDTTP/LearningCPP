
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  bool lemonadeChange(std::vector<int> &bills) {
    const int cost{5};
    bool track{true};
    int change{0};
    std::unordered_map<int, int> reserve = {
        {5, 0},
        {10, 0},
    };

    // iterate through vector
    for (int i{0}; i < bills.size(); ++i) {
      // Given $5 bill
      if (bills[i] == 5)
        ++reserve[5];

      // Given $10 bill
      else if (bills[i] == 10) {
        if (reserve[5] > 0) {
          --reserve[5];
          ++reserve[10];
        } else {
          track = false;
          break;
        }
      }

      // Given $20 bill
      else {
        if (reserve[10] >= 1 && reserve[5] >= 1) {
          --reserve[10];
          --reserve[5];
        } else if (reserve[5] >= 3) {
          reserve[5] -= 3;
        } else {
          track = false;
          break;
        }
      }
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
