
#include <iostream>
#include <string>
#include <vector>

class testUtils {
public:
  struct Case {
    std::string input;
    std::vector<int> output;
  };

  Case testA() {
    Case obj;
    obj.input = "2-1-1";
    obj.output = {0, 2};

    return obj;
  }

  Case testB() {
    Case obj;
    obj.input = "2*3-4*5";
    obj.output = {-34, -14, -10, -10, 10};

    return obj;
  }
};

std::vector<testUtils::Case> test() {
  testUtils cursor = testUtils();
  std::vector<testUtils::Case> obj;
  obj.push_back(cursor.testA());
  obj.push_back(cursor.testB());

  return obj;
}

class Solution {
private:
  int intManipulation(int first, int second, char op) {
    int returnVal;
    switch (op) {
    case '+':
      returnVal = first + second;
      break;
    case '-':
      returnVal = first - second;
      break;
    case '*':
      returnVal = first * second;
      break;
    }
    std::cout << first << ' ' << op << ' ' << second;
    std::cout << " = " << returnVal << '\n';
    return returnVal;
  }

  void combine(std::vector<int> nums, std::vector<char> operators,
               std::vector<int> &solutions) {
    std::vector<int> nextNums{nums};
    std::vector<char> nextOps{operators};

    // conditional to stop recursive call
    if (nums.size() == 1) {
      solutions.push_back(nums[0]);
      std::cout << "Adding: " << nums[0] << '\n';
      return;
    }

    // iterate through until second last num
    for (int val{0}; val < nextNums.size() - 1; ++val) {
      // combine current value with next value && delete
      nextNums[val] =
          intManipulation(nextNums[val], nextNums[val + 1], nextOps[val]);
      nextNums.erase(nextNums.begin() + (val + 1));
      nextOps.erase(nextOps.begin() + val);
      combine(nextNums, nextOps, solutions);
    }
  }

public:
  std::vector<int> diffWaysToCompute(std::string expression) {
    std::vector<int> solutions;

    // separate operator vs values
    std::vector<int> nums;
    std::vector<char> operators;

    std::string temp;
    for (char i : expression) {
      if (i >= 48 && i <= 57)
        temp += i;

      else {
        operators.push_back(i);
        nums.push_back(std::stoi(temp));
        temp = "";
      }
    }
    if (!temp.empty())
      nums.push_back(std::stoi(temp));

    // iterate through and combine
    combine(nums, operators, solutions);

    return solutions;
  }
};

int main() {
  std::vector<testUtils::Case> testCases{test()};
  Solution solCur = Solution();
  std::vector<int> output;

  // print vector<int>
  auto printVec = [](std::vector<int> vec) {
    for (int i : vec) {
      std::cout << i << ' ';
    }
  };

  int testNum{1};
  solCur.diffWaysToCompute(testCases[0].input);
  /*
  for (testUtils::Case cases : testCases) {
    std::cout << "Test #" << testNum << ' ';
    output = solCur.diffWaysToCompute(cases.input);
    if (output == cases.output)
      std::cout << "Success!\n" << std::endl;
    else {
      std::cout << "Failed!\n";
      std::cout << "Expected:\n";
      printVec(cases.output);
      std::cout << '\n';
      std::cout << "Actual:\n";
      printVec(output);
      std::cout << '\n' << std::endl;
    }
    ++testNum;
  }
  */

  return 0;
}
