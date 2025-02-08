
#include <iostream>

class Test {
public:
  struct TestCase {
    std::pair<std::vector<std::string>, std::vector<std::vector<int>>> input;
    std::vector<int> output;
  };

  TestCase testA() {
    TestCase obj;
    obj.input = {
        {"NumberContainers", "find", "change", "change", "change", "change",
         "find", "change", "find"},
        {{0}, {10}, {2, 10}, {1, 10}, {3, 10}, {5, 10}, {10}, {1, 20}, {10}}};
    obj.output = {0, -1, 0, 0, 0, 0, 1, 0, 2};
    return obj;
  }

  void printVec(std::vector<int> input) {
    for (int val : input) {
      std::cout << val << ' ';
    }
    std::cout << '\n' << std::endl;
  }
};

class NumberContainers {
public:
  NumberContainers() {
    // instantiate
    // here
  }

  void change(int index, int number) {
    // change
    // replace
  }

  int find(int number) {
    int out;
    return out;
  }
};

int main() {
  Test testCur{Test()};
  NumberContainers solCur{NumberContainers()};

  Test::TestCase unit{testCur.testA()};
  std::vector<int> output{};

  for (std::vector<int> call : unit.input.second) {
    switch (call.size()) {
    case 0:
      output.push_back(0);
      break;
    case 1:
      output.push_back(solCur.find(call[0]));
      break;
    case2:
      output.push_back(0);
      break;
    }
  }

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: ";
    testCur.printVec(unit.output);
    std::cout << "Actual: ";
    testCur.printVec(output);
  }
  std::cout << std::endl;

  return 0;
}
