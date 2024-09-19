
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
public:
  std::vector<int> diffWaysToCompute(std::string expression) {
    std::vector<int> solution;

    return solution;
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

  return 0;
}
