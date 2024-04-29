
#include <bitset>
#include <iostream>
#include <vector>

class Solution {
public:
  int minOperations(std::vector<int> &nums, int k) {
    // calculate XOR of all values
    int endXor{0};
    for (int num : nums)
      endXor = endXor xor num;

    int counter{0};
    std::bitset numBit{std::bitset<24>(endXor)};
    std::bitset kBit{std::bitset<24>(k)};

    // compare xor's
    for (int bit{0}; bit < numBit.size(); ++bit) {
      if (numBit[bit] != kBit[bit])
        ++counter;
    }

    return counter;
  }
};

int main() {
  std::vector<int> inputV{1, 2, 3, 4};
  int inputK{1};

  Solution answer = Solution();

  std::cout << answer.minOperations(inputV, inputK) << '\n';
}
