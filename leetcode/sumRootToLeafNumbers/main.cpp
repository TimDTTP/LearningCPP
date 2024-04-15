
#include "treeNode.h"
#include <iostream>
#include <queue>
#include <vector>

// utils to help solve the problem
class Util {
private:
  int height(TreeNode *node) {
    if (node == NULL) {
      return 0;
    }

    else {
      // find depth of each subtree
      int lDepth{height(node->left)};
      int rDepth{height(node->right)};

      // use larger one
      if (lDepth > rDepth)
        return (lDepth + 1);
      if (lDepth < rDepth)
        return (rDepth + 1);
    }

    return 0;
  }

  void printGivenLevel(TreeNode *root, int level) {
    if (root == NULL)
      return;
    if (level == 1)
      std::cout << " " << root->val;
    else if (level > 1) {
      // recursive call
      printGivenLevel(root->left, level - 1);
      printGivenLevel(root->right, level - 1);
    }
  }

public:
  // vector into binary tree
  TreeNode *root(std::vector<int> arr) {
    TreeNode *node = NULL;

    std::queue<TreeNode *> emptyNode{};

    for (int i : arr) {
      TreeNode *temp = new TreeNode(i);
      if (node == NULL) {
        node = temp;
        emptyNode.push(node);
        continue;
      }

      // if both are full
      if (emptyNode.front()->left && emptyNode.front()->right) {
        emptyNode.pop();
      }

      // if left node is empty
      if (!emptyNode.front()->left) {
        emptyNode.front()->left = temp;
        emptyNode.push(emptyNode.front()->left);
        continue;
      }

      // if right node is empty
      else if (!emptyNode.front()->right) {
        emptyNode.front()->right = temp;
        emptyNode.push(emptyNode.front()->right);
        continue;
      }
    }

    return node;
  }

  // print tree
  void printLevelOrder(TreeNode *root) {
    int h{height(root)};
    std::cout << "height: " << h << '\n';
    for (int i{1}; i <= h; i++) {
      printGivenLevel(root, i);
      std::cout << "\n";
    }
  }

  // test
};

class Solution {
public:
  int sumNumbers(TreeNode *root) { return 1; }
};

int main() {
  std::vector<std::vector<int>> tests{
      {1, 2, 3},
      {4, 9, 0, 5, 1},
  };

  Util cursor = Util();

  TreeNode *node{};

  node = cursor.root(tests[0]);

  cursor.printLevelOrder(node);

  return 0;
}
