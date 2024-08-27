
#include "treeNode.h"
#include <iostream>
#include <queue>

class Test {
private:
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
      Node *temp{new Node(values[nums])};

      // handle root node
      if (root == nullptr) {
        root = temp;
        order.push(root);

        nums += 1;

        // edge case tree is just 1 level
        if (nums >= values.size())
          return root;

        continue;
      }

      // if -1
      if (values[nums] == -1 || nums == values.size()) {
        order.front()->children = tempChildren;
        order.pop();

        // add children to parent queue
        for (Node *i : tempChildren) {
          order.push(i);
        }

        tempChildren.clear();
      }
      // handle actual ideal case
      else {
        tempChildren.push_back(temp);
      }
    }

    // add last group of children cause no ending NULL
    order.front()->children = tempChildren;

    return root;
  }

  // print testcase
  void printTree(Node *root) {
    std::vector<Node *> parent;
    std::vector<Node *> children;

    parent.push_back(root);

    while (!parent.empty()) {
      for (Node *i : parent.front()->children) {
        children.push_back(i);
      }

      std::cout << parent.front()->val << ' ';
      parent.erase(parent.begin());

      if (parent.empty() && !children.empty()) {
        std::cout << '\n';
        parent = children;
        children.clear();
      }
    }
  }

public:
  Node *testA() {
    std::vector<const int> obj{1, -1, 3, 2, 4, -1, 5, 6};

    Node *objTree{tree(obj)};
    printTree(objTree);

    return objTree;
  }

  Node *testB() {
    std::vector<const int> obj{1, -1, 2,  3,  4,  5,  -1, -1, 6,  7,  -1, 8, -1,
                               9, 10, -1, -1, 11, -1, 12, -1, 13, -1, -1, 14};

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
  Node *caseA{testCur.testB()};

  return 0;
}
