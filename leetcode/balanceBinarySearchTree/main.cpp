
#include "treeNode.h"
#include <iostream>
#include <vector>

class Test {
public:
  struct TestCase {
    TreeNode *root;
    TreeNode *expected;
  };

  TestCase testA() {}
  std::vector<TestCase> all() { return {}; };
};

class Solution {
private:
  std::vector<int> m_nums{};

  void dfs(TreeNode *root, std::vector<int> &nums) {
    if (root == nullptr)
      return;

    dfs(root->left, nums);
    nums.push_back(root->val);
    dfs(root->right, nums);
  }

  void addNode(TreeNode *parent, int newChild) {
    TreeNode *temp = new TreeNode;
    temp->val = newChild;

    if (newChild < parent->val) {
      if (parent->left == nullptr) {
        addNode(parent->left, newChild);
        return;
      } else {
        parent->left = temp;
      }
    } else if (newChild > parent->val) {
      if (parent->right == nullptr) {
        addNode(parent->right, newChild);
        return;
      } else {
        parent->right = temp;
      }
    }
  }

  void createTree(int low, int high, TreeNode *parent) {
    if ((high - low) < 2) {
      for (int i{low}; i <= high; ++i) {
        addNode(parent, m_nums[i]);
      }
    } else {
    }
  }

public:
  TreeNode *balanceBST(TreeNode *root) {
    // sort tree into sorted vector
    dfs(root, m_nums);

    // convert vector into tree
    // setup
    TreeNode *newTree = new TreeNode;
    createTree(0, (m_nums.size() - 1), newTree);

    return newTree;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    TreeNode result = sol.balancedBST(TreeNode * root);

    if (result == unit.expected) {
      std::cout << "✅ Test " << i + 1 << " passed!\n";
      ++passed;
    } else {
      std::cout << "❌ Test " << i + 1 << " failed!\n";
      std::cout << "   Expected: " << unit.expected << " | Got: " << result
                << "\n";
    }
  }
  std::cout << "\nSummary: " << passed << "/" << cases.size()
            << " tests passed.\n";

  return 0;
}
