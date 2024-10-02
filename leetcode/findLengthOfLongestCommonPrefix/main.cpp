
#include <iostream>
#include <vector>

class Test {
public:
  struct Unit {
    std::vector<int> input1;
    std::vector<int> input2;
    int output;
  };

  Unit testA() {
    Unit obj;
    obj.input1 = {1, 10, 100};
    obj.input2 = {1000};
    obj.output = 3;

    return obj;
  }

  Unit testB() {
    Unit obj;
    obj.input1 = {1, 2, 3};
    obj.input2 = {4, 4, 4};
    obj.output = 0;

    return obj;
  }
};

class Solution {
private:
  struct Node {
    int val;
    std::vector<Node *> children;

    Node() { val = 0; }
    Node(int num) { val = num; }
  };

  Node *initTree(std::vector<int> arr) {
    Node *head = new Node();
    head->val = 0;
    Node *tail{head};
    Node *trav{head};
    std::stack<int> digits;

    for (int i : arr) {
      trav = head;
      int temp{i};

      while (i > 0) {
        temp = i % 10;
        digits.push(temp);
        i /= 10;
      }

      // iterate through tree and check
      while (!digits.empty()) {
        // iterate through children and find digit
        for (Node *i : trav->children) {
          if (i->val == digits.top()) {
            tail = i;
            break;
          }
        }

        // if does not exist, add
        if (head == tail) {
          Node *newNode = new Node(digits.top());
          trav->children.push_back(newNode);
          trav = newNode;
        }
        // if does exist skip
        else {
          trav = tail;
        }

        digits.pop();
      }
    }

    return head;
  }

  int lengthOfMatch(Node *const tree, int num) {
    int counter{0};
    Node *trav{tree};
    std::stack<int> digits;
    int temp;
    bool flag{false};

    // get each digits in descending order
    while (num > 0) {
      temp = (num % 10);
      num /= 10;
      digits.push(temp);
    }

    // check against tree, exit early if pre-existing
    while (!digits.empty()) {
      flag = false;

      for (Node *i : trav->children) {
        if (i->val == digits.top()) {
          flag = true;
          ++counter;
          trav = i;
          continue;
        }
      }

      if (!flag)
        return counter;
    }

    return counter;
  }

public:
  void printTree(Node *root) {
    std::queue<Node *> order;
    int up{0};
    int down{1};
    order.push(root);

    while (!order.empty()) {
      for (Node *i : order.front()->children) {
        ++up;
        order.push(i);
      }
      std::cout << order.front()->val << ' ';
      order.pop();
      --down;

      if (down == 0) {
        std::cout << std::endl;
        down = up;
        up = 0;
      }
    }
  }

  int longestCommonPrefix(std::vector<int> &arr1, std::vector<int> &arr2) {
    int maxPrefix;
    // add values of arr2 to tree
    Node *arr2Tree{initTree(arr2)};

    maxPrefix = std::max();

    return maxPrefix;
  }
};

int main() {
  Test testCur = Test();
  Solution solCur = Solution();

  Test::Unit input{testCur.testA()};
  int output{solCur.longestCommonPrefix(input.input1, input.input2)};
  if (output == input.output)
    std::cout << "Success!\n";
  else {
    std::cout << "Failed!\n";
    std::cout << "Expected: " << input.output << '\n';
    std::cout << "Actual: " << output << '\n' << std::endl;
  }

  return 0;
}
