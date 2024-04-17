
#include "treeNode.h"
#include <iostream>

// Data type for test samples
struct Test {
  TreeNode *root;
  int val;
  int depth;
};

// Sample test input
Test test1() {
  Test result;

  TreeNode *a = new TreeNode(3);
  TreeNode *b = new TreeNode(1);
  TreeNode *c = new TreeNode(2, a, b);

  TreeNode *d = new TreeNode(5);
  TreeNode *e = new TreeNode(6, d, nullptr);

  TreeNode *f = new TreeNode(4, c, e);

  int value{1};
  int depth{2};

  result.root = f;
  result.val = value;
  result.depth = depth;

  return result;
}

// get height of tree
int height(TreeNode *root) {
  if (root == NULL)
    return 0;
  else {
    int lDepth{height(root->left)};
    int rDepth{height(root->right)};

    if (lDepth > rDepth)
      return lDepth + 1;
    else
      return rDepth + 1;
  }
}

// prints a level of a tree
void printLevel(TreeNode *root, int height) {
  if (root == NULL)
    return;

  if (height == 1)
    std::cout << ' ' << root->val;

  else if (height > 1) {
    printLevel(root->left, height - 1);
    printLevel(root->right, height - 1);
  }
}

// print binary tree by BFS
void printTree(TreeNode *root) {
  int h{height(root)};

  for (int i{1}; i <= h; ++i) {
    printLevel(root, i);
    std::cout << '\n';
  }
}

// ACTUAL SOLUTION
class Solution {
public:
  // get to appropriate depth
  void add(TreeNode *root, int val, int depth) {
    if (root == NULL)
      return;

    if (depth == 1) {
      // INSERT HERE
      TreeNode *holdL = root->left;
      TreeNode *holdR = root->right;

      TreeNode *tempL = new TreeNode(val, holdL, nullptr);
      TreeNode *tempR = new TreeNode(val, nullptr, holdR);

      root->left = tempL;
      root->right = tempR;
    }

    else if (depth > 1) {
      add(root->left, val, depth - 1);
      add(root->right, val, depth - 1);
    }
  }

  // main solution code
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    // edge case; depth == 1
    if (depth == 1) {
      TreeNode *temp = new TreeNode(val);
      temp->left = root;
      return temp;
    }

    // get to depth - 1, to edit child nodes
    add(root, val, depth - 1);

    return root;
  }
};

int main() {
  Solution ans = Solution();

  // Input sample for solution code
  Test input{test1()};

  printTree(ans.addOneRow(input.root, input.val, input.depth));

  return 0;
}
