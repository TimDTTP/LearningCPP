
#include <iostream>
#include <string>

struct TestCase {
  std::string haystack;
  std::string needle;
};

TestCase test1() {
  TestCase obj;
  obj.haystack = "sadbutsad";
  obj.needle = "sad";

  return obj;
}

class Solution {
  int strStr(std::string haystack, std::string needle) {}
};

int main() { return 0; }
