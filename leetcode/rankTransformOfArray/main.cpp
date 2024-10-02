
#include <iostream>
#include <unordered_map>
#include <vector>

class Test {
private:
  void printArray(std::vector<int> arr) {
    for (int i : arr) {
      std::cout << i << ' ';
    }
    std::cout << '\n' << std::endl;
  }

public:
  void checker(std::vector<int> expected, std::vector<int> actual) {
    if (expected == actual) {
      std::cout << "[Success!]\n" << std::endl;
    } else {
      std::cout << "[Failed!]\n";
      std::cout << "Expected:\n";
      printArray(expected);
      std::cout << "Actual:\n";
      printArray(actual);
    }
  }
  struct Unit {
    std::vector<int> input;
    std::vector<int> output;
  };

  Unit testA() {
    Unit obj;
    obj.input = {40, 10, 20, 30};
    obj.output = {4, 1, 2, 3};

    return obj;
  }

  Unit testB() {
    Unit obj;
    obj.input = {100, 100, 100};
    obj.output = {1, 1, 1};

    return obj;
  }

  Unit testC() {
    Unit obj;
    obj.input = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    obj.output = {5, 3, 4, 2, 8, 6, 7, 1, 3};

    return obj;
  }
};

class Solution {
public:
  std::vector<int> arrayRankTransform(std::vector<int> &arr) {
    std::vector<int> sorted{arr};
    std::sort(sorted.begin(), sorted.end());

    int counter{1};
    std::unordered_map<int, int> pos;

    // adding to map
    // {num : pos}
    for (int num : sorted) {
      if (pos.find(num) == pos.end()) {
        pos[num] = counter;
        ++counter;
      }
    }

    // loop over original and append pos to vector
    std::vector<int> output;
    for (int num : arr) {
      output.push_back(pos[num]);
    }

    return output;
  }
};

int main() {
  Test testCur = Test();
  Solution solCur = Solution();

  Test::Unit testCase{testCur.testC()};
  std::vector<int> output{solCur.arrayRankTransform(testCase.input)};
  testCur.checker(testCase.output, output);
}
