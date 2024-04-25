
#include <iostream>
#include <vector>

// test cases
struct TestCase {
  int n;
  int correct;
};

TestCase test1() {
  TestCase obj;
  obj.n = 3;
  obj.correct = 4;

  return obj;
}

TestCase test2() {
  TestCase obj;
  obj.n = 25;
  obj.correct = 1389537;

  return obj;
}

// Solution code
class Solution {
public:
  int tribonacci(int n) {
    std::vector<int> sequence{0, 1, 1};

    // edge cases
    if (n == 0)
      return 0;
    if (n == 2 || n == 1)
      return 1;

    for (int i{3}; i <= n; ++i) {
      int sum{sequence[i - 1] + sequence[i - 2] + sequence[i - 3]};
      sequence.push_back(sum);
    }

    return sequence.back();
  }
};

int main() {
  TestCase input{test1()};

  Solution ans = Solution();

  std::cout << ans.tribonacci(input.n) << '\n';

  return 0;
}
