
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
        {{}, {10}, {2, 10}, {1, 10}, {3, 10}, {5, 10}, {10}, {1, 20}, {10}}};
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
private:
  std::vector<int> nums{};

public:
  NumberContainers() {
    // store current values
  }

  void change(int index, int number) {
    // index out of range
    if (index > nums.size() - 1) {
      for (int i = nums.size(); i <= index; ++i) {
        nums.push_back(0);
      }
    }

    // index in range
    nums[index] = number;
  }

  int find(int number) {
    std::vector<int>::iterator location =
        std::find(nums.begin(), nums.end(), number);

    int result = (location == nums.end() ? -1 : location - nums.begin());

    return result;
  }

  void print() {
    for (int i : nums) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;
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
    case 2:
      output.push_back(0);
      break;
    }
  }

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected:\n";
    testCur.printVec(unit.output);
    std::cout << "Actual:\n";
    testCur.printVec(output);
  }
  std::cout << std::endl;

  return 0;
}
