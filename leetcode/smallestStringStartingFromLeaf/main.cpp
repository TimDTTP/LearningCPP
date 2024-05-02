
#include "treeNode.h"
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

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
  std::string dfs(TreeNode *root, const std::array<char, 26> &alpha,
                  std::string &minStr, std::string temp) {
    if (root != NULL) {
      // add char to temp string front
      temp = alpha[root->val] + temp;

      if (!root->left && !root->right) {
        if (minStr.empty())
          minStr = temp;

        // compare
        minStr = (minStr > temp) ? temp : minStr;
      }

      // recursively call left branch
      dfs(root->left, alpha, minStr, temp);

      // recursively call right branch
      dfs(root->right, alpha, minStr, temp);

      // pop last char added
      temp.erase(temp.begin());
    }

    return minStr;
  }

  std::string smallestFromLeaf(TreeNode *root) {
    std::array<char, 26> const alpha{
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    std::string minStr{};
    std::string temp{};

    return dfs(root, alpha, minStr, temp);
  }
};

int main() {
  Solution ans = Solution();

  TreeNode *node = test();

  std::cout << ans.smallestFromLeaf(node) << '\n';

  return 0;
}
