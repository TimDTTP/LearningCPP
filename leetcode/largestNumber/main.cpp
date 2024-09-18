
#include <algorithm>
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
    obj.output = "9534303";

    return obj;
  }
};

class Solution {
private:
  bool static cmp(std::pair<std::string, int> first,
                  std::pair<std::string, int> second) {
    if (first.second > second.second)
      return true;
    else
      return false;
  };

public:
  std::string largestNumber(std::vector<int> &nums) {
    std::string out{""};
    std::vector<std::pair<std::string, int>> table;

    // add value : priority to table
    for (int num : nums) {
      std::pair<std::string, int> obj;
      obj.first = std::to_string(num);
      obj.second = num * (pow(10, (9 - obj.first.size() - 1)));
      table.push_back(obj);
    }

    // sort table by priority
    std::sort(table.begin(), table.end(), cmp);

    // iterate and append to string
    for (std::pair<std::string, int> vals : table) {
      out += vals.first;
    }

    return out;
  }
};

int main() {
  TestingOnly testCur = TestingOnly();
  Solution solCur = Solution();

  TestingOnly::TestCase test{testCur.testA()};
  std::string output{solCur.largestNumber(test.input)};

  if (output == test.output) {
    std::cout << "Success!\n";
  } else {
    std::cout << "Failed!\n";
    std::cout << output << '\n' << std::endl;
  }

  return 0;
}
