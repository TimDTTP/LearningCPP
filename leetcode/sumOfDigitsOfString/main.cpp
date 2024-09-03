
#include <iostream>
#include <string>
#include <vector>

struct testCase {
  std::string s;
  int k;
  int output;
};

testCase testA() {
  testCase obj;
  obj.s = "iiii";
  obj.k = 1;
  obj.output = 36;

  return obj;
}

testCase testB() {
  testCase obj;
  obj.s = "leetcode";
  obj.k = 2;
  obj.output = 6;

  return obj;
}

class Solution {
public:
  int getLucky(std::string s, int k) {
    // convert letter and push into vector
    std::vector<int> vals{};
    int num{};
    for (char letter : s) {
      num = letter - 'a' + 1;

      if (num >= 10) {
        vals.push_back(num % 10);
        vals.push_back(num / 10);
      } else
        vals.push_back(num);
    }

    int sum{0};
    // total and split apart
    for (int i = 0; i < k; ++i) {
      // total
      sum = 0;
      for (int j : vals)
        sum += j;

      vals.clear();

      // split
      int temp{sum};
      while (temp > 0) {
        vals.push_back(temp % 10);
        temp /= 10;
      }
    }

    return sum;
  }
};

int main() {
  testCase test{testA()};

  Solution cursor = Solution();

  int yield{cursor.getLucky(test.s, test.k)};
  if (yield == test.output)
    std::cout << "Success!\n" << std::endl;
  else {
    std::cout << "Fail!\n";
    std::cout << "Expected: " << test.output << '\n';
    std::cout << "Actual: " << yield << '\n';
  }
}
