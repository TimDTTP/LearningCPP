
#include <iostream>

const int ROW = 5;
const int COL = 5;

class Solution {
private:
  void printArray(int arr[ROW][COL], int i, int j) {
    for (int a{0}; a < i; a++) {
      for (int b{0}; b < j; b++) {
        std::cout << arr[a][b] << ' ';
      }
      std::cout << std::endl;
    }
  }

public:
  void clockwise(int arr[ROW][COL], int i, int j) {
    // track upper limit
    int N{ROW};
    int M{COL};

    // place holder
    int curr{};
    int prev{};

    while (true) {
      int prev{arr[i + 1][j]};

      // iterate over first row
      for (int fr{0}; fr < N; fr++) {
        curr = arr[i][j];
        arr[i][j] = prev;
        prev = curr;
      }

      i++;

      // iterate over last column
      for (int lc{0}; lc < COL; lc++) {
        curr = arr[i][lc];
        arr[i][lc] = prev;
        prev = curr;
      }

      M--;

      // iterate over last row REVERSE
      for (int lr{M - 1}; lr > i; lr--) {
        curr = arr[lr][j];
        arr[lr][j] = prev;
        prev = curr;
      }

      N--;

      // iterate over first column
      for (int fc{j}; fc < M; fc++) {
        curr = arr[fc][j];
        arr[fc][j] = prev;
        prev = curr;
      }
    }

    printArray(arr, ROW, COL);
  }
};

int main() {
  int arr[ROW][COL] = {{1, 2, 3, 4, 5},
                       {6, 7, 8, 9, 10},
                       {11, 12, 13, 14, 15},
                       {16, 17, 18, 19, 20},
                       {21, 22, 23, 24, 25}};

  Solution cursor = Solution();
  cursor.clockwise(arr, 0, 0);

  return 0;
}
