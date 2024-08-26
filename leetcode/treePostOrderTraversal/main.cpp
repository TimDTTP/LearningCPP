
#include "treeNode.h"
#include <iostream>
#include <queue>

class Test {
private:
  // FIX: root is not const and changing per iteration
  // convert vector to tree
  Node *tree(std::vector<const int> values) {
    Node *root = nullptr;
    std::queue<Node *> order;
    std::vector<Node *> tempChildren;

    // if empty
    if (values.size() == 0)
      return root;

    // loop and add till -1
    for (int nums{0}; nums < values.size(); ++nums) {
      // Init value node
      Node temp{Node(values[nums])};

      // handle root node
      if (root == nullptr) {
        root = &temp;
        order.push(root);

        nums += 1;

        // edge case tree is just 1 level
        if (nums >= values.size())
          return root;

        continue;
      }
      // if -1
      if (values[nums] == -1) {
        order.front()->children = tempChildren;
        tempChildren.clear();
        order.pop();
      }
      // handle actual ideal case
      else {
        tempChildren.push_back(&temp);
      }
    }

    return root;
  }

  // print testcase
  void printTree(Node *root) {
    // std::cout << root->val << '\n';
    // std::queue<Node *> printOrder;
    // printOrder.push(root);
    //
    // while (!printOrder.empty()) {
    //   for (int i{0}; i < (printOrder.front()->children.size()); ++i) {
    //     printOrder.push(printOrder.front()->children[i]);
    //   }
    //   std::cout << printOrder.front() << ' ';
    //   printOrder.pop();
    // }
  }

public:
  Node *testA() {
    std::vector<const int> obj{1, -1, 3, 2, 4, -1, 5, 6};

    Node *objTree{tree(obj)};
    printTree(objTree);

    return objTree;
  }
};

class Solution {
public:
  std::vector<int> postorder(Node *root) {
    std::vector<int> result{};

    return result;
  }
};

int main() {
  Test testCur = Test();
  Node *caseA{testCur.testA()};

  return 0;
}
