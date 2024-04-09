
#include <iostream>
#include <vector>

class Solution {
public:
  int timeRequiredToBuy(std::vector<int> tickets, int k) {
    int base{tickets[k] * static_cast<int>(tickets.size())};

    for (int i{0}; i < tickets.size(); ++i) {
      if (tickets[i] < tickets[k])
        base -= (tickets[k] - tickets[i]);
      if ((i > k) && tickets[i] >= tickets[k])
        --base;
    }

    return base;
  }
};

int main() {
  std::vector tickets{5, 2, 5, 2, 5};
  int target{2};

  Solution cur = Solution();

  int ans{cur.timeRequiredToBuy(tickets, target)};

  std::cout << ans << '\n';

  return 0;
}
