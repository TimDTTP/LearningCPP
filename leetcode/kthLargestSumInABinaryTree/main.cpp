
#include "node.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Test {
public:
  struct TestCase {
    TreeNode *tree;
    int k;
    long long result;
  };

  TestCase testA() {
    TestCase obj;
    TreeNode *root{new TreeNode(5)};
    root->left = new TreeNode(8);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(6);

    obj.tree = root;
    obj.k = 2;
    obj.result = 13;

    return obj;
  }
};

class Solution {
public:
  long long kthLargestLevelSum(TreeNode *root, int k) {
    std::vector<long long> sums{};
    std::queue<TreeNode *> parent{};
    std::queue<TreeNode *> children{};

    parent.push(root);
    long long tempSum{0};

    // perform level order traversal
    while (!parent.empty()) {
      tempSum += parent.front()->val;
      if (parent.front()->left)
        children.push(parent.front()->left);
      if (parent.front()->right)
        children.push(parent.front()->right);
      parent.pop();

      // if end of level
      if (parent.empty()) {
        sums.push_back(tempSum);
        tempSum = 0;
        parent = children;
        while (!children.empty())
          children.pop();
      }
    }

    // if k > sums.size() return -1
    if (k > sums.size())
      return -1;

    // sort descending order
    std::sort(sums.begin(), sums.end(), std::greater());

    // sub 1 because of 1 index
    return sums[k - 1];
  }
};

int main() {
  Solution solCur{Solution()};
  Test testCur{Test()};

  Test::TestCase input{testCur.testA()};
  long long output{solCur.kthLargestLevelSum(input.tree, input.k)};

  if (output == input.result) {
    std::cout << "Success!\n" << std::endl;
  } else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << input.result << '\n';
    std::cout << "Actual: " << output << '\n' << std::endl;
  }

  return 0;
}
