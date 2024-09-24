
#include <iostream>
#include <vector>

class Test {
public:
  struct Unit {
    std::vector<int> input1;
    std::vector<int> input2;
    int output;
  };

  Unit testA() {
    Unit obj;
    obj.input1 = {1, 10, 100};
    obj.input2 = {1000};
    obj.output = 3;

    return obj;
  }

  Unit testB() {
    Unit obj;
    obj.input1 = {1, 2, 3};
    obj.input2 = {4, 4, 4};
    obj.output = 0;

    return obj;
  }
};

class Solution {
private:
  struct Node {
    int val;
    std::vector<Node *> subsequent;
  };

  Node *initTree(std::vector<int> arr) {
    Node head;
    head.val = 0;

    for (int i : arr) {
      int temp{i};
      while (i > 0) {
        temp = i % 10;
        i /= 10;

        // find if value exists
      }
    }
  }

public:
  int longestCommonPrefix(std::vector<int> &arr1, std::vector<int> &arr2) {
    int maxPrefix;
    // add values of arr2 to tree

    return maxPrefix;
  }
};

int main() {
  Test testCur = Test();
  Solution solCur = Solution();

  Test::Unit input{testCur.testA()};
  int output{solCur.longestCommonPrefix(input.input1, input.input2)};
  if (output == input.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << input.output << '\n';
    std::cout << "Actual: " << output << '\n' << std::endl;
  }

  return 0;
}
