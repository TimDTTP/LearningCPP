
#include <iostream>
#include <string>

struct TestCase {
  std::string version1;
  std::string version2;
  int expected;
};

TestCase test1() {
  TestCase obj;
  obj.version1 = "1.01";
  obj.version2 = "1.001";
  obj.expected = 0;

  return obj;
}

TestCase test2() {
  TestCase obj;
  obj.version1 = "1.0";
  obj.version2 = "1.0.0";
  obj.expected = 0;

  return obj;
}

TestCase test3() {
  TestCase obj;
  obj.version1 = "0.1";
  obj.version2 = "1.1";
  obj.expected = -1;

  return obj;
}

TestCase test4() {
  TestCase obj;
  obj.version1 = "1.0.1";
  obj.version2 = "1";
  obj.expected = 1;

  return obj;
}

TestCase test5() {
  TestCase obj;
  obj.version1 =
      "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0."
      "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
      "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
      "0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
      "0.0.0.0.0.0.0.0.0.0.0.000000";
  obj.version2 =
      "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
      "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
      "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
      "0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
      "0.0.0.0.0.0.0.0.0.0.0.0.000000";
  obj.expected = 1;

  return obj;
}

class Solution {
public:
  int compareVersion(std::string version1, std::string version2) {
    size_t v1{version1.size()};
    size_t v2{version2.size()};
    int ptr1{0};
    int ptr2{0};

    while (ptr1 < v1 || ptr2 < v2) {
      int val1{0};
      int val2{0};

      // value up to decimal
      if (ptr1 < v1) {
        while ((version1[ptr1] != '.') && (ptr1 < v1)) {
          val1 = val1 * 10 + (version1[ptr1] - '0');
          ++ptr1;
        }
      }
      if (ptr2 < v2) {
        while ((version2[ptr2] != '.') && (ptr2 < v2)) {
          val2 = val2 * 10 + (version2[ptr2] - '0');
          ++ptr2;
        }
      }

      // compare
      if (val1 < val2)
        return -1;
      else if (val1 > val2)
        return 1;

      // skip decimal
      ++ptr1;
      ++ptr2;
    }

    return 0;
  }
};

int main() {
  TestCase input{test5()};
  Solution answer = Solution();

  int res{answer.compareVersion(input.version1, input.version2)};

  std::cout << "Expected: " << '\n' << input.expected << "\n\n";
  std::cout << "Actual: " << '\n' << res << "\n\n";

  return 0;
}
