
#include "listnode.h"
#include <iostream>
#include <vector>

class TestCase {
private:
  // convert vector to linked list
  ListNode *vectorToList(std::vector<int> nums) {
    ListNode *head = nullptr;
    ListNode *tail;
    for (int i : nums) {
      ListNode *temp = new ListNode(i);
      if (head == nullptr) {
        head = temp;
        tail = head;
      } else {
        tail->next = temp;
        tail = tail->next;
      }
    }

    return head;
  }

public:
  int m;
  int n;
  ListNode *head;

  TestCase testA() {
    TestCase obj;

    obj.m = 5;
    obj.n = 5;
    int size{obj.m * obj.n};

    std::vector<int> vec;
    vec.reserve(size);
    for (int i{0}; i < size; ++i)
      vec.push_back(i);
    obj.head = vectorToList(vec);

    return obj;
  }

  TestCase testB() {
    TestCase obj;

    obj.m = 3;
    obj.n = 5;
    int size{obj.m * obj.n};

    std::vector<int> vec;
    vec.reserve(size);
    vec = {3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0};
    obj.head = vectorToList(vec);

    return obj;
  }

  TestCase testC() {
    TestCase obj;

    obj.m = 1;
    obj.n = 4;
    int size{obj.m * obj.n};

    std::vector<int> vec;
    vec.reserve(size);
    vec = {0, 1, 2};
    obj.head = vectorToList(vec);

    return obj;
  }

  TestCase testD() {
    TestCase obj;

    obj.m = 10;
    obj.n = 1;
    int size{obj.m * obj.n};

    std::vector<int> vec;
    vec.reserve(size);
    vec = {8, 24, 5, 21, 10, 11, 11, 12, 6, 17};
    obj.head = vectorToList(vec);

    return obj;
  }
};

void printMatrix(std::vector<std::vector<int>> &matrix) {
  std::cout << "printing:\n";
  if (matrix.empty())
    std::cout << "empty" << '\n';

  for (int r{0}; r < matrix.size(); ++r) {
    for (int c{0}; c < matrix[0].size(); ++c) {
      std::cout << matrix[r][c] << ' ';
      if (matrix[r][c] < 10 && matrix[r][c] >= 0)
        std::cout << ' ';
    }
    std::cout << '\n';
  }
  std::cout << std::endl;
}

class Solution {
public:
  std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode *head) {
    std::vector<std::vector<int>> matrix;

    // set matrix size
    matrix.reserve(m);
    for (std::vector<int> i : matrix)
      i.reserve(n);

    // occupy
    for (int row{0}; row < m; ++row) {
      matrix.push_back({});
      for (int col{0}; col < n; ++col) {
        matrix[row].push_back(-1);
      }
    }

    // iterate through list and add to matrix
    std::array<int, 4> const direction{0, 1, 0, -1};
    int dirM{0};
    int dirN{1};
    std::pair<int, int> pos{0, 0};

    // change function lambda
    auto changeDir = [&]() {
      dirM = (dirM + 1) % 4;
      dirN = (dirN + 1) % 4;
    };

    while (head != nullptr) {
      matrix[pos.first][pos.second] = head->val;

      // try next position
      pos.first += direction[dirM];
      pos.second += direction[dirN];

      // if out of bounds of matrix
      if (pos.first >= m || pos.first < 0 || pos.second >= n ||
          pos.second < 0 || matrix[pos.first][pos.second] != -1) {
        // reverse attempt
        pos.first -= direction[dirM];
        pos.second -= direction[dirN];

        changeDir();

        pos.first += direction[dirM];
        pos.second += direction[dirN];
      }

      head = head->next;
    }

    return matrix;
  }
};

int main() {
  TestCase test = TestCase();
  TestCase unit{test.testD()};

  Solution cursor = Solution();
  ListNode *head = unit.head;

  std::vector<std::vector<int>> output{
      cursor.spiralMatrix(unit.m, unit.n, unit.head)};
  printMatrix(output);

  return 0;
}
