
#include <iostream>

class Test {
public:
  struct TestCase {
    std::string str1;
    std::string str2;
    bool output;
  };

  TestCase testA() { return {"abc", "ad", true}; }

  TestCase testB() { return {"zc", "ad", true}; }

  TestCase testC() { return {"ab", "d", false}; }
};

class Solution {
public:
  bool canMakeSubsequence(std::string str1, std::string str2) {
    const int size1 = str1.size();
    const int size2 = str2.size();

    // str1 cannot be smaller than str2 in order to be true
    if (size1 < size2)
      return false;

    // create a separate string of str1 that has all incremented
    std::string inc{str1};
    for (int i{0}; i < size1; i++) {
      inc[i] = char(inc[i] + 1);
      // cyclical property
      if (inc[i] == '{')
        inc[i] = 'a';
    }

    // increment through and compare str2 to str1/inc to find matches
    int ptr1{0}, ptr2{0};
    for (int i{0}; i < size1; i++) {
      if (str2[ptr2] == str1[ptr1] || str2[ptr2] == inc[ptr1]) {
        ++ptr2;
        if (ptr2 == size2)
          return true;
      }
      ++ptr1;

      // too many chars that do not line up thus impossible to be true
      if ((ptr1 - ptr2) > (size1 - size2))
        return false;
    }

    return false;
  }
};

class OnlineSolution {
public:
  bool canMakeSubsequence(std::string source, std::string target) {
    int targetIdx = 0;
    int targetLen = target.length();
    for (char currChar : source) {
      if (targetIdx < targetLen &&
          (target[targetIdx] - currChar + 26) % 26 <= 1) {
        targetIdx++;
      }
    }
    return targetIdx == targetLen;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  bool output{solCur.canMakeSubsequence(unit.str1, unit.str2)};

  std::cout << std::boolalpha;
  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
