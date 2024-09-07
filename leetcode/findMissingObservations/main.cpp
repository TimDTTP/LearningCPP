
#include <iostream>
#include <vector>

struct TestCase {
  std::vector<int> rolls;
  int mean;
  int n;
};

TestCase testA() {
  TestCase obj;
  obj.rolls = {3, 2, 4, 3};
  obj.mean = 4;
  obj.n = 2;

  return obj;
}

TestCase testB() {
  TestCase obj;
  obj.rolls = {1, 5, 6};
  obj.mean = 3;
  obj.n = 4;

  return obj;
}

TestCase testC() {
  TestCase obj;
  obj.rolls = {1, 2, 3, 4};
  obj.mean = 6;
  obj.n = 4;

  return obj;
}

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

    sum = sumMissing % n;
    for (int i{0}; i < sum; ++i) {
      ++possibleVals[i];
    }

    return possibleVals;
  }
};

int main() {
  Solution cursor = Solution();
  TestCase test{testC()};
  std::vector<int> output{cursor.missingRolls(test.rolls, test.mean, test.n)};
  for (int i : output)
    std::cout << i << ' ';
  std::cout << '\n';

  return 0;
}
