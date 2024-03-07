
#include <iostream>

const int N{5};
const int M{5};

class Solution {
public:
  void recursive(const int arr[][5], int i, int j) {
    if (i == (N - 1) && j == (M - 1)) {
      std::cout << arr[i][j] << std::endl;
      return;
    }

    // print current element
    std::cout << arr[i][j] << ' ';

    // iter through each row
    if (j < M - 1) {
      recursive(arr, i, j + 1);
    }
    // iter through column
    else {
      std::cout << '\n';
      recursive(arr, i + 1, 0);
    }
  }
};

int main() {
  int arr[N][M] = {{1, 2, 3, 4, 5},
                   {6, 7, 8, 9, 10},
                   {11, 12, 13, 14, 15},
                   {16, 17, 18, 19, 20},
                   {21, 22, 23, 24, 25}};

  Solution cursor = Solution();
  cursor.recursive(arr, 0, 0);

  return 0;
}
