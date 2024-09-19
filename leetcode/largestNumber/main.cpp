
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
  bool static cmp(int first, int second) {
    std::string firstPriority{std::to_string(first) + std::to_string(second)};
    std::string secondPriority{std::to_string(second) + std::to_string(first)};

    bool greater{
        std::stoul(firstPriority) > std::stoul(secondPriority) ? true : false};

    return greater;
  }

public:
  std::string largestNumber(std::vector<int> &nums) {
    std::string out{""};

    std::sort(nums.begin(), nums.end(), cmp);
    std::cout << "here" << '\n';

    // trim leading zeros
    while (std::find(nums.begin(), nums.end(), 0) == nums.begin() &&
           nums.size() > 1) {
      nums.erase(nums.begin());
    }

    for (int num : nums) {
      out += std::to_string(num);
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
