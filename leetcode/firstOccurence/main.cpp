
#include <iostream>
#include <queue>
#include <string>

class Solution {
private:
  int findInitial(char target, int start, std::string area) {
    for (int i{start}; i < area.size(); ++i) {
      if (area[i] == target) {
        return i;
      }
    }

    return -1;
  }

public:
  // FIX:
  int strStr(std::string haystack, std::string needle) {
    int lenNeedle{static_cast<int>(needle.size())};
    int stackPtr{0};
    int needlePtr{0};
    std::queue<int> initialOccurence;
    int found{-1};

    // get first occurence of first letter
    stackPtr = findInitial(needle[0], stackPtr, haystack);
    found = stackPtr;

    // iterate attempting to match letters, if same as initial track it
    while (stackPtr < haystack.size()) {
      if (haystack[stackPtr] == needle[0] && stackPtr != found)
        initialOccurence.push(stackPtr);

      if (haystack[stackPtr] == needle[needlePtr]) {
        if (needlePtr == needle.size() - 1)
          return found;

        ++needlePtr;
        ++stackPtr;
        continue;
      } else {
        // reset ptrs
        needlePtr = 0;
        found = -1;

        // use next occurence of needle initial
        if (initialOccurence.size() == 0) {
          stackPtr = findInitial(needle[0], stackPtr, haystack);
          found = stackPtr;
        } else {
          stackPtr = initialOccurence.front();
          found = stackPtr;
          initialOccurence.pop();
        }
      }
    }

    return found;
  }
};

// Test cases
struct tests {
  std::string h;
  std::string n;
  int output;
};

tests testA() {
  tests obj;
  obj.h = "sadbutsad";
  obj.n = "sad";
  obj.output = 0;

  return obj;
}

tests testB() {
  tests obj;
  obj.h = "leetcode";
  obj.n = "leeto";
  obj.output = -1;

  return obj;
}

int main() {
  // set up
  Solution cur = Solution();
  tests test;
  int output;

  std::cout << "Test 1" << '\n';
  test = testA();
  output = cur.strStr(test.h, test.n);
  std::cout << "Output: " << output << '\n';
  if (output == test.output)
    std::cout << "Success!" << '\n' << std::endl;
  else
    std::cout << "Fail!" << '\n' << std::endl;

  std::cout << "Test 2" << '\n';
  test = testB();
  output = cur.strStr(test.h, test.n);
  std::cout << "Output: " << output << '\n';
  if (output == test.output)
    std::cout << "Success!" << '\n' << std::endl;
  else
    std::cout << "Fail!" << '\n' << std::endl;

  return 0;
}
