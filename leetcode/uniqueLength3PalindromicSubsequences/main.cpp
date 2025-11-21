
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Test {
public:
  struct TestCase {
    std::string s;
    int expected;
  };

  TestCase testA() { return {"aabca", 3}; }
  TestCase testB() { return {"adc", 0}; }
  TestCase testC() { return {"bbcbaba", 4}; }
  std::vector<TestCase> all() { return {testA(), testB(), testC()}; };
};

class Solution {
public:
  int countPalindromicSubsequence(std::string s) {
    // string to vector
    std::vector<char> chars{};
    for (char c : s) {
      chars.push_back(c);
    }

    // map first and last of each char
    std::unordered_map<char, std::pair<int, int>> table{};
    for (int i{0}; i < chars.size(); ++i) {
      if (!table.contains(chars[i])) {
        table[chars[i]].first = i;
        table[chars[i]].second = -1;
      } else {
        table[chars[i]].second = i;
      }
    }

    // count unique
    int count{0};
    for (const auto [key, value] : table) {
      if (value.second == -1)
        continue;
      std::unordered_set<char> temp{chars.begin() + value.first + 1,
                                    chars.begin() + value.second};
      count += temp.size();
    }

    return count;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    int result = sol.countPalindromicSubsequence(unit.s);

    if (result == unit.expected) {
      std::cout << "✅ Test " << i + 1 << " passed!\n";
      ++passed;
    } else {
      std::cout << "❌ Test " << i + 1 << " failed!\n";
      std::cout << "   Expected: " << unit.expected << " | Got: " << result
                << "\n";
    }
  }
  std::cout << "\nSummary: " << passed << "/" << cases.size()
            << " tests passed.\n";

  return 0;
}
