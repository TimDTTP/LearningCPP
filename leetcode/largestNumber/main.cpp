
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
    obj.input = {10, 2};
    obj.output = "210";

    return obj;
  }
};

class Solution {
private:
  bool static cmp(std::vector<int> first, std::vector<int> second) {
    // if matched && next value is greater than initial value
    for (int index{0}; index < first.size(); ++index) {
      if (first[index] == -1) {
        return (second[index] > second[0]) ? false : true;
      } else if (second[index] == -1) {
        return (first[index] > first[0]) ? true : false;
      } else if (first[index] != second[index])
        return (first[index] > second[index] ? true : false);
    }

    return true;
  }

public:
  std::string largestNumber(std::vector<int> &nums) {
    std::string out{""};
    std::vector<std::vector<int>> table;
    table.reserve(nums.size());
    table[0].reserve(10);

    // fill table with -1
    for (int i{0}; i < nums.size(); ++i) {
      table.push_back({});
      for (int j{0}; j < 10; ++j) {
        table[i].push_back(-1);
      }
    }

    // add values to table
    std::string temp;
    for (int num{0}; num < nums.size(); ++num) {
      temp = std::to_string(nums[num]);
      for (int digit{0}; digit < temp.size(); ++digit) {
        table[num][digit] = temp[digit] - '0';
      }
    }

    // sort
    std::sort(table.begin(), table.end(), cmp);

    // append to string
    for (int row{0}; row < table.size(); ++row) {
      for (int col{0}; col < table[0].size(); ++col) {
        if (table[row][col] != -1)
          out += std::to_string(table[row][col]);
      }
    }

    return out;
  }
};

int main() {
  TestingOnly testCur = TestingOnly();
  Solution solCur = Solution();

  TestingOnly::TestCase test{testCur.testD()};
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
