
#include "treeNode.h"

struct Test {
  TreeNode *root;
  int val;
  int depth;
};

Test test1() {
  Test result;

  TreeNode *a = new TreeNode(3);
  TreeNode *b = new TreeNode(1);
  TreeNode *c = new TreeNode(2, a, b);

  TreeNode *d = new TreeNode(5);
  TreeNode *e = new TreeNode(6, d, nullptr);

  TreeNode *f = new TreeNode(3, c, e);

  int value{1};
  int depth{2};

  result.root = f;
  result.val = value;
  result.depth = depth;

  return result;
}

class Solution {
public:
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    // lorem
    // ipsum
  }
};

int main() {
  Solution ans = Solution();

  Test input{test1()};

  ans.addOneRow(input.root, input.val, input.depth);

  return 0;
}
