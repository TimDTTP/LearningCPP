
#include <bitset>
#include <iostream>
#include <string>

class Solution {
public:
  int minBitFlips(int start, int goal) {
    std::bitset<32> bitStart{static_cast<unsigned>(start)};
    std::bitset<32> bitGoal{static_cast<unsigned>(goal)};

    // compare start vs goal
    int counter{0};
    for (int i{0}; i < 32; ++i) {
      if (bitStart[i] != bitGoal[i])
        ++counter;
    }

    return counter;
  }
};

int main() {
  std::cout << "Start\n" << std::endl;

  Solution cursor = Solution();
  int output = cursor.minBitFlips(3, 4);
  std::cout << output << '\n';

  return 0;
}
