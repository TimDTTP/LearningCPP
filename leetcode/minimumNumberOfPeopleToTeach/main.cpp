
#include <bitset>
#include <climits>
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    int n;
    std::vector<std::vector<int>> languages;
    std::vector<std::vector<int>> friendships;
    int output;
  };

  TestCase testA() {
    TestCase obj;
    obj.n = 2;
    obj.languages = {{1}, {2}, {1, 2}};
    obj.friendships = {{1, 2}, {1, 3}, {2, 3}};
    obj.output = 1;
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.n = 3;
    obj.languages = {{2}, {1, 3}, {1, 2}, {3}};
    obj.friendships = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
    obj.output = 2;
    return obj;
  }
};

class Solution {
public:
  int minimumTeachings(int n, std::vector<std::vector<int>> &languages,
                       std::vector<std::vector<int>> &friendships) {
    int m = languages.size();

    // known languages for each person
    std::vector<std::bitset<501>> know(m);
    for (int i = 0; i < m; i++)
      for (int l : languages[i])
        know[i][l] = 1;

    // people need be taught
    std::bitset<501> need = 0;
    for (auto &f : friendships) {
      int a = f[0] - 1, b = f[1] - 1;
      if ((know[a] & know[b]).any())
        continue; // can talk
      need[a] = need[b] = 1;
    }

    // if no need
    if (need.count() == 0)
      return 0;

    int ans = INT_MAX;
    for (int lang = 1; lang <= n; lang++) { // languages for 1..n
      int cnt = 0;
      for (int i = 0; i < m; i++) {
        if (need[i] & !know[i][lang])
          cnt++;
      }
      ans = std::min(ans, cnt);
    }

    return ans;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  int output{solCur.minimumTeachings(unit.n, unit.languages, unit.friendships)};

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
