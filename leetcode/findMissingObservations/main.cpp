
#include <vector>

class Solution {
public:
  std::vector<int> missingRolls(std::vector<int> &rolls, int mean, int n) {
    int divisor{static_cast<int>(rolls.size() + n)};

    int sum{};
    for (int const i : rolls)
      sum += i;
    int sumMissing{mean * divisor - sum};

    // base case
    if (sumMissing < (n * 1) || sumMissing > (n * 6)) {
      return {};
    }

    // find a possible solution of missing values
    std::vector<int> possibleVals;
    possibleVals.reserve(n);

    for (int i{0}; i < n; ++i)
      possibleVals.push_back(sumMissing / n);

    sum = (sumMissing / n) * n;
    for (int i{0}; i < sum; ++i) {
      ++possibleVals[i];
    }

    return possibleVals;
  }
};

int main() { return 0; }
