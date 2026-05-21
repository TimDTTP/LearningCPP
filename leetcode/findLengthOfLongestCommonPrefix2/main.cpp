
#include <cstddef>
#include <iostream>
#include <stack>
#include <vector>

class Test {
public:
  struct TestCase {
    std::vector<int> arr1;
    std::vector<int> arr2;
    int expected;
  };

  TestCase testA() { return {{1, 10, 100}, {1000}, 3}; }
  TestCase testB() { return {{1, 2, 3}, {4, 4, 4}, 0}; }
  std::vector<TestCase> all() { return {testA(), testB()}; };
};

class Tree {
private:
  std::stack<int> split(int val) {
    std::stack<int> buffer{};
    while (val != 0) {
      buffer.push(val % 10);
      val /= 10;
    }
    return buffer;
  }

public:
  int m_val{};
  std::vector<Tree *> m_children{};

  Tree() {
    m_val = -1;
    m_children.resize(10, nullptr);
  }
  Tree(int val) {
    m_val = val;
    m_children.resize(10, nullptr);
  }

  // insert
  void insert(int val) {
    std::stack<int> buffer{split(val)};
    Tree *curr{this};

    while (!buffer.empty()) {
      if (curr->m_children[buffer.top()] == nullptr) {
        curr->m_children[buffer.top()] = new Tree(buffer.top());
      }
      curr = curr->m_children[buffer.top()];
      buffer.pop();
    }
  }

  ~Tree() {
    for (Tree *child : m_children) {
      delete child;
    }
  }
};

class Solution {
public:
  int longestCommonPrefix(std::vector<int> &arr1, std::vector<int> arr2) {
    Tree *stencil = new Tree();
    for (int i : arr2) {
      stencil->insert(i);
    }

    // trace
    int max{0};
    int soFar{};
    std::stack<int> buffer{};
    for (int i : arr1) {
      soFar = 0;
      Tree *curr = stencil;

      while (i != 0) {
        buffer.push(i % 10);
        i /= 10;
      }

      while (!buffer.empty()) {
        if (curr->m_children[buffer.top()] != nullptr) {
          ++soFar;
          curr = curr->m_children[buffer.top()];
        } else {
          break;
        }
        buffer.pop();
      }

      // clear buffer
      while (!buffer.empty()) {
        buffer.pop();
      }

      max = std::max(max, soFar);
    }

    return max;
  }
};

int main() {
  Test tests;
  Solution sol;
  auto cases = tests.all();

  int passed{0};
  for (size_t i{0}; i < cases.size(); ++i) {
    auto &unit = cases[i];
    int result = sol.longestCommonPrefix(unit.arr1, unit.arr2);

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
