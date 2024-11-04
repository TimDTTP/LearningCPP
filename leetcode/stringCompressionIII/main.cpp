
#include <iostream>
#include <string>

class Test {
public:
  struct TestCase {
    std::string word;
    std::string output;
  };

  TestCase testA() {
    TestCase obj{"abcde", "1a1b1c1d1e"};
    return obj;
  }

  TestCase testB() {
    TestCase obj{"aaaaaaaaaaaaaabb", "9a5a2b"};
    return obj;
  }

  TestCase testC() {
    TestCase obj{"aaaaaaaaay", "9a1y"};
    return obj;
  }
};

class Solution {
private:
  void appendStr(int count, char letter, std::string &comp) {
    comp += std::to_string(count);
    comp += letter;
  };

public:
  std::string compressedString(std::string word) {
    std::string comp;
    int ptrFirst{0};
    int counter{1};

    // iterate + add freq and char
    for (int ptrSecond{1}; ptrSecond < word.length(); ptrSecond++) {
      if (word[ptrFirst] == word[ptrSecond]) {
        counter++;
        if (counter == 10) {
          appendStr(counter - 1, word[ptrFirst], comp);
          counter = 1;
          ptrFirst = ptrSecond;
        }
      } else {
        appendStr(counter, word[ptrFirst], comp);
        counter = 1;
        ptrFirst = ptrSecond;
      }
    }

    // add last prefix
    appendStr(counter, word[ptrFirst], comp);

    return comp;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testC()};
  std::string output{solCur.compressedString(unit.word)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << unit.output << '\n';
    std::cout << "Actual: " << output << '\n';
  }
  std::cout << std::endl;
}
