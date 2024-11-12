
#include <iostream>

class Test {
public:
  struct TestCase {
    std::vector<std::vector<int>> items;
    std::vector<int> queries;
    std::vector<int> output;
  };

  TestCase testA() {
    TestCase obj;
    obj.items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
    obj.queries = {1, 2, 3, 4, 5, 6};
    obj.output = {2, 4, 5, 5, 6, 6};
    return obj;
  }

  TestCase testB() {
    TestCase obj;
    obj.items = {{1, 2}, {1, 2}, {1, 3}, {1, 4}};
    obj.queries = {1};
    obj.output = {4};
    return obj;
  }

  TestCase testC() {
    TestCase obj;
    obj.items = {{10, 1000}};
    obj.queries = {5};
    obj.output = {0};
    return obj;
  }
};

class Solution {
public:
  std::vector<int> maximumBeauty(std::vector<std::vector<int>> &items,
                                 std::vector<int> &queries) {
    std::vector<int> out;
    return out;
  }
};

void printVector(std::vector<int> vec) {
  for (int i : vec) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  Test::TestCase unit{testCur.testA()};
  std::vector<int> output{solCur.maximumBeauty(unit.items, unit.queries)};

  if (output == unit.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: ";
    printVector(unit.output);
    std::cout << "Actual: ";
    printVector(output);
  }
  std::cout << std::endl;
}
