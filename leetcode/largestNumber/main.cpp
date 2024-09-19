
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

class TestingOnly {
public:
  struct TestCase {
    std::vector<int> input;
    std::string output;
  };

  TestCase testA() {
    TestCase obj;
    obj.input = {10, 2};
    obj.output = "210";

    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.input = {3, 30, 34, 5, 9};
    obj.output = "9534330";

    return obj;
  }

  TestCase testC() {
    TestCase obj;
    obj.input = {111311, 1113};
    obj.output = "1113111311";

    return obj;
  }

  TestCase testD() {
    TestCase obj;
    obj.input = {0, 0};
    obj.output = "0";

    return obj;
  }

  TestCase testE() {
    TestCase obj;
    obj.input = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    obj.output = "0";

    return obj;
  }
};

class Solution {
private:
  bool static cmp(std::string first, std::string second) {
    return (first + second) > (second + first);
  }

public:
  std::string largestNumber(std::vector<int> &nums) {
    std::string out{""};
    std::vector<std::string> numStr;

    for (int num : nums)
      numStr.push_back(std::to_string(num));

    std::sort(numStr.begin(), numStr.end(), cmp);

    // if greatest value == 0 return 0
    if (numStr[0] == "0")
      return "0";

    for (std::string i : numStr) {
      out += i;
    }

    return out;
  }
};

int main() {
  TestingOnly testCur = TestingOnly();
  Solution solCur = Solution();

  TestingOnly::TestCase test{testCur.testE()};
  std::string output{solCur.largestNumber(test.input)};

  if (output == test.output) {
    std::cout << "Success!\n";
  } else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << test.output << '\n';
    std::cout << "Actual: " << output << '\n' << std::endl;
  }

  return 0;
}
