
#include "treeNode.h"
#include <algorithm>
#include <stack>
#include <string>

// sample test
TreeNode *test() {
  TreeNode *a = new TreeNode(3);
  TreeNode *b = new TreeNode(4);
  TreeNode *c = new TreeNode(1, a, b);

  TreeNode *d = new TreeNode(3);
  TreeNode *e = new TreeNode(4);
  TreeNode *f = new TreeNode(2, d, e);

  TreeNode *g = new TreeNode(0, c, f);

  return g;
}

class Solution {
public:
  void dfs(TreeNode *root, std::string currStr) {
    if (root != NULL) {
      // action
      dfs(root->left, currStr);
      dfs(root->right, currStr);
    }

    return;
  }

  std::string smallestFromLeaf(TreeNode *root) {
    std::stack<TreeNode *> treeStack{};
    std::string minString{};
    std::string tempString{};

    // initial push
    treeStack.push(root);

    // dfs
    while (!treeStack.empty()) {
      // grab top node
      TreeNode *temp = treeStack.top();
      treeStack.pop();

      // if leaf node
      if (temp->left == NULL && temp->right == NULL) {
        minString = (minString < tempString) ? minString : tempString;
      }

      // push into stack
      if (temp->left != NULL)
        treeStack.push(temp->left);
      if (temp->right != NULL)
        treeStack.push(temp->right);
    }

    return minString;
  }
};

int main() {
  Solution ans = Solution();

  return 0;
}
