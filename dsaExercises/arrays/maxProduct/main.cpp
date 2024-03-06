
#include <algorithm>
#include <array>
#include <iostream>

class Solution {
private:
  // Nested loop approach
  int nestedLoop(std::array<int, 7> arr) {
    int size{arr.size()};
    int maxSoFar{};
    int temp{};

    for (int i{0}; i < size; ++i) {
      temp = arr[i];
      for (int j{i + 1}; j < size; ++j) {
        std::cout << arr[j] << std::endl;
        if (arr[j] == 0)
          break;
        else
          temp *= arr[j];
      }
      maxSoFar = std::max(temp, maxSoFar);
    }

    return maxSoFar;
  }

  // Kadanes algorithm approach
  int kadane(std::array<int, 7> arr) {
    int maxEndingHere{arr[0]};
    int minEndingHere{arr[0]};
    int maxSoFar{arr[0]};

    // loop over array
    for (int i : arr) {
      maxEndingHere = std::max(i, maxEndingHere * i, minEndingHere * i);
      minEndingHere = std::min(i, maxEndingHere * i, minEndingHere * i);
    }

    return maxSoFar;
  }
  // Traversal approach

public:
  // Prints array
  void printArray(const std::array<int, 7> &arr) {
    for (const int i : arr) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;
  }

  // Returns results using all approaches
  void printSolution(const std::array<int, 7> &arr) {
    std::cout << "Approach A)" << nestedLoop(arr) << std::endl;
  }
};

int main() {
  std::array<int, 7> arr{4, 8, -2, 0, 5, -9, -4};

  Solution cursor = Solution();
  cursor.printSolution(arr);

  return 0;
}
