
#include "treeNode.h"
#include <iostream>
#include <queue>
#include <vector>

class Test {
private:
  TreeNode *vecToTree(std::vector<int> v) {
    TreeNode *root = nullptr;
    std::queue<TreeNode *> leaf{};

    for (int num : v) {
      TreeNode *temp{new TreeNode(num)};

      if (root == nullptr) {
        root = temp;
        leaf.push(root->left);
        leaf.push(root->right);
        continue;
      }

      if (temp->val == -1)
        leaf.pop();
      else {
        leaf.front() = temp;
        leaf.push(temp->left);
        leaf.push(temp->right);
        leaf.pop();
      }
    }

    return root;
  }

public:
  struct TestCase {
    TreeNode *input;
    std::vector<int> output;
  };

  // print as a string for ease of display
  void printTree(TreeNode *root) {}

  TestCase testA() {
    std::vector<int> in{5, 4, 9, 1, 10, -1, 7};
    std::vector<int> out{0, 0, 0, 7, 7, -1, 11};

    TestCase obj{vecToTree(in), out};

    return obj;
  }

  TestCase testB() {
    std::vector<int> in{3, 1, 2};
    std::vector<int> out{0, 0, 0};

    TestCase obj{vecToTree(in), out};

    return obj;
  }
};

class Solution {
public:
  TreeNode *replaceValueInTree(TreeNode *root) {
    std::queue<TreeNode *> order{};
    int currSize{};
    int currSum{};

    order.push(root);
    root->val = 0;

    while (!order.empty()) {
      currSize = order.size();
      currSum = 0;
      // sum all cousins
      for (int i{0}; i < currSize; i++) {
        if (order.front()->left)
          currSum += order.front()->left->val;
        if (order.front()->right)
          currSum += order.front()->right->val;
        order.push(order.front());
        order.pop();
      }

      // assign value to siblings and push children
      for (int i{0}; i < currSize; i++) {
        int nodeSum{0};
        if (order.front()->left)
          nodeSum += order.front()->left->val;
        if (order.front()->right)
          nodeSum += order.front()->right->val;

        if (order.front()->left) {
          order.front()->left->val = currSum - nodeSum;
          order.push(order.front()->left);
        }
        if (order.front()->right) {
          order.front()->right->val = currSum - nodeSum;
          order.push(order.front()->right);
        }

        order.pop();
      }
    }

    return root;
  }
};

int main() {
  Test testCur{Test()};
  Solution solCur{Solution()};

  TreeNode *input{testCur.testA().input};

  return 0;
}
