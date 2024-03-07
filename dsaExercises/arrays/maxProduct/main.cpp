// NOTE: Reminder to stash changes, could not pull 18:26 03/06/24

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
    for (int i{1}; i < arr.size(); ++i) {
      // place holder to not cause overlap
      int temp{};
      temp = std::max({arr[i], maxEndingHere * arr[i], minEndingHere * arr[i]});
      minEndingHere =
          std::min({arr[i], maxEndingHere * arr[i], minEndingHere * arr[i]});
      maxEndingHere = temp;
      maxSoFar = std::max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
  }

  // Traversal approach
  int traversal(std::array<int, 7> arr) {
    int maxSoFar{arr[0]};
    int product{1};

    // iterate through array forwards
    for (int i{0}; i < arr.size(); ++i) {
      product *= arr[i];
      if (arr[i] == 0)
        product = 1;

      maxSoFar = std::max(product, maxSoFar);
    }

    // reset value of product
    product = 1;

    // iterate through array backwards
    for (int i{arr.size() - 1}; i >= 0; --i) {
      product *= arr[i];
      if (arr[i] == 0)
        product = 1;
      maxSoFar = std::max(product, maxSoFar);
    }

    return maxSoFar;
  }

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
    std::cout << "Approach B)" << kadane(arr) << std::endl;
    std::cout << "Approach C)" << traversal(arr) << std::endl;
  }
};

int main() {
  std::array<int, 7> arr{4, 8, -2, 0, 5, -9, -4};

  Solution cursor = Solution();
  cursor.printSolution(arr);

  return 0;
}
