
#include <format>
#include <iostream>
#include <numeric>
#include <vector>

class Test {
public:
  struct TestCase {
    int n;
    int delay;
    int forget;
    int output;
  };

  TestCase testA() { return {6, 2, 4, 5}; }

  TestCase testB() { return {4, 1, 3, 6}; }
};

class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    std::vector<std::pair<int, int>> buffer{{1, 1}};
    int modulo{1000000007};

    int count{0};
    for (int i{1}; i < n; i++) {

      for (int j{0}; j < buffer.size(); j++) {
        buffer[j].first++;
        if (buffer[j].first > delay && buffer[j].first <= forget) {
          count = ((count + buffer[j].second) % modulo);
        }

        if (buffer[j].first > forget) {
          buffer.erase(buffer.begin() + 0);
          j--;
        }
      }

      if (count > 0) {
        buffer.push_back({1, count});
      }

      // BUG:
      for (std::pair<int, int> dos : buffer) {
        std::cout << std::format("{{{}, {}}} ", dos.first, dos.second);
      }
      std::cout << std::endl;

      count = 0;
    }

    int total{std::accumulate(buffer.begin(), buffer.end(), 0,
                              [modulo](int x, std::pair<int, int> nums) {
                                return ((x + nums.second) % modulo);
                              })};

    return total;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testB()};
  int output{solCur.peopleAwareOfSecret(unit.n, unit.delay, unit.forget)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;

  return 0;
}
