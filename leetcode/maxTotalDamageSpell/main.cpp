
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> power;
    long long output;
  };

  TestCase testA() { return {{1, 1, 3, 4}, 6}; }
  TestCase testB() { return {{7, 1, 6, 6}, 13}; }
  TestCase testC() { return {{7, 1, 6, 3}, 10}; }
};

class Solution {
private:
  std::unordered_map<int, int> m_table{};
  long long m_maxSoFar{};
  int m_size{};

  long long findMax(long long total, std::vector<int> &power, int pos) {
    long long curMax{};
    long long temp{};
    for (int i{pos}; i < m_size; ++i) {
      temp = total;
      if (power[i] > (power[pos] + 2)) {
        temp = findMax((total + m_table[power[i]]), power, i);
      }
      curMax = std::max(curMax, temp);
    }

    return curMax;
  }

public:
  long long maximumTotalDamage(std::vector<int> &power) {
    // compile to only unique values and total same values
    std::set<int> temp{power.begin(), power.end()};
    for (int i : power) {
      m_table[i] += i;
    }
    power.assign(temp.begin(), temp.end());
    m_size = power.size();

    long long total{};
    for (int head{0}; head < m_size; ++head) {
      total = m_table[power[head]];
      m_maxSoFar = std::max(m_maxSoFar, findMax(total, power, head));
    }

    return m_maxSoFar;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  long long output{solCur.maximumTotalDamage(unit.power)};

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
