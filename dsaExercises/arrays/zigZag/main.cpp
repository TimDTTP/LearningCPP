
#include <algorithm>
#include <array>
#include <iostream>

class Solution {
private:
  // Sorting + swap
  std::array<int, 7> sorting(const std::array<int, 7> &arr) {
    std::array<int, 7> temp{arr};

    std::sort(temp.begin(), temp.end());

    // swap every 2
    for (int i{1}; i < arr.size() - 1; i += 2) {
      std::swap(temp[i], temp[i + 1]);
    }

    return temp;
  }

  // Traversal + flag
  std::array<int, 7> traversal(const std::array<int, 7> &arr) {
    std::array<int, 7> temp{arr};
    bool flag{true};

    for (int i{0}; i < temp.size() - 1; ++i) {
      if (flag) {
        if (temp[i] > temp[i + 1])
          std::swap(temp[i], temp[i + 1]);
      }

      else {
        if (temp[i] < temp[i + 1])
          std::swap(temp[i], temp[i + 1]);
      }

      flag = !flag;
    }

    return temp;
  }

public:
  void printArray(const std::array<int, 7> &arr) {
    for (const int i : arr) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;
  }

  void printSolution(const std::array<int, 7> &arr) {
    printArray(sorting(arr));
    printArray(traversal(arr));
  }
};

int main() {
  std::array<int, 7> arr{6, 1, 8, 34, 52, 62, 14};

  Solution cursor = Solution();
  cursor.printSolution(arr);

  return 0;
}
