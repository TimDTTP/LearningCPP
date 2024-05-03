
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

class Solution {
public:
  int compareVersion(std::string version1, std::string version2) { return 0; }
};

int main() {
  TestCase input{test1()};
  Solution answer = Solution();
}
