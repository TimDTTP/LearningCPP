
#include "treeNode.h"
#include <iostream>

TreeNode *test1() {
  TreeNode *a = new TreeNode(3);
  TreeNode *b = new TreeNode(2);
  TreeNode *c = new TreeNode(1, a, b);

  return c;
}

TreeNode *test2() {
  TreeNode *a = new TreeNode(5);
  TreeNode *b = new TreeNode(1);
  TreeNode *c = new TreeNode(9, a, b);

  TreeNode *e = new TreeNode(0);

  TreeNode *g = new TreeNode(4, c, e);

  return g;
}

class Solution {
public:
  int dfs(TreeNode *root, int sum) {
    // edge case
    if (root == NULL)
      return 0;

    sum = sum * 10 + root->val;

    if (!root->left && !root->right)
      return sum;

    return dfs(root->left, sum) + dfs(root->right, sum);
  }

  int sumNumbers(TreeNode *root) {
    int sum{0};
    sum = dfs(root, sum);

    return sum;
  }
};

int main() {
  Solution answer = Solution();
  TreeNode *node{test2()};

  int ans{answer.sumNumbers(node)};

  std::cout << "Sum: " << ans << '\n';

  return 0;
}
